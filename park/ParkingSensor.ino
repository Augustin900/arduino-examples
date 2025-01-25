#define beep_start 100
#define min_distance  5
#define c 0.0343

void setup(){
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(2,HIGH);
  delayMicroseconds(10);
  digitalWrite(2,LOW);
  delayMicroseconds(5);
  digitalWrite(2,HIGH);
  delayMicroseconds(10);

  int Time = pulseIn(3, HIGH) / 2;
  int distance = Time * c;

  Serial.print("distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(50);

// If the distance is less than one  metre
  if (distance < beep_start) { 
    // Emits sounds at intervals proportional  to distance (1 m = 400 ms)
    tone(9, 1000); 
    delay(40);
    //  Below min_distance cm it emits a continuous sound
    if (distance > min_distance)  {
      noTone(9); 
      delay(distance * 4);
    }
  } 
  if(distance <=10 ){
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
  }
  if(distance>10 && distance <=15){
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
  }
  if(distance>15 && distance <=20){
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
  }
  if(distance>20 && distance <=25){
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
  }
  if(distance>25 && distance <=30){
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
  }
  if(distance>30){
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
  }
}