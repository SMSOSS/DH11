//for more projects visit:www.blackkeyhole.com

#include <dht.h> // load lib



#define dht_apin   11
dht DHT;  // sensor pin S to pin11
int temp = 0;
int hydr = 0;
void setup() {
  Serial.begin(9600);

}


void loop() {
  DHT.read11(dht_apin);
  if (temp == 0){
    temp = DHT.temperature;
    hydr = DHT.humidity;
   }
  if (DHT.temperature > temp && hydr < DHT.humidity){
    Serial.println("[WARN] Potential fire detected");
    Serial.print("Current temperature: ");
    Serial.println(DHT.temperature);
    Serial.print("Current humidity: ");
    Serial.println(DHT.humidity);
  }
  else {
    Serial.println("[INFO] All stable");
  }

  delay(1000);
}
