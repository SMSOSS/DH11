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
  if (val == DHT.humidity) {
    Serial.println("No");
  } else {
    if (val == 0) {
    val = DHT.humidity;
    }
    else {
        Serial.println("Change");
        Serial.print("Humidity = ");
        Serial.println(DHT.humidity);
        val = DHT.humidity;
        }
  }


  delay(1000);
}
