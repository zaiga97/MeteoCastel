#pragma once

#define MAX_RECORDS 50 // Make it less than 50... if you change something you have to test max again

class Record{
  public:

  String timeStamp;
  float airTemperature;
  float humidity;
  float pressure;
  float lightIntensity;
  float groundTemperature;
  float rain;
  int uvIndex;


  Record() = default;

  Record(const String timeStamp, const float airTemperature, const float humidity, const float pressure, const float lightIntensity, const float groundTemperature, const float rain, const int uvIndex):
    timeStamp{timeStamp},
    airTemperature{airTemperature},
    humidity{humidity},
    pressure{pressure},
    lightIntensity{lightIntensity},
    groundTemperature{groundTemperature},
    rain{rain},
    uvIndex{uvIndex}{
  }


  String toString() const {
    return String("[\"") + timeStamp + "\", " + 
          airTemperature + ", " +
          humidity + ", " +
          pressure + ", " +
          lightIntensity + ", " +
          groundTemperature + ", " +
          rain + ", " +
          uvIndex + "]"; 
  }
};

class Records{
  public:
  
  Record toSendRecords[MAX_RECORDS];
  int toSend = 0;

  bool addRecord(Record record){
    if (toSend >= MAX_RECORDS) return false;
    toSendRecords[toSend++] = record;
    return true;
  }

  String toString() const {
    String s = "[";
    for (int i=0; i<toSend; i++){
      s += toSendRecords[i].toString();
      if (!(i+1 == toSend)) s += ",";
    }
    s += "]";
    return s;
  }

  void clear(){toSend = 0;}
};