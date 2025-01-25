#define DistanceEn_Pin 2
 
int i;
long distance;

int distanceValue[4] = {0,0,0,0};

void setup(){
  Serial.begin(9600);
  pinMode(DistanceEn_Pin,OUTPUT);
}
 
void Distance(){
  while(Serial.read() >= 0);
  digitalWrite(DistanceEn_Pin,0);
  while(Serial.available() <= 4);

  distanceValue[0] = Serial.read();
  if(distanceValue[0] == 0xff){
    for(i = 1; i <= 3; i++){
      distanceValue[i] = Serial.read();
    }
   }
 
  digitalWrite(DistanceEn_Pin,1);
 
  distance = distanceValue[1] * 256 + distanceValue[2];
  if((distanceValue[3] == distanceValue[1] + distanceValue[2] - 1)){
    print_range(distance, 10);
  }
}
 
void loop(){
  Distance();
  delay(100);
}

void print_range(long distance, int divide) {
  for(int i = 0; i < 25; i++){
    if((distance / divide) < i){
      Serial.print("#");
    }else{
      Serial.print("-");
    }
  }

  Serial.print(" ");
  Serial.print(distance / divide);
  Serial.print(".");
  Serial.print(distance % divide);
  Serial.println(" cm");
}