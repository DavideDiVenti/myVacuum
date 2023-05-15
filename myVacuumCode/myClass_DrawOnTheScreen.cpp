#include <Arduino.h>
#include "myClass_DrawOnTheScreen.h"

PixelImage::PixelImage(){}

void PixelImage::create(int w, int h, String image){
  /* Permet de déclarer l'existance d'une première frame
   * Et ce depuis les parametres width, height et image
   */
  this->pixelArray = image;
  this->mywidth = w;
  this->myheight = h;
}

void PixelImage::addFrame(String image){
  /* Permet de déclarer l'existance d'une deuxième ou plus frame
   * Et ce depuis uniquement l'image
   */
  if(this->SerialDebug)Serial.println();
  if(this->SerialDebug)Serial.println("Current frame(s) : " + this->pixelArray);
  if(this->SerialDebug)Serial.println("New frame added  : " + image);
  this->pixelArray = this->pixelArray + image;
}

void PixelImage::drawFrame(int x, int y, int frame, uint16_t color) { 
  /* Permet d'afficher l'image sur l'écran.
   * En y insérant la coordonnée x y, la frame en question, et la couleur, cette fonction affiche l'image.
   * Depuis la chaine String binaire, la fonction affiche l'image pixel par pixel.
   * Là où il y a des 1 se trouve un pixel allumé (COLOR). Là où il y a des 0 se trouve un pixel éteint (BLACK)
   */
  int my_x = x;
  int my_y = y;
  int pixelsQuantity = this->mywidth * this->myheight;
  int pixelStart = frame * pixelsQuantity;
  if(this->SerialDebug)Serial.println();
  if(this->SerialDebug)Serial.println("Matrix frame n°"+String(frame)+" displayed at X = "+String(x)+" Y = " +String(y)+" : " );
  for (int pixel=pixelStart; pixel<pixelStart+pixelsQuantity; pixel++){
    if ((pixel%this->mywidth)==0){
      my_y++;
      my_x = x;
      if(this->SerialDebug)Serial.println();
    }
    if (this->pixelArray[pixel]=='1'){
      _tft->drawPixel(my_x, my_y, color);
    }
    else{
      _tft->drawPixel(my_x, my_y, 0x0000);
    }   
    my_x++;
    if(this->SerialDebug)Serial.print(this->pixelArray[pixel]);
    if(this->SerialDebug)Serial.print(" ");   
    //delay(20);
  }
  if(this->SerialDebug)Serial.println();
} 

void PixelImage::debug(bool is_active){
  /* Permet d'activer le débug en cas de débugging souhaité.
   * Le parametre à False permet de désactiver les affichages des débug au moniteur série.
   */
  this->SerialDebug = is_active;
}
