
#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(0, 1); //TX, RX respetively
String readvoice;

void setup() {
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

}
//-----------------------------------------------------------------------// 
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
  readvoice += c; //build the string- "forward", "reverse", "left" and "right"
  } 
  if (readvoice.length() > 0) {
    Serial.println(readvoice);

  if(readvoice == "*forward#")
  {
    digitalWrite(3, HIGH);
    digitalWrite (4, HIGH);
    delay(100);
  }

  else if(readvoice == "*stop#")
  {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }

  else if (readvoice == "*left#")
  {
    digitalWrite (3,HIGH);
    digitalWrite (4,LOW);
   delay (800);
      
  }

 else if ( readvoice == "*right#")
 {
   digitalWrite (3, LOW);
   digitalWrite (4, HIGH);
   delay (800);
 }


 readvoice="";}} //Reset the variable
