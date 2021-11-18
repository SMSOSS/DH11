//for more projects visit:www.blackkeyhole.com

#include <dht.h> // load lib



#define dht_apin   11
dht DHT;  // sensor pin S to pin11
int val = 0;
void setup() {
  Serial.begin(9600);

}


void loop() {
  DHT.read11(dht_apin);
  if (val == DHT.temperature) {
    Serial.println("No");
  } else {
    if (val == 0) {
    val = DHT.temperature;
    }
    else {
        Serial.println("Change");
        Serial.print("Temperature = ");
        Serial.println(DHT.temperature);
        val = DHT.temperature;
        }
  }


  delay(1000);
}
