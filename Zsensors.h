#pragma once
#include "Zdht22.h"
#include "Zbme280.h"
#include "Zb20.h"
#include "Zbh1750.h"
#include "Zuv.h"
#include "Zrecord.h"
#include "Zntp.h"
#include "Zrain.h"

class Zsensors{
  //Zdht22 zdht22;
  Zbme280 zbme280{};
  Zb20 zb20{ONE_WIRE_BUS};
  Zbh1750 zbh1750{};
  Zntp zntp{};
  Zrain zrain{};
  Zuv zuv{UV_PIN};

  Record lastDataRecord;

  public: 
  
  void updateMeasures(){
    lastDataRecord = {
      zntp.getTimeStamp(),
      zbme280.getTemperature(),
      zbme280.getHumidity(),
      zbme280.getPressure(),
      zbh1750.getLux(),
      zb20.getTemperature(),
      zrain.getRain(),
      zuv.getUvIndex()
    };
  }

  Record getMeasuresRecord(){
    return lastDataRecord;
  }
};