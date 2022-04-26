//########## Libraries ###################
#define LED D3
#define ONE_WIRE_BUS D4
#define PM_10 D5
#define PM_25 D6
#define WIND_PIN D7
#define RAIN_PIN D8
#define UV_PIN A0
const String googleAppUrl = "/macros/s/AKfycbyRfgFy4IWD6Qa7XESh9FctGKGs9Qa6Z412XNe3TnqF3HqWSGvMim02uY1pIwEXSZ4/exec";

//########## OtherFiles ##################
#include "Zwifi.h"
#include "Zrecord.h"
#include "Zclient.h"
#include "Zsensors.h"
#include "Zled.h"

//########## Objects #####################
Records records;
Zclient zclient;
Zwifi zwifi;
Zsensors zsensors;
Zled zled{LED};

//########## Setup #######################
void setup() {
  Serial.begin(115200);
  Serial.println("Starting the setup\n");
  
  Serial.println("Setup WiFi...\n");
  zwifi.setup();
  Serial.println("Connecting to WiFi...");
  if (!zwifi.connect()) return; // If not able to connect restart
  
  Serial.println("Setup client...\n");
  zclient.setup();
  zled.blink(3);
}


//########## Loop ########################
void loop() {
  
  //This is how the cycle should look like:
  //Once evry while:
    //Reconnect wifi
    zwifi.connect();
    //Get all measures updated
    zsensors.updateMeasures();

    //Add all measures to a queue
    if (!records.addRecord(zsensors.getMeasuresRecord())) Serial.println("Not able to add to records... Probably full!");
    else Serial.println("Added new records to the ones to send, now at: " + String(records.toSend));

    //Connect to wifi
    if (!zwifi.connect()){
      Serial.println("Unable to connect to wifi");
      //Do someting since you was not able to connect
    }

    else {
      //Connect to client
      if (zclient.connect()){
        //Send the data
        //Read response
        Serial.println("Making a new request:");
        zclient.send(records, "Today");
        //Dequeue the data sent
        records.clear();
        zled.blink(1);
      }
      else {
        Serial.println("Unable to connect to the client");
        //Do something since you was not able to reach the client
      }
    } 
    //Wifi sleep N.B: this is almost 10s lost
    Serial.println("Going to sleep");
    zwifi.sleep(10000);
    Serial.println("Waking up");
  //sleep/keep
}