void setup()
{
  pinMode(7, OUTPUT);
}

void loop()
{
 	int b = analogRead(A0);
  	analogWrite(7,b);
}