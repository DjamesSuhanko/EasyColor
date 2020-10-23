/* Nested classes in EasyColor class. Check it.
Formulas reference: https://www.rapidtables.com/convert/color/
*/
#include <Arduino.h>
#include <math.h>

extern "C" {
#include <stdlib.h>
#include "esp_system.h"
}

#define HUE_ANGLE 360
#define RGB_MAX   255.0
#define ONE_DOT   1.0
#define HUNDRED   100.0

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb;

typedef struct {
    int c;
    int m;
    int y;
    int k;
} cmyk;

typedef struct {
    double h;
    double s;
    double v;
} hsv;

//TODO: check datatype before implement
typedef struct {
    double h;
    double s;
    double l;
} hsl;

class EasyColor{
    public:
        EasyColor();

        class HSVRGB{
            public:
                HSVRGB();

                long map(long x, long in_min, long in_max, long out_min, long out_max);
               
                rgb HSVtoRGB(hsv in, rgb out);
                hsv RGBtoHSV(rgb in, hsv out);
        };

        class CMYKRGB{
            public:
                CMYKRGB();

                rgb CMYKtoRGB(cmyk in, rgb out);
                cmyk RGBtoCMYK(rgb in, cmyk out);
        };

        class HSLRGB{
            public:
                HSLRGB();

                rgb HSLtoRGB(hsl in, rgb out);
                hsl RGBtoHSL(rgb in, hsl out);
        };
};