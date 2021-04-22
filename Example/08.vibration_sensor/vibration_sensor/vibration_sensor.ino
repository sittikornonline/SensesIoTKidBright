const int vibrationPin = 33;    
const int ledPin =  17;      

int vibrationState = 0;          

void setup() {
 
  pinMode(ledPin, OUTPUT); 
  pinMode(vibrationPin, INPUT);
}

void loop() { 
  vibrationState = digitalRead(vibrationPin);
 
  if (vibrationState == HIGH) { 
    digitalWrite(ledPin, HIGH);
  } 
  else { 
    digitalWrite(ledPin, LOW);
  }
}                                                         
