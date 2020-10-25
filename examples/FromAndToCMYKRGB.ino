//CMYK to and from RGB example sketch//
#include <EasyColor.h>

EasyColor::CMYKRGB CMYKConverter;

void setup(){
    Serial.begin(9600);
    //Open terminal serial to see output
    delay(2000);
    
    cmyk out_cmyk;
    out_cmyk.c = 0;
    out_cmyk.m = 0;
    out_cmyk.y = 0;
    out_cmyk.k = 0;
    
    rgb in_rgb;
    in_rgb.r = 255;
    in_rgb.g = 0;
    in_rgb.b = 80;
    
    cmyk in_cmyk;
    in_cmyk.c = 90;
    in_cmyk.m = 0;
    in_cmyk.y = 70;
    in_cmyk.k = 0;
    
    rgb out_rgb;
    out_rgb.r = 0;
    out_rgb.g = 0;
    out_rgb.b = 0;
    
    //RGB24 to CMYK. If needs convertion from RGB16, take a look below
    out_cmyk = CMYKConverter.RGBtoCMYK(in_rgb, out_cmyk);
    
    Serial.println("CMYK");
    Serial.println(out_cmyk.c);
    Serial.println(out_cmyk.m);
    Serial.println(out_cmyk.y);
    Serial.println(out_cmyk.k);
    
    //CMYK to RGB color to show in a display like ILI9341.
    //In this case, needs convertion to RGB16. Take a look below
    out_rgb = CMYKConverter.CMYKtoRGB(in_cmyk, out_rgb);
    
    Serial.println("RGB");
    Serial.println(out_rgb.r);
    Serial.println(out_rgb.g);
    Serial.println(out_rgb.b);
    
}

void loop(){

}
