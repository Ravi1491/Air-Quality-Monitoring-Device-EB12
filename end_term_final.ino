#include <MQUnifiedsensor.h>
#define pin A0 //Analog input 0 of your arduino
#define type 135 //MQ135
MQUnifiedsensor MQ135(pin, type);
#include <LiquidCrystal.h> 
LiquidCrystal lcd(12,11, 5, 4, 3, 2);
void setup() 
{
lcd.begin(16,2);
lcd.setCursor (0,0);
lcd.print ("Air Quality ");
//Serial.print ("Air Quality ");
lcd.setCursor (0,1);  
lcd.print ("Sensor Warming ");
//Serial.print ("Sensor Warming ");
delay(1000);
Serial.begin(9600);
lcd.clear();
  MQ135.inicializar(); 
}

void loop() {
float air_quality =analogRead(A0);
Serial.print("Air quality=");
Serial.println( air_quality , DEC); 
lcd.setCursor (0, 0);
lcd.print ("Air Quality is ");
lcd.print (air_quality);
lcd.print (" PPM ");
lcd.setCursor (0,1);
if (air_quality<=200)
{
lcd.print("Fresh Air");
Serial.print("Fresh Air");
digitalWrite(8, LOW);
}
else if( air_quality>=201 && air_quality<=300 )
{
lcd.print("Poor Air, Open Windows");
Serial.print("Poor Air, Open Windows");
digitalWrite(8, HIGH );
}
else if (air_quality>=301 )
{
lcd.print("Danger! Move to Fresh Air");
Serial.print("Danger! Move to Fresh Air");
digitalWrite(8, HIGH);   // turn the LED on
}
lcd.scrollDisplayLeft();
delay(1000);
}
