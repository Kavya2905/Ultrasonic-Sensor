void setup() {
  pinMode(D2, INPUT); //echo
  pinMode(D1, OUTPUT); //trigger
  pinMode(D3, OUTPUT); //red LED
  Serial.begin(9600);

}

void loop() {
  digitalWrite(D1, HIGH);
  delayMicroseconds(10);
  digitalWrite(D1, LOW);
  delayMicroseconds(10);

  long t = pulseIn(D2,HIGH)/2;  //reads ultrasound waves and counts in microsec
  long d_cm=t/29;
  long d_inch=t/74;
  Serial.print("Distance - ");
  Serial.print(d_cm);
  Serial.print("Centimeters,");
  Serial.print(d_inch);
  Serial.println("Inches.");
  
  //if distance is <20cm led glows-code given below
  
  if(d_cm<20){
    digitalWrite(D3, HIGH); 
  }
  else{
    digitalWrite(D3, LOW);
  }
  delay(2000);

}
