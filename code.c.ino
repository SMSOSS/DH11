//for more projects visit:www.blackkeyhole.com

#include <dht.h> // load lib



#define dht_apin   7
dht DHT;  // sensor pin S to pin11
int val ;
void setup() {
  val = DHT.humidity;
  Serial.begin(9600);

}


void loop() {
  DHT.read11(dht_apin);
  if(val == DHT.humidity){
    Serial.println("No");
  }else{
    Serial.println("Change");
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity);
    val = DHT.humidity;
  }

  
  delay(1000);
}
