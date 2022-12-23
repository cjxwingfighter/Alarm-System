#include <Wire.h>
#include <Adafruit_TCS34725.h>
int buzzer = 12;
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;


Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(9600);
  //Serial.println("Color View Test!");

 pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output

  if (tcs.begin()) {
    //Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }
}
void loop()
{
  unsigned long z;
  
  float red, green, blue;
  
  tcs.setInterrupt(false);  // turn on LED

  delay(60);  // takes 50ms to read

  tcs.getRGB(&red, &green, &blue);
  
  tcs.setInterrupt(true);  // turn off LED

  Serial.print("R:\t"); Serial.print(int(red)); 
  Serial.print("\tG:\t"); Serial.print(int(green)); 
  Serial.print("\tB:\t"); Serial.print(int(blue));
  Serial.println("");
  unsigned char i;
  a = 1000;
  if (a = 1000)
   {
    int pass = 0;
    if ((red>=35) && (red<= 45) && (green<= 95)&& (green>= 90)&& (blue<= 115)&& (blue>= 105))
    {
      Serial.println ("Yes");
      int pass = 1; // what i need to fix, perminetly set outside of the loop
     }
    if ((pass = 0) && (z = 0, z = 5000, z++))
    {
        for(i=0;i<80;i++)
     {
           digitalWrite(buzzer,HIGH);
           delay(1);//wait for 1ms
           digitalWrite(buzzer,LOW);
           delay(1);//wait for 1ms
     }
    //output another frequency
         for(i=0;i<100;i++)
          {
           digitalWrite(buzzer,HIGH);
           delay(2);//wait for 2ms
           digitalWrite(buzzer,LOW);
           delay(2);//wait for 2ms
           }
          delay(1);
       }
     delay(1);
    }
  }
