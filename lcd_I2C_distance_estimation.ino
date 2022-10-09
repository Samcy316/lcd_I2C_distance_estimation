const int trig_pin=9;
const int echo_pin=10;
const int buzzer_pin=8;
const int red_led=4;
const int green_led=7;
const int blue_led=6;
float  distance_cm;
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

long duration;


void setup()
{
 lcd.init(); //initialize lcd
 lcd.backlight();
 lcd.begin(16,2);
 lcd.setCursor(0,0);
 pinMode(trig_pin, OUTPUT);
 pinMode(echo_pin, INPUT);
 pinMode(red_led, OUTPUT);
 pinMode(green_led, OUTPUT);
 pinMode(blue_led, OUTPUT);
 pinMode(buzzer_pin, OUTPUT);
 
}

void loop()
{
  digitalWrite(trig_pin,LOW);
  delayMicroseconds(2); 
   digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
   digitalWrite(trig_pin,LOW);
  duration=pulseIn(echo_pin,HIGH);
  distance_cm=(duration*0.034)/2.0;
  if(distance_cm<=10)
  {
     digitalWrite(buzzer_pin,LOW);
     lcd.setCursor(0,0);
     lcd.print("NO OBJECT[>10CM]");
     lcd.setCursor(0,1);
     lcd.print("DETECTED!");
     delay(1000);
     lcd.clear();
     digitalWrite(green_led, HIGH);
  


  }
  else
  {
     digitalWrite(buzzer_pin,HIGH);
     lcd.setCursor(0,0);
     lcd.print("DISTANCE(CM):");
     lcd.print(distance_cm);
     
     lcd.setCursor(0,1);
     lcd.print("DETECTED!");
     delay(1000);
     lcd.clear();
     digitalWrite(red_led, HIGH);
      digitalWrite(green_led, LOW);
  
 }
 
 
}
