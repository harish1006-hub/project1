#define trigger 6
#define echo 8
void setup()
 {
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
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
}


