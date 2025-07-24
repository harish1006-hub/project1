#define fire A3
#define led 7
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(fire,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int b =analogRead(fire);
Serial.println("fire");
Serial.println(b);
delay(1000);
if(b==1)
{
  digitalWrite(led,HIGH);

}
else
{
  digitalWrite(led,LOW);
  }
}


