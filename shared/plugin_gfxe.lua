local Library = require('CoronaLibrary')

local function readFile(path)
    if not path then return end
    --
    local file = io.open(path, 'rb')
    if not file then return end
    --
    local contents = file:read('*a')
    io.close(file)
    --
    return contents
end

-- Create stub library
local lib = Library:new(
    {
        name = 'plugin.gfxe',
        publisherId = 'com.ansh3ll'
    }
)

-- Cropping types
lib.NO_CROPPING = 0
lib.CROP_TO_BBOX = 1

-- Aspect types
lib.ORIGINAL_SIZE = 0
lib.PRESERVE_WIDTH = 1
lib.PRESERVE_HEIGHT = 2
lib.ZOOM_BY_RATIO = 3

-- Shape rendering methods
lib.SHAPE_PREFER_SPEED = 0
lib.SHAPE_CRISP_EDGES = 1
lib.SHAPE_PRECISE_GEOMETRY = 2

-- Text rendering methods
lib.TEXT_PREFER_SPEED = 0
lib.TEXT_PREFER_LEGIBILITY = 1
lib.TEXT_PRECISE_GEOMETRY = 2

-- Image rendering methods
lib.IMAGE_PREFER_QUALITY = 0
lib.IMAGE_PREFER_SPEED = 1

function lib.newSizing()
    local sizing = {
        width = 0, height = 0,
        aspect = 0, zoom = 1, crop = 0
    }
    --
    sizing.raw = function(self)
        return {
            self.width, self.height,
            self.aspect, self.zoom, self.crop
        }
    end
    --
    return sizing
end

function lib.newTransform()
    local transform = {
        skewX = 0, skewY = 0,
        scaleX = 1, scaleY = 1,
        translateX = 0, translateY = 0
    }
    --
    transform.raw = function(self)
        return {
            self.scaleX, self.skewY, self.skewX,
            self.scaleY, self.translateX, self.translateY
        }
    end
    --
    return transform
end

function lib.newRender()
    local render = {
        dpi = 96, shape = 2,
        text = 1, image = 0
    }
    --
    render.raw = function(self)
        return {
            self.dpi, self.shape,
            self.text, self.image
        }
    end
    --
    return render
end

---------------------------------------------------------------------------

function lib.newStaticTexture(opts)
    local data
    local fmt = opts.format or 'rgba'
    --
    if opts.data then
        data = opts.data
    elseif opts.filepath then
        data = readFile(opts.filepath)
    elseif opts.filename then
        data = readFile(system.pathForFile(opts.filename, opts.baseDir))
    end
    --
    if data then
        return lib._newStaticTexture(fmt, data)
    end
end

function lib.newAnimatedTexture(opts)
    local data
    local loop = opts.loop or false
    --
    if opts.data then
        data = opts.data
    elseif opts.filepath then
        data = readFile(opts.filepath)
    elseif opts.filename then
        data = readFile(system.pathForFile(opts.filename, opts.baseDir))
    end
    --
    if data then
        return lib._newAnimatedTexture(loop, data)
    end
end

function lib.newScalableTexture(opts, conf)
    local data
    local fmt = opts.format or 'rgba'
    --
    if opts.data then
        data = opts.data
    elseif opts.filepath then
        data = readFile(opts.filepath)
    elseif opts.filename then
        data = readFile(system.pathForFile(opts.filename, opts.baseDir))
    end
    --
    if data then
        return lib._newScalableTexture(fmt, data, conf)
    end
end

---------------------------------------------------------------------------

function lib.newStaticImage(opts)
    local texture = lib.newStaticTexture(opts)
    if not texture then return end
    --
    local width = opts.width or texture.width
    local height = opts.height or texture.height
    --
    local rect = display.newImageRect(texture.filename, texture.baseDir, width, height)
    rect.trait = texture.trait
    texture:releaseSelf()
    --
    return rect
end

function lib.newAnimatedImage(opts)
    local texture = lib.newAnimatedTexture(opts)
    if not texture then return end
    --
    local width = opts.width or texture.width
    local height = opts.height or texture.height
    --
    local rect = display.newImageRect(texture.filename, texture.baseDir, width, height)
    rect.frameCount = texture.frameCount
    --
    rect.trait = texture.trait
    rect.texture = texture
    --
    rect._time = 0
    rect._playing = false
    rect._complete = false
    --
    rect.cleanup = opts.cleanup
    rect.listener = opts.listener
    rect._loop = opts.loop or false
    --
    rect.update = function(event)
        rect.texture:update(event.time - rect._time)
        rect.texture:invalidate()
        --
        rect._time = event.time
    end
    --
    rect._update = function(event)
        rect.update(event)
        --
        if rect.texture.completed then
            rect:stop(rect.cleanup)
            --
            if rect.listener then
                rect.listener()
            end
        end
    end
    --
    rect.play = function(self)
        if self._complete then return end
        if self._playing then return end
        --
        self._playing = true
        self._time = system.getTimer()
        --
        if self._loop then
            Runtime:addEventListener('enterFrame', self.update)
        else
            Runtime:addEventListener('enterFrame', self._update)
        end
    end
    --
    rect.pause = function(self)
        if not self._playing then return end
        self._playing = false
        --
        if self._loop then
            Runtime:removeEventListener('enterFrame', self.update)
        else
            Runtime:removeEventListener('enterFrame', self._update)
        end
    end
    --
    rect.stop = function(self, dispose)
        if self._complete then return end
        --
        self._complete = true
        self:pause()
        --
        self.texture:releaseSelf()
        --
        if dispose then
            timer.performWithDelay(1,
                function()
                    self.texture = nil
                    self:removeSelf()
                end
            )
        end
    end
    --
    return rect
end

function lib.newScalableImage(opts, conf)
    local texture = lib.newScalableTexture(opts, conf)
    if not texture then return end
    --
    local width = opts.width or texture.width
    local height = opts.height or texture.height
    --
    local rect = display.newImageRect(texture.filename, texture.baseDir, width, height)
    rect.trait = texture.trait
    rect.texture = texture
    --
    rect._disposed = false
    rect._dispose = rect.removeSelf
    --
    rect.modify = function(self, conf)
        if self._disposed then return end
        --
        if self.texture:modify(conf) then
            self.texture:invalidate()
            --
            self.width = self.texture.width
            self.height = self.texture.height
            --
            return true
        end
        --
        return false
    end
    --
    rect.removeSelf = function(self)
        self._disposed = true
        self.texture:releaseSelf()
        --
        timer.performWithDelay(1,
            function()
                self.texture = nil
                self:_dispose()
            end
        )
    end
    --
    return rect
end

-- Return an instance
return lib
