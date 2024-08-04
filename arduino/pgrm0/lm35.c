
void setup()
{
	Serial.begin(9600);
}

void loop()
{
	int r = analogRead(A0);
  	float v = r*(5/1024);
  	float tc = v*100;
  	Serial.print("Temperature in C = ");
  	Serial.print(tc);
  	Serial.print("    ");
  	Serial.print("Temperature in F = ");
  	Serial.print(tc*9/5 + 32);
  	Serial.println();
  	delay(1000);
  	
}