#pragma once

#define RED 255, 0, 0
#define ORANGE 255, 128, 0
#define YELLOW 255, 255, 0
#define CHARTREUSE 128, 255, 0
#define GREEN 0, 255, 0
#define SPRING 0, 255, 128
#define CYAN 0, 255, 255
#define AZURE 0, 128, 255
#define BLUE 0, 0, 255
#define VIOLET 128, 0, 255
#define MAGENTA 255, 0, 255
#define ROSE 255, 0, 128
#define WHITE 255, 255, 255
#define BLACK 0, 0, 0

#define R 0
#define G 1
#define B 2

class DE_rgb {
  public:
    DE_rgb(uint8_t redPin, uint8_t greenPin, uint8_t bluePin) {
      _redPin = redPin;
      _greenPin = greenPin;
      _bluePin = bluePin;
      pinMode(_redPin, OUTPUT);
      pinMode(_greenPin, OUTPUT);
      pinMode(_bluePin, OUTPUT);
    }

    void setBrightness(float bright) {
      //конвертируем диапазон от 0 до 255 в диапазон от 0.0 до 1.0
      _k = bright / 255.0;
    }

    void rgb(uint8_t redValue, uint8_t greenValue, uint8_t blueValue) {
      _redValue = redValue;
      _greenValue = greenValue;
      _blueValue = blueValue;
      //умножаем значение компонентов на коэффициент и округляем
      analogWrite(_redPin, int(_redValue * _k));
      analogWrite(_greenPin, int(_greenValue * _k));
      analogWrite(_bluePin, int(_blueValue * _k));
    }

    void hex(String hexColor) {
      extract(hexColor);    //разбиваем строку на компоненты RGB
      rgb(_r, _g, _b);      //заливаем компоненты в функцию rgb()
    }

    void off() {
      analogWrite(_redPin, 0);
      analogWrite(_greenPin, 0);
      analogWrite(_bluePin, 0);
    }
    void setSpeed(uint8_t period) {
      _period = period;
    }

    void gradient(uint8_t color1, uint8_t color2) {
      if (color1 == R && color2 == G) {  //от красного к зелёному
        for (int i = 0; i < 255; i++) {
          rgb(255 - i, i, 0);
          delay(_period);
        }
      }
      else if (color1 == G && color2 == R) {  //от зелёного к красному
        for (int i = 0; i < 255; i++) {
          rgb(i, 255 - i, 0);
          delay(_period);
        }
      }
      else if (color1 == G && color2 == B) {  //от зелёного к синему
        for (int i = 0; i < 255; i++) {
          rgb(0, 255 - i, i);
          delay(_period);
        }
      }
      else if (color1 == B && color2 == G) {  //от синего к зелёному
        for (int i = 0; i < 255; i++) {
          rgb(0, i, 255 - i);
          delay(_period);
        }
      }
      else if (color1 == B && color2 == R) {  //от синего к красному
        for (int i = 0; i < 255; i++) {
          rgb(i, 0, 255 - i);
          delay(_period);
        }
      }
      else if (color1 == R && color2 == B) {  //от красного к синему
        for (int i = 0; i < 255; i++) {
          rgb(255 - i, 0, i);
          delay(_period);
        }
      }
    }

    void rainbow(uint8_t mode) {
      if (mode == R) {
        gradient(R, G);
        gradient(G, B);
        gradient(B, R);
      }
      else if (mode == G) {
        gradient(G, B);
        gradient(B, R);
        gradient(R, G);
      }
      else if (mode == B) {
        gradient(B, R);
        gradient(R, G);
        gradient(G, B);
      }
    }

  private:
    uint8_t _redPin;
    uint8_t _greenPin;
    uint8_t _bluePin;

    uint8_t _greenValue;
    uint8_t _redValue;
    uint8_t _blueValue;

    float _k = 1.0;
    uint8_t _r, _g, _b;

    uint8_t _period = 10;

    void extract(String hexColor) {
      //разбиваем строку на 3 значения RGB
      String rStr = hexColor.substring(1, 3);
      String gStr = hexColor.substring(3, 5);
      String bStr = hexColor.substring(5, 7);
      _r = strtol(rStr.c_str(), nullptr, 16);
      _g = strtol(gStr.c_str(), nullptr, 16);
      _b = strtol(bStr.c_str(), nullptr, 16);
    }
};
