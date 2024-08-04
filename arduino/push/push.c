// C++ code
void setup()
{
  pinMode(6,INPUT_PULLUP);
  pinMode(7, OUTPUT);
  
}

void loop()
{
 	if(digitalRead(6)==LOW)
      digitalWrite(7,HIGH);
  	else
      digitalWrite(7,LOW);
}