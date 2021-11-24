#include <dht.h> // load dht lib

// rain2wood@SMSOSS, import common lib
#include <stdio.h>
#include <stdlib.h>

/* rain2wood@SMSOSS, import custom fireStat lib */
#include "firestat.h"

#define dht_apin   11 // define pin node
#define flamePin    12  // define flame sensor pin
#define debugMode   0  // define debug mode
dht DHT;  // sensor pin S to pin11

int temp = 65536; // initialize temperature value to zero
int flame; // flame val uses integer
int isFire = 0;
    	
void setup() {
  Serial.begin(9600); // label 9600 baud
}

void loop() {
  DHT.read11(dht_apin);
  flame = digitalRead(flamePin);
  // device hasn't been set up yet
  if (temp == 65536){
    Serial.println("[INFO] Initializing values");
    temp = DHT.temperature;
   } // finish device setup

  // real bug trigger
  if (DHT.temperature > (temp + 3) && flame != 1){
    Serial.println("[WARN] Potential fire detected");
    Serial.print("Current temperature: ");
    Serial.println(DHT.temperature);
    Serial.print("Current flame level :");
    Serial.println(flame);
    isFire = 1;
  }
  else if (DHT.temperature < temp) { // val update
    Serial.println("[INFO] Updating stored values");
    temp = DHT.temperature;
    isFire = 0;
    if (debugMode == 1) {
        Serial.print("[DEBUG] Current temperature value: ");
        Serial.println(temp);
        Serial.print("[DEBUG] Current flame value: ");
        Serial.println(flame);
    }
  }
  else {
    Serial.println("[INFO] All stable"); // val update
    temp = DHT.temperature;
    if (debugMode == 1) {
        Serial.print("[DEBUG] Current temperature value: ");
        Serial.println(temp);
        Serial.print("[DEBUG] Current flame value: ");
        Serial.println(flame);
    }
  }

  delay(1000);
}
