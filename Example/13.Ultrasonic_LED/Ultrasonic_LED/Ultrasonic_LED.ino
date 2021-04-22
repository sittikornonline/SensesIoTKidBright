int trigPin  = 18;
int echoPin  = 19;

int LED_BT   = 17; //LED 4
int LED_WIFI = 2;  //LED 3
int LED_NTP  = 15; //LED 2
int LED_IOT  = 12; //LED 1

long duration, cm;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(LED_BT,  OUTPUT);
  pinMode(LED_WIFI, OUTPUT);
  pinMode(LED_NTP, OUTPUT);
  pinMode(LED_IOT, OUTPUT);

}

void loop() {

  digitalWrite(trigPin, LOW);  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  // Convert the time into a distance
  cm = (duration / 2) * 0.0347362 ;

  Serial.print(cm); Serial.print("cm");  Serial.println();

  if (cm <= 2) {
    digitalWrite(LED_BT  , HIGH);
    digitalWrite(LED_WIFI, HIGH);
    digitalWrite(LED_NTP , HIGH);
    digitalWrite(LED_IOT , HIGH);
  }

  else if (cm <= 5) {
    digitalWrite(LED_BT  , HIGH);
    digitalWrite(LED_WIFI, HIGH);
    digitalWrite(LED_NTP , HIGH);
    digitalWrite(LED_IOT , LOW);
  }

  else if (cm <= 10) {
    digitalWrite(LED_BT  , HIGH);
    digitalWrite(LED_WIFI, HIGH);
    digitalWrite(LED_NTP , LOW);
    digitalWrite(LED_IOT , LOW);
  }

  else if (cm <= 15) {
    digitalWrite(LED_BT  , HIGH);
    digitalWrite(LED_WIFI, LOW);
    digitalWrite(LED_NTP , LOW);
    digitalWrite(LED_IOT , LOW);
  }

  else if (cm <= 20 || cm > 20) {
    digitalWrite(LED_BT  , LOW);
    digitalWrite(LED_WIFI, LOW);
    digitalWrite(LED_NTP , LOW);
    digitalWrite(LED_IOT , LOW);
  }

  delay(250);
}
