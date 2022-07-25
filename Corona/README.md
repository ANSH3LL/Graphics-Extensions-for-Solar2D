# Graphics Extensions for Solar2D
An extension to Solar2D's supported image formats. Provides full decoding support for **SVG**, **WEBP** & **QOI**. Also includes support for **PNG** & **JPEG**.

## API Documentation
### Gotcha
- Creating a static texture from `.png` or `.jpg` images on android requires you either change the file extension or load the image contents using the [AssetReader plugin](http://ggcrunchy.github.io/corona-plugin-docs/DOCS/AssetReader/api.html).
- This is a result of the restrictions explained [here](https://docs.coronalabs.com/api/library/system/pathForFile.html#android-file-restrictions).
- This also applies for `.ttf` font files that can be used when creating scalable textures containing text. Refer to `/main.lua` for an example on how to do this.
- If you intend to use any of the textures provided by this library in a DIY fashion, make sure to take a look at how they are used in the library's source code [starting here](https://github.com/ANSH3LL/Graphics-Extensions-for-Solar2D/blob/master/shared/plugin_gfxe.lua#L151) so as to avoid any nasty surprises.

### StaticTexture
Use this to load static images. Supports **WEBP** (no animation), **QOI**, **JPEG** and **PNG**.

#### Parameters
- `format` *Optional* - the texture format to create. Can be `rgba`, `rgb` or `mask`. Defaults to `rgba`
- `filename` *Optional* - the name of the image to load
- `baseDir` *Optional* - the base directory where `filename` is located
- `filepath` *Optional* - an absolute path to the image file. Substitutes `filename` and `baseDir`
- `data` *Optional* - a lua string containing the image data. Substitutes `filepath`, `filename` and `baseDir`

#### Example
```lua
local gfxe = require('plugin.gfxe')

local texture = gfxe.newStaticTexture(
    {
        filename = 'images/compass.webp'
    }
)

if texture then
    local image = display.newImageRect(texture.filename, texture.baseDir, texture.width, texture.height)
    texture:releaseSelf()
else
    print('Error creating texture')
end
```


### ScalableTexture
Use this to load vector images. Supports **SVG** and **SVGZ** (more info [here](https://github.com/RazrFalcon/resvg#readme)).

#### Parameters
- `format` *Optional* - the texture format to create. Can be `rgba`, `rgb` or `mask`. Defaults to `rgba`
- `filename` *Optional* - the name of the image to load
- `baseDir` *Optional* - the base directory where `filename` is located
- `filepath` *Optional* - an absolute path to the image file. Substitutes `filename` and `baseDir`
- `data` *Optional* - a lua string containing the image data. Substitutes `filepath`, `filename` and `baseDir`

#### Configuration
**All fields are optional**
- `sizing` *Optional* - a table containing size info. Use with `gfxe.newSizing` for convenience
- `transform` *Optional* - a table containing a transform matrix. Use with `gfxe.newTransform` for convenience
- `render` *Optional* - a table containing render output configuration. Use with `gfxe.newRender` for convenience
- `resourceDir` *Optional* - an absolute path to a directory containing resources (such as linked images) used by the SVG image
- `languages` *Optional* - a comma-separated list of languages (such as `"en,en-US"`) used to resolve the `systemLanguage` conditional attribute
- `fontFamily` *Optional* - the default font family to use when rendering text
- `fontSize` *Optional* - the default font size to use when rendering text
- `fontData` *Optional* - a lua string containing truetype font data
- `systemFonts` *Optional* - a boolean describing whether or not to load fonts present on your computer. Defaults to `false`. **This is a very I/O intensive parameter and is unlikely to work on mobile devices**

#### Extra configuration
**The following will only have an effect when used in the `modify()` method. All fields are optional**
- `nodeID` *Optional* - the string ID of a node that should be rendered instead of the whole vector image
- `svgData` *Optional* - a lua string containing SVG or SVGZ image data that should be rendered to replace the prior vector image

#### Methods
- `modify(config)` - used to modify and re-render the loaded vector image. `config` is a table. Can be called without arguments to reset the rendered image to its original form. The `systemFonts` field will be ignored. Refer to the `configuration` and `extra configuration` options above.

#### Example
```lua
local gfxe = require('plugin.gfxe')

local sz = gfxe.newSizing()
sz.crop = gfxe.CROP_TO_BBOX

local texture = gfxe.newScalableTexture(
    {
        filename = 'images/svg_logo.svg'
    },
    {
        sizing = sz:raw()
    }
)

if texture then
    local image = display.newImageRect(texture.filename, texture.baseDir, texture.width, texture.height)
    texture:releaseSelf()
else
    print('Error creating texture')
end
```

#### Gotcha
When setting `sizing`, `transform` or `render` parameters in the configuration table, make sure to use the `raw()` method as illustrated below:

```lua
local s = gfxe.newSizing()
-- set sizing properties

local t = gfxe.newTransform()
-- set transform properties

local r = gfxe.newRender()
-- set render properties

local config = {
    sizing = s:raw(),
    transform = t:raw(),
    render = r:raw()
}

local texture = gfxe.newScalableTexture(params, config)
```

#### Sizing
Use this to set parameters on how to calculate the output size of the vector image.

##### Properties
- `width` *Optional* - the required output width
- `height` *Optional* - the required output height
- `aspect` *Optional* - how to resize the vector image
- `zoom` *Optional* - the scale factor to apply when `aspect` is `gfxe.ZOOM_BY_RATIO`
- `crop` *Optional* - how to crop the rendered image

##### Aspect types
- `gfxe.ORIGINAL_SIZE` - renders the vector image in its original size
- `gfxe.PRESERVE_WIDTH` - ensures the rendered image fits the `width` given
- `gfxe.PRESERVE_HEIGHT` - ensures the rendered image fits the `height` given
- `gfxe.ZOOM_BY_RATIO` - scales the rendered image up or down depending on `zoom`. `zoom` must be larger than 0

##### Cropping types
- `gfxe.NO_CROPPING` - no cropping of the rendered image
- `gfxe.CROP_TO_BBOX` - crops the rendered image to the vector image's bounding box and eliminates padding. Might be overzealous in some cases

#### Transform
Use this to set parameters on how to skew, scale and translate the rendered image. Values must be larger than 0.

##### Properties
- `skewX` - skew on the x-axis
- `skewY` - skew on the y-axis
- `scaleX`- scaling on the x-axis
- `scaleY`- scaling on the y-axis
- `translateX`- translate on the x-axis
- `translateY`- translate on the y-axis

#### Render
Use this to set parameters on how to render the vector image.

##### Properties
- `dpi` - the target dots-per-inch to use when rendering the vector image (impacts unit conversion to px)
- `shape` - the default shape rendering method
- `text` - the default text rendering method
- `image` - the default image rendering method

##### Shape rendering methods
- `gfxe.SHAPE_PREFER_SPEED`
- `gfxe.SHAPE_CRISP_EDGES`
- `gfxe.SHAPE_PRECISE_GEOMETRY` *Default*

##### Text rendering methods
- `gfxe.TEXT_PREFER_SPEED`
- `gfxe.TEXT_PREFER_LEGIBILITY` *Default*
- `gfxe.TEXT_PRECISE_GEOMETRY`

##### Image rendering methods
- `gfxe.IMAGE_PREFER_QUALITY` *Default*
- `gfxe.IMAGE_PREFER_SPEED`


### AnimatedTexture
Use this to load and play animated images. Supports animated **WEBP**.

#### Parameters
- `loop` *Optional* - a boolean describing whether or not to loop the animation indefinitely. Defaults to `false` (plays once and stops. Must be reset in order to be replayed).
- `filename` *Optional* - the name of the image to load
- `baseDir` *Optional* - the base directory where `filename` is located
- `filepath` *Optional* - an absolute path to the image file. Substitutes `filename` and `baseDir`
- `data` *Optional* - a lua string containing the image data. Substitutes `filepath`, `filename` and `baseDir`

#### Methods
- `update(delta)` - load the next frame of the animation. `delta` should be the time between now and the last call to this method in milliseconds
- `reset(loop)` - go back to the first frame of the animation so it can be replayed. Also resets the `completed` property. If `loop` is set to `true`, the animation will play on loop once restarted

#### Properties
**Read-only**
- `frameCount` - how many frames the animation has
- `completed` - `true` when the animation has played to its last frame and looping was disabled

#### Example
```lua
local gfxe = require('plugin.gfxe')

local texture = gfxe.newAnimatedTexture(
    {
        filename = 'images/animated.webp'
    }
)

if texture then
    local image = display.newImageRect(texture.filename, texture.baseDir, texture.width, texture.height)
    -- Go to the next frame if it appears within 100ms after the first
    texture:update(100)
    texture:invalidate()
    -- Release the texture
    texture:releaseSelf()
else
    print('Error creating texture')
end
```


### StaticImage
Use this to display static images. Supports **WEBP** (no animation), **QOI**, **JPEG** and **PNG**. This is actually an `ImageRect`.

#### Parameters
Same as those accepted by a `StaticTexture`

#### Example
```lua
local gfxe = require('plugin.gfxe')

local image = gfxe.newStaticImage(
    {
        filename = 'images/qoi_logo.qoi'
    }
)
```


### ScalableImage
Use this to display and modify vector images. Supports **SVG** and **SVGZ**. This is actually an `ImageRect`.

#### Parameters
Same as those accepted by a `ScalableTexture`

#### Configuration
- Same as that accepted by a `ScalableTexture`

#### Methods
Same as those present in a `ScalableTexture`

#### Example
```lua
local gfxe = require('plugin.gfxe')

local image = gfxe.newScalableImage(
    {
        filename = 'images/svg_logo.svg'
    }
)
```


### AnimatedImage
Use this to play animated images. Supports animated **WEBP**. This is actually an `ImageRect`.

#### Parameters
Same as those accepted by an `AnimatedTexture` in addition to:
- `listener` - a function that will be called when playback of a non-looped animation has been completed
- `cleanup` - if set to `true`, will auto-remove the `ImageRect` when playback of a non-looped animation has been completed

#### Methods
- `play()` - playback the loaded animation
- `pause()` - pause playback
- `reset(loop)` - reset a paused or completed animation so it can be replayed from the first frame. If `loop` is set to `true`, the animation will play on loop once `play()` is called. Otherwise, looping will be disabled until `reset()` is called once more even though it was previously enabled.
- `stop(dispose)` - stop playback. If `dispose` is set to `true`, the `ImageRect` will be removed. Once this method is called, it becomes impossible to reset or continue playing the animation

#### Properties
**Read-only**
Same as those present in an `AnimatedTexture`. Does not expose the `completed` property

#### Example
```lua
local gfxe = require('plugin.gfxe')

local image = gfxe.newAnimatedImage(
    {
        filename = 'images/banana.webp',
        loop = true
    }
)

if image then
    image:play()
end
```