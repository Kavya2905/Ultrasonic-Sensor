void setup() {
  pinMode(D1, INPUT); //echo
  pinMode(D2, OUTPUT); //trigger
  Serial.begin(9600);

}

void loop() {
  digitalWrite(D2, HIGH);
  delayMicroseconds(10);
  digitalWrite(D2, LOW);
  delayMicroseconds(10);

  long t = pulseIn(D1,HIGH)/2;  //reads ultrasound waves and counts in microsec
  long d_cm=t/29;
  long d_inch=t/74;
  Serial.print("Distance - ");
  Serial.print(d_cm);
  Serial.print("Centimeters,");
  Serial.print(d_inch);
  Serial.println("Inches.");
  
  //if distance is <20cm led glows-code given below
  
  if(d_cm<20){
    digitalWrite(D3, LOW); 
  }
  else{
    digitalWrite(D3, HIGH);
  }
  delay(2000);

}
