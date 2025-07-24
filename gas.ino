#define gas A0
void setup()
 {
  Serial.begin(9600);

  pinMode(gas,INPUT);
}
void loop() 
{
int a = analogRead(gas);
 Serial.println("gas");
 Serial.println(a);
delay(1000);
}