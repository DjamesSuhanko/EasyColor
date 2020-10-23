//RGB888 to and from RGB565
#include <EasyColor.h>

//You can make any choice to instantiate a class:
//HSLRGB, CMYKRGB, HSVRGB
EasyColor::HSLRGB HSLConverter;

void setup(){
    Serial.begin(9600);
    //open terminal serial to see output
    delay(2000);
    
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
