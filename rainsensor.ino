#define rain A0
#define led 6
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(rain,INPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
int b =analogRead(rain);
Serial.println("rain");
Serial.println(b);
delay(1000);
if(b<=500)
{
  analogWrite(led,HIGH);

}
else
{
  analogWrite(led,LOW);
  }
}


