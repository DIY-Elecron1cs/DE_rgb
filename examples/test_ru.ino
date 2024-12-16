/*
Автор: DIY electronics (https://github.com/DIY-Elecron1cs)
*/

#include <DE_rgb.h>          //подключаем библиотеку

DE_rgb color(9, 10, 11);     //создаём объект класса DE_rgb

void setup() {
  color.setBrightness(255);  //устанавливаем яркость
  color.setSpeed(5);         //устанавливаем скорость
}

void loop() {
  color.rgb(255, 128, 50);  //красим по трём компонентам RGB
  delay(1000);
  color.hex("#ffcc00");     //красим по HEX-цвету
  delay(1000);
  color.gradient(G, B);     //градиент от зелёного до синего
  delay(1000);
  color.rgb(SPRING);        //пишем цвет по константе (всего их 14)
  delay(1000);
  color.rainbow(R);         //радуга, начиная с красного
  color.off();              //выключаем
  delay(100);
}
