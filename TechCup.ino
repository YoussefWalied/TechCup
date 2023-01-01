#include <LiquidCrystal_I2C.h>
#include<Wire.h>
int const trigPin = 10;
int const echoPin = 9;
int const buzzPin = 2;
int const pump = 8;
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(pump, OUTPUT);
}

void loop() {
  
  int duration, distance;
  lcd.setCursor(2,0);
  
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
      Serial.println(distance);

  
  if(distance<10){
    Serial.println(distance);
    delay(500);
   digitalWrite(pump,HIGH);
   lcd.clear();
   lcd.print("Waiting...");

   for(int i = 0;i<=100;i++){
  if(distance<10){delay(150);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  }
   }
   digitalWrite(pump,LOW);
   lcd.clear(); 
   tone(buzzPin,2000);
   delay(600); noTone(buzzPin);
   lcd.setCursor(0,0);
   lcd.print("take ur cup");
   lcd.setCursor(1,1);
   lcd.print("thnx for using");
   delay(1000);
   lcd.clear();
   lcd.print("    TechCup");
   delay(2000);
   lcd.clear();  
 }
 else{
  
  lcd.setCursor(2,1);
  lcd.print("place ur cup");
  digitalWrite(pump,LOW);
 }
 
}