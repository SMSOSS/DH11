#include <dht.h> // load dht lib
#include <Tone.h> // load tone lib

#define dht_apin   11 // define pin node
#define buzzerPin   8  // define buzzer pin
dht DHT;  // sensor pin S to pin11
int temp = 65536; // initialize temperature value to zero

void setup() {
  Serial.begin(9600); // label 9600 baud
}

void loop() {
  DHT.read11(dht_apin);
  // device hasn't been set up yet
  if (temp == 65536){
    Serial.println("[INFO] Initializing values");
    temp = DHT.temperature;
   } // finish device setup

  // real bug trigger
  if (DHT.temperature > (temp + 3)){
    Serial.println("[WARN] Potential fire detected");
    Serial.print("Current temperature: ");
    Serial.println(DHT.temperature);
    tone(buzzerPin, 2000, 500); // buzz buzz when fire
  }
  else if (DHT.temperature < temp) { // val update
    Serial.println("[INFO] Updating stored values");
    temp = DHT.temperature;
  }
  else {
    Serial.println("[INFO] All stable"); // val update
    temp = DHT.temperature;
  }

  delay(1000);
}
