 
#include <Wire.h> 
#include <Adafruit_GFX.h> 
#include "Adafruit_LEDBackpack.h" 
 
#define SEND_DELAY 200   
 
Adafruit_8x16minimatrix matrix = Adafruit_8x16minimatrix(); 

const int sw1 = 16;
const int sw2 = 14; 

byte cnt = 0; 

void setup(){
  Serial.begin(9600);  
  Wire1.begin(4, 5);
  
  matrix.begin(0x70);
  matrix.setRotation(1); 
  matrix.setTextSize(1); 
  matrix.setTextWrap(false); 
  matrix.setTextColor(LED_ON); 

  pinMode(sw1,INPUT_PULLUP);
  pinMode(sw2,INPUT_PULLUP);
}

void loop()
{ 

   int sw1Val = digitalRead(sw1);
   int sw2Val = digitalRead(sw2);

if(sw1Val==LOW){
  cnt++;
}
else if(sw2Val==LOW){
  cnt--;
} 

  //Display value on LED Matrix
  matrix.clear();
  matrix.setCursor(3,0);
  String data = String(cnt);
  Serial.println(data);
  matrix.print(data); 
  matrix.writeDisplay();

  delay(SEND_DELAY);
}
                                                                                  
