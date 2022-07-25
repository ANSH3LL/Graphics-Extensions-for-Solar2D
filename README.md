<img src="https://i.imgur.com/rC2qFK5.png" height="100" />

# Graphics Extensions for Solar2D
Extend your graphical might with some of the greatest image formats available

## Rationale
Would you like to support high screen resolutions without bloating up your app/game with duplicate images of varying sizes?

Would you like to play short animations on loop like GIFs or animated stickers?

Would you like to take advantage of the super fast decoding of [QOI](https://qoiformat.org/)?

Is the nanosvg plugin too inaccurate/slow/minimal?

Are the standard image formats supported by Solar2D too antiquated for you?

Fear not, for the solution to your woes is finally at hand.

## Features
- Load and manipulate vector graphics with extensive support for the **SVG1.1** and much of the **SVG2.0** spec
- Load and play animated **WEBP** images
- Load and display images of the **QOI** format
- Load static and scalable images as masking textures
- Modify and re-render scalable graphics in real-time
- Much better SVG support and rendering output than the competition
- Load images from disk or memory
- Supports SVG / SVGZ, WEBP, QOI, PNG & JPEG image formats

## Usage
Refer to example project and API documentation in the `Corona/` directory

## Credits
- [QOI](https://github.com/phoboslab/qoi) by [@phoboslab](https://github.com/phoboslab)
- [resvg](https://github.com/RazrFalcon/resvg) by [@RazrFalcon](https://github.com/RazrFalcon)
- [stb_image](https://github.com/nothings/stb/blob/master/stb_image.h) by [@nothings](https://github.com/nothings)
- [libwebp](https://github.com/webmproject/libwebp) by the [webmproject](https://github.com/webmproject)
- Current logo by <a href="http://cooltext.com" target="_blank"><img src="https://cooltext.com/images/ct_pixel.gif" width="80" height="15" alt="Cool Text: Logo and Graphics Generator" title = "Cool Text: Logo and Graphics Generator" border="0" /></a>

## P/s
- If you love this plugin and are willing to make a logo to spruce up this readme, I will credit you however you like (as long as it's reasonable) above
- If you own a **macOS** device and are comfortable wrangling [Rust](https://www.rust-lang.org/) (to build resvg), I'd appreciate your assistance with building the plugin for **macOS** and **iOS** and will credit you however you like (as long as it's reasonable) above
