#define water A0
#define led1 6
#define led2 7
#define led3 8
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(water,INPUT);
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(led3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int a =analogRead(water);
Serial.println("water level is");
Serial.println(a);
delay(1000);

if(a>=0 && a<=200){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
}
else if(a>=250 && a<=600){
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
}
else if(a>=650 && a<=1000){
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,HIGH);
}
else{
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
}

}
