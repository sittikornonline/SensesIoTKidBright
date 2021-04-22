const int VRx = 18;
const int VRy = 19;
const int SW  = 23;

const int LED_BT   = 17;
const int LED_WIFI = 2;
const int LED_NTP  = 15;

void setup() {
  Serial.begin(9600);
  pinMode(VRx, INPUT_PULLUP);
  pinMode(VRy, INPUT_PULLUP);
  pinMode(SW,  INPUT_PULLUP);

  pinMode(LED_BT,  OUTPUT);
  pinMode(LED_WIFI, OUTPUT);
  pinMode(LED_NTP, OUTPUT);
}

void loop() {

  int VRxVal = digitalRead(VRx);
  int VRyVal = digitalRead(VRy);
  int SWVal  = digitalRead(SW);

  Serial.print("VRxVal = "); Serial.println(VRxVal);
  Serial.print("VRyVal = "); Serial.println(VRyVal);
  Serial.print("SWVal  = "); Serial.println(SWVal);
  Serial.println("==========");

  if (VRxVal == HIGH) {
    digitalWrite(LED_BT, LOW);
  } 
  else {
    digitalWrite(LED_BT, HIGH);
  }

  if (VRyVal == HIGH) {
    digitalWrite(LED_WIFI, LOW);
  } 
  else {
    digitalWrite(LED_WIFI, HIGH);
  }

  if (SWVal == HIGH) {
    digitalWrite(LED_NTP, LOW);
  } 
  else {
    digitalWrite(LED_NTP, HIGH);
  }

  delay(250);
}                                                         
