#define water 4
#define led 7
void setup() {

 Serial.begin(9600);
 pinMode(water,INPUT);
 pinMode(led,OUTPUT);
}
void loop() {
int b =digitalRead(water);
Serial.println("water level is");
Serial.println(b);
delay(1000);
if(b>=1){
  digitalWrite(7,HIGH);
}
else{
  digitalWrite(7,LOW);
}
}
