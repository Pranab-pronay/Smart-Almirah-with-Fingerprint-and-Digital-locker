#include <SoftwareSerial.h>

//Create software serial object to communicate with A6
SoftwareSerial A6GSM(2,3); //A6 Tx & Rx is connected to Arduino #3 & #2
int a=1;
void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  delay(500);

}

void loop(){
  a=0;
  a=digitalRead(8);
//delay(500);
  if(a==1){
    yes();
    }
//  while(A6GSM.available()){
//    Serial.write(A6GSM.read());
//    }
//    while(Serial.available()){
//      A6GSM.write(Serial.read());
//      }
       // Serial.println("checkpoint");
}
void yes(){
  Serial.begin(9600);
  delay(500);
  //Begin serial communication with Arduino and A6
  A6GSM.begin(9600);
  delay (1000);
  Serial.println("Initiating A6"); 
  delay(1000);

  A6GSM.println("AT"); //Once the handshake test is successful, it will back to OK
  delay(1000);

  A6GSM.println("AT+CMGF=1"); // Configuring TEXT mode
  delay (1000);
  A6GSM.println("AT+CMGS=\"8801711871931\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  delay(3000);
    A6GSM.print("INTRUDER ALERT"); //text content
  delay(3000);
  A6GSM.println(char(26));
  delay(2000);
  }
