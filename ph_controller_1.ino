#include <LiquidCrystal.h>

LiquidCrystal lcd(6, 7, 5, 4, 3, 2);//RS,EN,D4,D5,D6,D7 

const int analogInPin = A0; 
int ppump = 12;
const unsigned long ppump_offTime = 11000;
unsigned long ppump_onTime = 1000;
unsigned int ppumpstate = LOW;
unsigned long previousMillis=0;
int sensorValue = 0; 
unsigned long int avgValue; 
float b;
int buf[10],temp;

void setup() {
  
 pinMode (ppump,OUTPUT);
 digitalWrite (ppump,HIGH);
 Serial.begin(9600);
 
 lcd.begin(16, 2);
 lcd.setCursor(0,0);
 lcd.print("PERFECT pH ");
 lcd.setCursor(0,1);    
 lcd.print("BITCHES! ");
 delay(2000);
}

void loop() {
 for(int i=0;i<10;i++) 
 { 
  buf[i]=analogRead(analogInPin);
  delay(10);
 }
 for(int i=0;i<9;i++)
 {
  for(int j=i+1;j<10;j++)
  {
   if(buf[i]>buf[j])
   {
    temp=buf[i];
    buf[i]=buf[j];
    buf[j]=temp;
   }
  }
 }
 
 avgValue=0;//
 for(int i=2;i<8;i++)
 avgValue+=buf[i];
 
 float pHVol=(float)avgValue*5.0/1024/6;
 float phValue = -6.00 * pHVol + 22.75;
 
 Serial.print("sensor = ");
 Serial.println(phValue);
 lcd.clear();
 lcd.setCursor(0,0);  
 lcd.print("YOUR PERFECT PH");
 lcd.setCursor(3,1);  
 lcd.print(phValue);
 delay(900);
 {
 }
 long currentMillis = millis();

 if ((ppump==HIGH)&&(phValue<5.85>=ppump_offTime))
 {

 } else if(ppump==LOW)&&(phValue>5.85>=onTime))
  
  {
    //digitalWrite(RELAY2, LOW);
    ppump = HIGH;  // Turn it off
    previousMillis = currentMillis;  // Remember the time
    digitalWrite(ppump, HIGH);  // Update the actual relay
  } 
}
 
