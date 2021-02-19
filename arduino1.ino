#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

//7 right al
//9 left al

SoftwareSerial mySerial(2,3);  //3 te white

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
  int ls=1;
  int rs=1;
  int crap=0;
void setup()  
{
  Serial.begin(9600);
  finger.begin(57600);
  finger.getTemplateCount();
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  delay(100);
  pinMode(7,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(10,OUTPUT);

}

void loop()                     // run over and over again
{  
  int ra=digitalRead(7);
  int la=digitalRead(9);
  Serial.print(la);
  Serial.print("  ");
  Serial.println(ra);
  getFingerprintIDez();
  delay(50);            //don't ned to run this at full speed.

  if(la==0&&ra==0){
        crap=0;
        }
  if(ls==1||rs==1){
    if(la==1||ra==1){
      crap++;
      }
    }
    if(crap>5){
      text();
      crap=0;
      }
}

int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  {
  Serial.println("milenai");
  digitalWrite(8,HIGH);
  delay(100);
  digitalWrite(8,LOW);

    return -1;
  }

Serial.print(finger.fingerID); 
  delay(500);
  Serial.println(finger.confidence);
  delay(500);
  if(finger.fingerID==1||finger.fingerID==2){
    rdo();
    }
  else if(finger.fingerID==3||finger.fingerID==4){
      ldo();
      }
  return finger.fingerID; 
}

void ldo(){
  Serial.print("x");
  if (ls==0){
    digitalWrite(4,LOW);
    Serial.println("low");
    delay(100);
    ls=1;
    }
    else if(ls==1){
      digitalWrite(4,HIGH);
      Serial.println("high");
      delay(100);
      ls=0;
      }
  }

void rdo(){
  
  Serial.print("y");
  if (rs==0){
    digitalWrite(5,LOW);
    Serial.println("low");
    delay(100);
    rs=1;
  }
    else if(rs==1){
      digitalWrite(5,HIGH);
      Serial.println("high");
      delay(100);
      rs=0;
      }
  }

  void text(){
    digitalWrite(10,HIGH);
    delay(500);
    digitalWrite(10,LOW);
    }
