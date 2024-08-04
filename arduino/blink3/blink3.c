// C++ code
void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
}

void loop()
{
 	digitalWrite(7,HIGH),digitalWrite(6,LOW),digitalWrite(5,LOW);
  	delay(300);
   	digitalWrite(6,HIGH),digitalWrite(7,LOW),digitalWrite(5,LOW);
  	delay(300);
   	digitalWrite(5,HIGH),digitalWrite(6,LOW),digitalWrite(7,LOW);
  	delay(300);

}