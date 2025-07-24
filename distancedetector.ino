#define trigger 6
#define echo 8
#define led1 11
#define led2 12
#define led3 13
void setup()
 {
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop() 
{
long distance;
long duration;
digitalWrite(trigger,HIGH);
delay(1000);
digitalWrite(trigger,LOW);
duration=pulseIn(echo,HIGH);
distance=duration*0.0343/2;
Serial.println("distance in cm");
Serial.println(distance);
delay(1000);
if(distance>=4 && distance<=9)
{
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}
else if(distance>=10 && distance<=99)
{
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
}
else if(distance>=100)
{
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
}
else
{
  digitalWrite(11,LOW);

}
}

