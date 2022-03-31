#pragma once
#include <BH1750.h>
#include <Wire.h>

class Zbh1750{
  BH1750 lightMeter{};

  public:

  Zbh1750(){
    Wire.begin();
    lightMeter.begin();
  }

  float getLux(){
    return lightMeter.readLightLevel();
  }
};