#pragma once

class Zuv{

  int analogPin;

  public:
  Zuv(int analogPin):analogPin{analogPin}
  {}

  int getUvIndex(){
    return analogRead(analogPin) / 100 / 3.3;
  }
};