void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(D3, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);

}

void loop() {
  int A = random(999); Serial.println(String (A));
  int B = random(999); Serial.println(String (B));
  int C = random(999); Serial.println(String (C));
  int D = random(999); Serial.println(String (D));
  // put your main code here, to run repeatedly:
  if (A < B || A > C){
      digitalWrite(D3, HIGH);
  } 
  else {digitalWrite(D3, LOW);}

  if (C < A & C > B){
    digitalWrite(D5, HIGH);
  } else {digitalWrite(D5, LOW);}

  if (B < C & B > A){
    digitalWrite(D6, HIGH);
  } else {digitalWrite(D6, LOW);}

  if (D < A & D < B & D < C){
    digitalWrite(D5, HIGH);
    delay(200);
    digitalWrite(D5, LOW);
    delay(200);
    digitalWrite(D5, HIGH);
    delay(200);
    digitalWrite(D5, LOW);
    digitalWrite(D3, HIGH);
    delay(200);
    digitalWrite(D3, LOW);
    delay(200);
    digitalWrite(D3, HIGH);
    delay(200);
    digitalWrite(D3, LOW);
    digitalWrite(D6, HIGH);
    delay(200);
    digitalWrite(D6, LOW);
    delay(200);
    digitalWrite(D6, HIGH);
    delay(200);
    digitalWrite(D6, LOW);
  }

delay(2000);


    
  
  
   
      
}
