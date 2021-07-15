# img2ascii

Image to ASCII converter written in C++.  

Note that you may have to resize your terminal font for most images. This can be done on some terminals with `ctrl -` and undone with `ctrl +`  

## Usage

`make`  
`./img2ascii [/path/to/image]`  

Optional - output to file:  
`./img2ascii [/path/to/image] > [/path/to/output]`  

## Dependencies

Uses `stb_image.h` from [stb](https://github.com/nothings/stb)
