#include <dht.h> // load dht lib
#include <Tone.h> // load tone lib

#define flamePin    12 // define flame pin
#define buzzerPin   8  // define buzzer pin
#define smokePin    5  // define smoke sensor pin
#define debugMode   0  // define debug mode
#define smokeThres  300 // smoke level threshold. depends on situation + sensor. tune later.
dht DHT;  // sensor pin S to pin11

int temp = 65536; // initialize temperature value to zero
int smoke; // smoke val uses integer
int flame; // flame val uses integer

void setup() {
  Serial.begin(9600); // label 9600 baud
}

void loop() {
  smoke = analogRead(smokePin);
  flame = digitalRead(flamePin);
  // real bug trigger
  if (flame == 1 && (analogRead(smokePin) > smokeThres){
    Serial.println("[WARN] Potential flame detected");
    Serial.print("Current flame val: ");
    Serial.println(flame);
    Serial.print("Current Smoke level :");
    Serial.println(smoke);
    tone(buzzerPin, 2000, 500); // buzz buzz when fire
  }
  else {
    Serial.println("[INFO] All stable"); // val update
    temp = DHT.temperature;
    if (debugMode == 1) {
        Serial.print("[DEBUG] Current flame value: ");
        Serial.println(flame);
        Serial.print("[DEBUG] Current smoke value: ");
        Serial.println(smoke);
    }
  }

  delay(1000);
}
