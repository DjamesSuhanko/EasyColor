#include "EasyColor.h"
EasyColor::EasyColor()
{

}

EasyColor::HSVRGB::HSVRGB()
{

}

long EasyColor::HSVRGB::map(long x, long in_min, long in_max, long out_min, long out_max)
{
    long divisor = (in_max - in_min);
    if(divisor == 0){
        return -1; //AVR returns -1, SAM returns 0
    }
    return (x - in_min) * (out_max - out_min) / divisor + out_min;
}

rgb EasyColor::HSVRGB::HSVtoRGB(hsv in, rgb out)
{
    if (in.h > 360) in.h -= 360;
    if (in.h < 0)   in.h += 360;

    in.h = constrain(in.h, 0, 360);
    in.s = constrain(in.s, 0, 1);
    in.v = constrain(in.v, 0, 1);

    float c = in.v * in.s;
    float x = c * (1 - fabsf (fmod ((in.h / HUE_ANGLE), 2) - 1));
    float m = in.v - c;
    float rp, gp, bp;
  
    int a = in.h / 60;


    switch (a){
        case 0:
            rp = c;
            gp = x;
            bp = 0;
            break;

        case 1:
            rp = x;
            gp = c;
            bp = 0;
            break;

        case 2:
            rp = 0;
            gp = c;
            bp = x;
            break;

        case 3:
            rp = 0;
            gp = x;
            bp = c;
            break;

        case 4:
            rp = x;
            gp = 0;
            bp = c;
            break;

        default:
            rp = c;
            gp = 0;
            bp = x;
            break;
    }

    out.r = (rp + m) * 255;
    out.g = (gp + m) * 255;
    out.b = (bp + m) * 255;
  
    return out;
}

hsv EasyColor::HSVRGB::RGBtoHSV(rgb in, hsv out)
{
    float max_rgb  = max(max(in.r, in.g), in.b);
    float rgb_min  = min(min(in.r, in.g), in.b);
    float deltaRGB = max_rgb - rgb_min;
  
    if(deltaRGB > 0) {
        if(max_rgb == in.r) {
            out.h = 60 * (fmod(((in.g - in.b) / deltaRGB), 6));
        }
        else if(max_rgb == in.g) {
            out.h = 60 * (((in.b - in.r) / deltaRGB) + 2);
        }
        else if(max_rgb == in.b) {
            out.h = 60 * (((in.r - in.g) / deltaRGB) + 4);
        }
    
        if(max_rgb > 0) {
            out.s = (deltaRGB / max_rgb) * 100;
        }
        else {
            out.s = 0;
        }
    
        out.v = map(max_rgb,0,255,0,100);
        }
        else {
            out.h = 0;
            out.s = 0;
            out.v = map(max_rgb,0,255,0,100);
    }
  
    if(out.h < 0) {
        out.h = 360 + out.h;
    }
    return out;
}

rgb EasyColor::CMYKRGB::CMYKtoRGB(cmyk in, rgb out)
{
    /*
    A reversa também é simples e será utilizada para manipular o CMYK direto no display.
    O RGB é inteiro, mas o CMYK precisa ser passado de 0 à 1 novamente. No artigo tem uma
    imagem de exemplo do cálculo na calculadora, mas segue um exemplo:
    C = 43
    M = 30
    Y = 10
    K = 10
    R = 255 * (1-(43/100))*(1-(10/100)) = 130,815 ; arredondar para cima quando > 0.5
    ==================================
    The R,G,B values are given in the range of 0..255.
    The red (R) color is calculated from the cyan (C) and black (K) colors:
    R = 255 × (1-C) × (1-K)
    The green color (G) is calculated from the magenta (M) and black (K) colors:
    G = 255 × (1-M) × (1-K)
    The blue color (B) is calculated from the yellow (Y) and black (K) colors:
    B = 255 × (1-Y) × (1-K)
    */
    //uint8_t exemplo = round(255.0 * (1.0-((float)43/100.0))*(1.0-((float)10/100.0)));
    out.r = round(RGB_MAX * (ONE_DOT-((float)in.c/HUNDRED)) * (ONE_DOT-((float)in.k/HUNDRED)));
    out.g = round(RGB_MAX * (ONE_DOT-((float)in.m/HUNDRED)) * (ONE_DOT-((float)in.k/HUNDRED)));
    out.b = round(RGB_MAX * (ONE_DOT-((float)in.y/HUNDRED)) * (ONE_DOT-((float)in.k/HUNDRED)));

    return out;
}

cmyk EasyColor::CMYKRGB::RGBtoCMYK(rgb in, cmyk out)
{
    float Rfrac = (float)in.r/(float)255;
    float Gfrac = (float)in.g/(float)255;
    float Bfrac = (float)in.b/(float)255;

    float K = 1-max({Rfrac,Gfrac,Bfrac});

    float C = (1-Rfrac-K)/(1-K);
    float M = (1-Gfrac-K)/(1-K);
    float Y = (1-Bfrac-K)/(1-K);

    out.c = C*100;
    out.m = M*100;
    out.y = Y*100;
    out.k = K*100;

    return out;
}