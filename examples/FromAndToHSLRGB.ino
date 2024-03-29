//HSL to and from RGB example sketch//
#include <EasyColor.h>

EasyColor::HSLRGB HSLConverter;

void setup(){
    Serial.begin(9600);
    //Open terminal serial to see output
    delay(2000);
    
    rgb in_rgb;
    in_rgb.r = 255;
    in_rgb.g = 0;
    in_rgb.b = 80;
    
    rgb out_rgb;
    out_rgb.r = 0;
    out_rgb.g = 0;
    out_rgb.b = 0;
    
    hsl out_hsl;
    out_hsl.h = 0.0;
    out_hsl.s = 0.0;
    out_hsl.l = 0.0;
    
    hsl in_hsl;
    in_hsl.h = 0.98;
    in_hsl.s = 0.50;
    in_hsl.l = 0.40;
    
    //RGB to HSL conversion
    out_hsl = HSLConverter.RGBtoHSL(in_rgb, out_hsl);
    
    Serial.println("HSL");
    Serial.println(out_hsl.h);
    Serial.println(out_hsl.s);
    Serial.println(out_hsl.l);
    
    //HSL to RGB conversion
    out_rgb = HSLConverter.HSLtoRGB(in_hsl, out_rgb);
    
    Serial.println("RGB");
    Serial.println(out_rgb.r);
    Serial.println(out_rgb.g);
    Serial.println(out_rgb.b);
    
}

void loop(){

}
