/* Nested classes in EasyColor class. Check it.
*/
#include <Arduino.h>
#include <math.h>

extern "C" {
#include <stdlib.h>
#include "esp_system.h"
}

#define HUE_ANGLE 360

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb;

typedef struct {
    double h;
    double s;
    double v;
} hsv;

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
        };
};