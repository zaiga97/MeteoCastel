#pragma once
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

class Zbmp280{
  Adafruit_BMP280 bmp{};

  public:

  Zbmp280(){
    if(!bmp.begin()) return;

    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,
                    Adafruit_BMP280::SAMPLING_X2,    
                    Adafruit_BMP280::SAMPLING_X16,    
                    Adafruit_BMP280::FILTER_X16,      
                    Adafruit_BMP280::STANDBY_MS_500); 
  }

  float getTemperature(){
    return bmp.readTemperature();
  }

  float getPression(){
    return bmp.readPressure();
  }
};