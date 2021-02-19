#include <Servo.h> 
Servo r;  // create servo object to control a servo
int off=0;
Servo l;  // create servo object to control a servo
int of=0;
void setup()  
{
    Serial.begin(9600);
  pinMode(5,INPUT);
  pinMode(4,INPUT);
  r.attach(9);  // attaches the servo on pin 9 to the servo object
  delay(200);
  l.attach(6);  // attaches the servo on pin 9 to the servo object
  delay(200);
}

void loop()                     // run over and over again
{  
  
  int p=digitalRead(5);
  int q=digitalRead(4);
    Serial.print(p);
    
    Serial.print("    ");
    Serial.println(q);
    
    if(p==HIGH)
    runlock();
    if(q==HIGH)
    lunlock();
    if(p==LOW){
    rlock();
    }
    if(q==LOW){
      llock();
      }
}


  void rlock(){
  r.write(95);
  delay(1000);
  }

void runlock(){
    r.write(0);
  delay(1000);
    }

    
void lunlock(){
  l.write(95+of);
  delay(1000);
  }

void llock(){
    l.write(0+of);
  delay(1000);
    }
