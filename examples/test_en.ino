/*
Author: DIY electronics (https://github.com/DIY-Elecron1cs)
*/

#include <DE_rgb.h>          //attached the library

DE_rgb color(9, 10, 11);     //creating an object

void setup() {
  color.setBrightness(255);  //setting the brightness
  color.setSpeed(5);         //setting the speed
}

void loop() {
  color.rgb(255, 128, 50);  //we paint using three RGB components
  delay(1000);
  color.hex("#ffcc00");     //we paint according to the HEX color
  delay(1000);
  color.gradient(G, B);     //gradient from green to blue
  delay(1000);
  color.rgb(SPRING);        //we write the color according to the constant (there are 14 of them in total)
  delay(1000);
  color.rainbow(R);         //A rainbow starting from red
  color.off();              //turning it off
  delay(100);
}
