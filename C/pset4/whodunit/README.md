# Questions

## What's `stdint.h`?

the library in C language allow programmers to write more portable code by providing a set of typedefs
that specify exact-width integer types, together with the defined minimum and maximum allowable values for each type, using macros

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

data type is basically the same as byte in Arduino. Writers of embedded software often define these types,
because systems can sometimes define int to be 8 bits, 16 bits or 32 bits long.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE is 1 byte
DWORD is 4 bytes
LONG is 4 bytes
WORD is 2 bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

 they must to be set to the signature word BM (0x4D42).

## What's the difference between `bfSize` and `biSize`?

bfSize is The number of bytes required by the structure
bfSize is The size, in bytes, of the bitmap file.

## What does it mean if `biHeight` is negative?

 the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

structure contains information about the dimensions and color format of a device-independent bitmap (DIB).

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

because it can't find the file

## Why is the third argument to `fread` always `1` in our code?

becaue This is the number of elements, each one with a size of size bytes.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

it helps us to change the offset of a pointer.

## What is `SEEK_CUR`?

give the current position in the file.
