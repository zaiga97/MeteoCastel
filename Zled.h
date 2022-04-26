#pragma once

class Zled{
  int pin;

  public:
  Zled(int pin){
    pin = pin;
    pinMode(pin, OUTPUT);
    digitalWrite (pin, LOW);
  }

  void blink(int times = 3){
    for (int i = 0; i < times; i++)
    {
      digitalWrite (pin, HIGH);
      delay (300);
      digitalWrite (pin, LOW);
      delay (300);
    }
  }
};