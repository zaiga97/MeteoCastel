#pragma once  


volatile unsigned int RainCount = 0;
IRAM_ATTR void RainIncrementCount(){
    RainCount++;
}

class Zrain{
  const float mmForEveryCount = 0.37;

  public:
  Zrain(){
    pinMode(RAIN_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(RAIN_PIN), RainIncrementCount, RISING);
  }

  float getRain(){
    float mmOfRain = RainCount * mmForEveryCount;
    RainCount = 0;
    return mmOfRain;
  }
};


