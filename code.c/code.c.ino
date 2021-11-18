#include <dht.h> // load lib



#define dht_apin   11 // define pin node
dht DHT;  // sensor pin S to pin11
int temp = 65536; // initialize temperature value to zero
int hydr = 65536; // initialize hydro value to zero

void setup() {
  Serial.begin(9600); // label 9600 baud
}

void loop() {
  DHT.read11(dht_apin);
  // device hasn't been set up yet
  if (temp == 65536){
    Serial.println("[INFO] Initializing values");
    temp = DHT.temperature;
//    hydr = DHT.humidity;
   } // finish device setup

  // real bug trigger
  if (DHT.temperature > (temp + 3)){
    Serial.println("[WARN] Potential fire detected");
    Serial.print("Current temperature: ");
    Serial.println(DHT.temperature);
//    Serial.print("Current humidity: ");
//    Serial.println(DHT.humidity);
  }
  else if (DHT.temperature < temp) { // val update
    Serial.println("[INFO] Updating stored values");
    temp = DHT.temperature;
//    hydr = DHT.humidity;    
  }
  else {
    Serial.println("[INFO] All stable"); // val update
    temp = DHT.temperature;
//    hydr = DHT.humidity; 
  }

  delay(1000);
}
