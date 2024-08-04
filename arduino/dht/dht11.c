#include<dht11.h>

dht11 d;
#define pin 2
//#define pin D2
void setup()
{
	Serial.begin(9600);
}

void loop()
{

  d.read(pin);
  
  Serial.print("Humidity = ");
  Serial.println((float)d.humidity,2);
  Serial.print("Temperature = ");
  Serial.println((float)d.temperature,2);
  
  delay(2000);
}