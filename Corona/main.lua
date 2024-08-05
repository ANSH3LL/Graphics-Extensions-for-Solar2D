local gfxe = require('plugin.gfxe')
local asset_reader = require('plugin.AssetReader')

local font
local platform = system.getInfo('platform')

if platform == 'android' then
    font = asset_reader.Read('fonts/Inconsolata-Regular.ttf')
else
    local file = io.open(system.pathForFile('fonts/Inconsolata-Regular.ttf'), 'rb')
    font = file:read('*a')
    file:close()
end

-------------------------------------------------------------------

local svg1 = gfxe.newScalableImage(
    {
        filename = 'images/h350.svg'
    },
    {
        fontData = font,
        fontFamily = 'Inconsolata'
    }
)
svg1.x, svg1.y = display.contentCenterX, display.contentCenterY

-------------------------------------------------------------------

local sizing = gfxe.newSizing()

sizing.zoom = 2
sizing.crop = gfxe.CROP_TO_BBOX

local svg2 = gfxe.newScalableImage(
    {
        filename = 'images/svg_logo.svg'
    }
)

timer.performWithDelay(2000,
    function()
        svg2:modify(
            {
                sizing = sizing:raw()
            }
        )
    end
)

svg2.x, svg2.y = display.contentCenterX, display.contentCenterY

-------------------------------------------------------------------

local qoi = gfxe.newStaticImage(
    {
        filename = 'images/qoi_logo.qoi',
        width = 224, height = 110
    }
)
qoi.x, qoi.y = 115, 58

-------------------------------------------------------------------

local webp1 = gfxe.newStaticImage(
    {
        filename = 'images/compass.webp',
    }
)
webp1.x, webp1.y = 847, 153

-------------------------------------------------------------------

local webp2 = gfxe.newAnimatedImage(
    {
        filename = 'images/banana.webp',
        width = 200, height = 200,
        loop = true
    }
)
webp2.x, webp2.y = 103, 497
webp2:play()

-------------------------------------------------------------------

webp3 = gfxe.newAnimatedImage(
    {
        filename = 'images/animated.webp',
        width = 200, height = 200
    }
)
webp3.x, webp3.y = 897, 497
webp3:play()
