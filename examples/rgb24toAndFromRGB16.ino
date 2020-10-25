//RGB888 to and from RGB565
#include <EasyColor.h>

//Convert RGB24 to and from RGB16
EasyColor rgb2rgb;

void setup(){
    Serial.begin(9600);
    //open terminal serial to see output
    delay(2000);
    
    uint16_t rgb_565_test = rgb2rgb.RGB24toRGB16(0x80,0x80,0x00);
    Serial.println(rgb_565_test,HEX);

    rgb rgb_888_test = rgb2rgb.RGB16toRGB24(0x8400);
    Serial.println(rgb_888_test.r);
    Serial.println(rgb_888_test.g);
    Serial.println(rgb_888_test.b);
}

void loop(){
    
}
