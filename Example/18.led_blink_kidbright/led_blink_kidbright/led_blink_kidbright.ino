 

void setup() { 
 
     pinMode(17, OUTPUT);   
     pinMode(2, OUTPUT); 
     pinMode(15, OUTPUT); 
     pinMode(12, OUTPUT); 
     pinMode(26, OUTPUT); 
     pinMode(27, OUTPUT); 
     pinMode(18, OUTPUT); 
     pinMode(19, OUTPUT); 
     pinMode(23, OUTPUT);  
 
  Serial.begin(115200);
}

void loop() {
  // เปิด LED
  Serial.println("ON"); 
    digitalWrite(17, HIGH); 
    digitalWrite(2, HIGH); 
    digitalWrite(15, HIGH); 
    digitalWrite(12, HIGH); 
    digitalWrite(26, HIGH); 
    digitalWrite(27, HIGH); 
    digitalWrite(18, HIGH); 
    digitalWrite(19, HIGH); 
    digitalWrite(23, HIGH); 
  delay(3000);

  // ปิด LED 
    digitalWrite(17, LOW); 
    digitalWrite(2, LOW); 
    digitalWrite(15, LOW); 
    digitalWrite(12, LOW); 
    digitalWrite(26, LOW); 
    digitalWrite(27, LOW); 
    digitalWrite(18, LOW); 
    digitalWrite(19, LOW); 
    digitalWrite(23, LOW); 
  delay(3000);
}
