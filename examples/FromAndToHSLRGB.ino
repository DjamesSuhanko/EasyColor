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
    
    //RGB24 to CMYK. If needs convertion from RGB16, take a look below
    out_hsl = CMYKConverter.RGBtoHSL(in_rgb, out_hsl);
    
    Serial.println("HSL");
    Serial.println(out_hsl.h);
    Serial.println(out_hsl.s);
    Serial.println(out_hsl.l);
    
    //CMYK to RGB color to show in a display like ILI9341.
    //In this case, needs convertion to RGB16. Take a look below
    out_rgb = CMYKConverter.HSLtoRGB(in_hsl, out_rgb);
    
    Serial.println("RGB");
    Serial.println(out_rgb.r);
    Serial.println(out_rgb.g);
    Serial.println(out_rgb.b);
    
    //Olive color from RGB24 to RGB16
    Serial.println(" ");
    Serial.println("RGB24 to and from RGB16");
    uint16_t rgb16_result = hsvConverter.RGB24toRGB16(0x80,0x80,0x00);
    Serial.println(rgb16_result,HEX);

    //Olive color from RGB16 to RGB24
    rgb rgb24_result = hsvConverter.RGB16toRGB24(rgb16_result);
    Serial.println(rgb24_result.r);
    Serial.println(rgb24_result.g);
    Serial.println(rgb24_result.b);
}

void loop(){

}
