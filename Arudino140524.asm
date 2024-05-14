
#define O OUTPUT
#define I INPUT
#define dw digitalWrite 
#define dr digitalRead
#define ar analogRead
#define aw analogWrite
//void setup() {
//  // put your setup code here, to run once:
//  pinMode(8,I);
//  pinMode(7,O);
//
//}
//void loop() {
//
//  if(dr(8)){
//    dw(7,1);
//  }
//   else
//    dw(7,0);
//}
//void setup() {
//  // put your setup code here, to run once:
//Serial.begin(9600);
//
//}
//void loop() {
//Serial.println(analogRead(A0));
//delay(100);
//}

void setup() {
  pinMode(11,O);
  // put your setup code here, to run once:
}
void loop() {
  int pv = ar(A1);
  pv/=4 ;
  Serial.println(pv);
  aw(11,pv);

}
