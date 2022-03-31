#pragma once

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

class Zbme280{
  Adafruit_BME280 bme{};

  public:

  Zbme280(){
    if(!bme.begin(0x76)) return;
  }

  float getTemperature(){
    return bme.readTemperature();
  }

  float getPressure(){
    return bme.readPressure();
  }

  float getHumidity(){
    return bme.readHumidity();
  }
};

