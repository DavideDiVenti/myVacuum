#include <Arduino.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>

class PixelImage {
    private:
        Adafruit_ST7735 *_tft;  //je vais devoir faire appel à l'obet tft que je créerai dans le main
        unsigned char bgColor;
        unsigned char fgColor;
        String pixelArray;
        int mywidth;
        int myheight;    
        bool SerialDebug;
        
    public:
        PixelImage(Adafruit_ST7735 &tft) : _tft(&tft) {} 
        void create(int w, int h, String image);
        void addFrame(String image);
        void drawFrame(int x, int y, int frame, uint16_t color);   
        void debug(bool is_active);
        
        //Constructeur      
        PixelImage();
};
