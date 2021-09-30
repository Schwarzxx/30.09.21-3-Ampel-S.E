
  #include <SoftwareSerial.h>
  
  SoftwareSerial link (2, 3);
  
  int Rot = 13;
  int Gelb = 12;
  int Gruen = 11;
  int data = 0; 

  char cString[20];
  byte chPos = 0;
  byte ch = 0;
  char dataStr[6];
  


void setup() {
  
  Serial.begin(9600);
  link.begin(9600); 
  pinMode(Rot, OUTPUT);
  pinMode(Gelb, OUTPUT);
  pinMode(Gruen, OUTPUT);
  
}


void changeLights(){

   
// Grüne Phase
   digitalWrite(Gruen, HIGH);
   digitalWrite(Gelb, LOW);
   digitalWrite(Rot, LOW);
   delay(5000);

   
  
// Gelbe Phase
   digitalWrite(Gruen, LOW);
   digitalWrite(Gelb, HIGH);
   digitalWrite(Rot, LOW);
   delay(1500);




// Rote Phase

   digitalWrite(Gruen, LOW);
   digitalWrite(Gelb, LOW);
   digitalWrite(Rot, HIGH);
   delay(5000);
 

   
// Rot-Gelbe Phase

   digitalWrite(Gruen, LOW);
   digitalWrite(Gelb, HIGH);
   digitalWrite(Rot, HIGH);
   delay(100);

   
   
}


void loop() {
  
   
  
   if (link.available() > 0) {

  data = Serial.read();
  Serial.println((char)data);
  changeLights(); 
  delay (0.001);
   
   }

   
  while (link.available())
  
   { 
     ch = link.read();
     cString[chPos] = ch;
     chPos++;     
     cString[chPos] = 0; //terminate cString
     chPos = 0;
   
   Serial.print(cString);

   }

  }
   
