
#ifndef IMG_FORMAT_H
#define IMG_FORMAT_H

/* RGB/BGR Formats */

#define IMGFMT_RGB_MASK 0xFFFFFF00
#define IMGFMT_RGB (('R'<<24)|('G'<<16)|('B'<<8))
#define IMGFMT_RGB1  (IMGFMT_RGB|1)
#define IMGFMT_RGB4  (IMGFMT_RGB|4)
#define IMGFMT_RGB4_CHAR  (IMGFMT_RGB|4|128) // RGB4 with 1 pixel per byte
#define IMGFMT_RGB8  (IMGFMT_RGB|8)
#define IMGFMT_RGB15 (IMGFMT_RGB|15)
#define IMGFMT_RGB16 (IMGFMT_RGB|16)
#define IMGFMT_RGB24 (IMGFMT_RGB|24)
#define IMGFMT_RGB32 (IMGFMT_RGB|32)

#define IMGFMT_BGR_MASK 0xFFFFFF00
#define IMGFMT_BGR (('B'<<24)|('G'<<16)|('R'<<8))
#define IMGFMT_BGR1 (IMGFMT_BGR|1)
#define IMGFMT_BGR4 (IMGFMT_BGR|4)
#define IMGFMT_BGR4_CHAR (IMGFMT_BGR|4|128) // BGR4 with 1 pixel per byte
#define IMGFMT_BGR8 (IMGFMT_BGR|8)
#define IMGFMT_BGR15 (IMGFMT_BGR|15)
#define IMGFMT_BGR16 (IMGFMT_BGR|16)
#define IMGFMT_BGR24 (IMGFMT_BGR|24)
#define IMGFMT_BGR32 (IMGFMT_BGR|32)

#ifdef WORDS_BIGENDIAN
#define IMGFMT_ABGR IMGFMT_RGB32
#define IMGFMT_BGRA (IMGFMT_RGB32|64)
#define IMGFMT_ARGB IMGFMT_BGR32
#define IMGFMT_RGBA (IMGFMT_BGR32|64)
#else
#define IMGFMT_ABGR (IMGFMT_BGR32|64)
#define IMGFMT_BGRA IMGFMT_BGR32
#define IMGFMT_ARGB (IMGFMT_RGB32|64)
#define IMGFMT_RGBA IMGFMT_RGB32
#endif

/* old names for compatibility */
#define IMGFMT_RG4B  IMGFMT_RGB4_CHAR
#define IMGFMT_BG4B  IMGFMT_BGR4_CHAR

#define IMGFMT_IS_RGB(fmt) (((fmt)&IMGFMT_RGB_MASK)==IMGFMT_RGB)
#define IMGFMT_IS_BGR(fmt) (((fmt)&IMGFMT_BGR_MASK)==IMGFMT_BGR)

#define IMGFMT_RGB_DEPTH(fmt) ((fmt)&0x3F)
#define IMGFMT_BGR_DEPTH(fmt) ((fmt)&0x3F)


/* Planar YUV Formats */

#define IMGFMT_YVU9 0x39555659
#define IMGFMT_IF09 0x39304649
#define IMGFMT_YV12 0x32315659
#define IMGFMT_I420 0x30323449
#define IMGFMT_IYUV 0x56555949
#define IMGFMT_CLPL 0x4C504C43
#define IMGFMT_Y800 0x30303859
#define IMGFMT_Y8   0x20203859
#define IMGFMT_NV12 0x3231564E
#define IMGFMT_NV21 0x3132564E

/* unofficial Planar Formats, FIXME if official 4CC exists */
#define IMGFMT_444P 0x50343434
#define IMGFMT_422P 0x50323234
#define IMGFMT_411P 0x50313134
#define IMGFMT_HM12 0x32314D48

/* Packed YUV Formats */

#define IMGFMT_IUYV 0x56595549
#define IMGFMT_IY41 0x31435949
#define IMGFMT_IYU1 0x31555949
#define IMGFMT_IYU2 0x32555949
#define IMGFMT_UYVY 0x59565955
#define IMGFMT_UYNV 0x564E5955
#define IMGFMT_cyuv 0x76757963
#define IMGFMT_Y422 0x32323459
#define IMGFMT_YUY2 0x32595559
#define IMGFMT_YUNV 0x564E5559
#define IMGFMT_YVYU 0x55595659
#define IMGFMT_Y41P 0x50313459
#define IMGFMT_Y211 0x31313259
#define IMGFMT_Y41T 0x54313459
#define IMGFMT_Y42T 0x54323459
#define IMGFMT_V422 0x32323456
#define IMGFMT_V655 0x35353656
#define IMGFMT_CLJR 0x524A4C43
#define IMGFMT_YUVP 0x50565559
#define IMGFMT_UYVP 0x50565955

/* Compressed Formats */
#define IMGFMT_MPEGPES (('M'<<24)|('P'<<16)|('E'<<8)|('S'))
#define IMGFMT_MJPEG (('M')|('J'<<8)|('P'<<16)|('G'<<24))
/* Formats that are understood by zoran chips, we include
 * non-interlaced, interlaced top-first, interlaced bottom-first */
#define IMGFMT_ZRMJPEGNI  (('Z'<<24)|('R'<<16)|('N'<<8)|('I'))
#define IMGFMT_ZRMJPEGIT (('Z'<<24)|('R'<<16)|('I'<<8)|('T'))
#define IMGFMT_ZRMJPEGIB (('Z'<<24)|('R'<<16)|('I'<<8)|('B'))

// I think that this code could not be used by any other codec/format
#define IMGFMT_XVMC 0x1DC70000
#define IMGFMT_XVMC_MASK 0xFFFF0000
#define IMGFMT_IS_XVMC(fmt) (((fmt)&IMGFMT_XVMC_MASK)==IMGFMT_XVMC)
//these are chroma420
#define IMGFMT_XVMC_MOCO_MPEG2 (IMGFMT_XVMC|0x02)
#define IMGFMT_XVMC_IDCT_MPEG2 (IMGFMT_XVMC|0x82)

typedef struct {
    void* data;
    int size;
    int id;        // stream id. usually 0x1E0
    int timestamp; // pts, 90000 Hz counter based
} vo_mpegpes_t;

const char *vo_format_name(int format);

#endif