//HSV to and from RGB example sketch//
#include <EasyColor.h>

EasyColor::HSVRGB HSVConverter;

void setup(){
    Serial.begin(9600);
    //do open terminal serial to see output
    delay(2000);
    
    //HSV to RGB conversion. The values and names are just examples.
    rgb out_rgb;
    out_rgb.r = 220;
    out_rgb.g = 180;
    out_rgb.b = 90;

    hsv out_hsv;
    out_hsv.h = 284;
    out_hsv.s = 46;
    out_hsv.v = 60;

    rgb in_rgb;
    in_rgb.r = 200;
    in_rgb.g = 100;
    in_rgb.b = 190;

    hsv in_hsv;
    in_hsv.h = 192.94;
    in_hsv.s = 100;
    in_hsv.v = 255;
    
    Serial.println("RGB");
    out_rgb =  hsvConverter.HSVtoRGB(in_hsv,out_rgb);
    Serial.println(out_rgb.r);
    Serial.println(out_rgb.g);
    Serial.println(out_rgb.b);

    //HSV to RGB convertion
    Serial.println("HVS");
    out_hsv = hsvConverter.RGBtoHSV(in_rgb, out_hsv);
    Serial.println(out_hsv.h);
    Serial.println(out_hsv.s);
    Serial.println(out_hsv.v);
    
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

