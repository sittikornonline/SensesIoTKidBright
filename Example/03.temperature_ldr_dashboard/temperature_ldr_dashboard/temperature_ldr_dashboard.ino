#include "Senses_wifi_esp32.h"
#include <Wire.h>

#define LM73_ADDR 0x4D
#define SEND_DELAY 3000
const int analogInPin = 36;

const char *ssid = "BOOM_WiFi";
const char *passw = "076434654";
const char *userid = "122";
const char *key = "p3itsvhtzzj7";

int slot_data_temp = 1;
int slot_data_ldr  = 2;

float temp = 0;
int ldr = 0;

Senses_wifi_esp32 myiot;
float readTemperature();

void setup() {
  Serial.begin(9600);
  Wire1.begin(4, 5);
  Serial.println(F("Senses Platform in KidBright"));
  String response = myiot.connect(ssid, passw, userid, key);
  Serial.println(response);
}

void loop() {

  temp = readTemperature();
  ldr  = analogRead(analogInPin);

  myiot.send(slot_data_temp, temp);
  myiot.send(slot_data_ldr , ldr);
  Serial.print("Temp  = ");  Serial.println(temp);
  Serial.print("LDR   = ");  Serial.println(ldr);
  Serial.println("Send data to Senses Platform");
  Serial.println("---------------------------------");

  delay(SEND_DELAY);
}

//โค้ดมาจาก http://quantum.engr.tu.ac.th/smf/index.php?topic=94.0
float readTemperature() {
  Wire1.beginTransmission(LM73_ADDR);
  Wire1.write(0x00);
  Wire1.endTransmission();

  uint8_t count = Wire1.requestFrom(LM73_ADDR, 2);
  float temp = 0.0;
  if (count == 2) {
    byte buff[2];
    buff[0] = Wire1.read();
    buff[1] = Wire1.read();
    temp += (int)(buff[0] << 1);
    if (buff[1] & 0b10000000) temp += 1.0;
    if (buff[1] & 0b01000000) temp += 0.5;
    if (buff[1] & 0b00100000) temp += 0.25;
    if (buff[0] & 0b10000000) temp *= -1.0;
  }
  return temp;
}
