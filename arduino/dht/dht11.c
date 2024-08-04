#include<dht11.h>

dht11 d;

void setup()
{
	Serial.begin(9600);
}

void loop()
{

  d.read(2);
  
  Serial.print("Humidity = ");
  Serial.println((float)d.humidity,2);
  Serial.print("Temperature = ");
  Serial.println((float)d.temperature,2);
  
  delay(2000);
}