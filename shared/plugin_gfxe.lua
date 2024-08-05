local Library = require('CoronaLibrary')

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
        zoom = 0, crop = 0
    }
    --
    function sizing:raw()
        return {
            self.zoom, self.crop
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
    function transform:raw()
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
    function render:raw()
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
    local data, path
    local fmt = opts.format or 'rgba'
    --
    if opts.data then
        data = opts.data
    elseif opts.filepath then
        path = opts.filepath
    elseif opts.filename then
        path = system.pathForFile(opts.filename, opts.baseDir)
    end
    --
    if data then
        return lib._newStaticTexture(true, fmt, data)
    elseif path then
        return lib._newStaticTexture(false, fmt, path)
    end
end

function lib.newAnimatedTexture(opts)
    local data, path
    local loop = opts.loop or false
    --
    if opts.data then
        data = opts.data
    elseif opts.filepath then
        path = opts.filepath
    elseif opts.filename then
        path = system.pathForFile(opts.filename, opts.baseDir)
    end
    --
    if data then
        return lib._newAnimatedTexture(true, loop, data)
    elseif path then
        return lib._newAnimatedTexture(false, loop, path)
    end
end

function lib.newScalableTexture(opts, conf)
    local data, path
    local fmt = opts.format or 'rgba'
    --
    if opts.data then
        data = opts.data
    elseif opts.filepath then
        path = opts.filepath
    elseif opts.filename then
        path = system.pathForFile(opts.filename, opts.baseDir)
    end
    --
    if data then
        return lib._newScalableTexture(true, fmt, data, conf)
    elseif path then
        return lib._newScalableTexture(false, fmt, path, conf)
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
    rect.texture = texture
    --
    rect._time = 0
    rect._complete = false
    rect.isPlaying = false
    --
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
            rect._complete = true
            rect:pause()
            --
            if rect.listener then
                rect.listener()
            end
        end
    end
    --
    function rect:play()
        if self._complete then return end
        if self.isPlaying then return end
        --
        self.isPlaying = true
        self._time = system.getTimer()
        --
        if self._loop then
            Runtime:addEventListener('enterFrame', self.update)
        else
            Runtime:addEventListener('enterFrame', self._update)
        end
    end
    --
    function rect:pause()
        if not self.isPlaying then return end
        self.isPlaying = false
        --
        if self._loop then
            Runtime:removeEventListener('enterFrame', self.update)
        else
            Runtime:removeEventListener('enterFrame', self._update)
        end
    end
    --
    function rect:reset(loop)
        if self.isPlaying then return end
        self._complete = false
        --
        self._time = 0
        self._loop = loop or false
        --
        self.texture:reset(self._loop)
        self.texture:invalidate()
    end
    --
    function rect:finalize(event)
        self.texture:releaseSelf()
    end
    --
    rect:addEventListener('finalize')
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
    rect.texture = texture
    --
    function rect:modify(conf)
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
    function rect:finalize(event)
        self.texture:releaseSelf()
    end
    --
    rect:addEventListener('finalize')
    return rect
end

-- Return an instance
return lib
