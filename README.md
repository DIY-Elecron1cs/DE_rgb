# DE_rgb
библиотека для работы с RGB светодиодами
## подключение
```cpp
#include <DE_rgb.h>
```
## объявление объекта/ов
```cpp
DE_rgb color(redPin, greenPin, bluePin);
```
## функции
```cpp
  setBrightness(uint8_t);  //настройка яркости (0...255)
  setSpeed(uint8_t);       //скорость для градиента (0...255)

  rgb(uint8_t, uint8_t, uint8_t);  //красим по трём компонентам RGB
  hex(String);                     //красим по HEX-цвету
  color.gradient(color1, color2);  //градиент от одного цвета до другого
  rainbow(mode);                   //радуга, начиная с цвета (R, G, B);
```
## константы
```cpp
RED
ORANGE
YELLOW
CHARTREUSE
GREEN
SPRING
CYAN
AZURE
BLUE 
VIOLET
MAGENTA
ROSE
WHITE
BLACK

R
G
B
```
## пример
```cpp
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
```
