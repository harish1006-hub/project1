#define gas A0
#define fire A4
#define water A2
#define ir1 6
#define ir2 8
#define led1 12
#define led2 13
#define led3 11
int count=0;

void setup()
 {
  Serial.begin(9600);

  pinMode(ir1, INPUT);
  pinMode(ir2,INPUT);
  pinMode(fire,INPUT);
  pinMode(gas,INPUT);
  pinMode(water,INPUT);
  pinMode(led1,OUTPUT); 
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop()
{

int a = digitalRead(6);
int b=digitalRead(8);

 Serial.println(a);
 Serial.println(b);

delay(2000);
{

if(a==0)
{
  count++;
  Serial.print("count");
  Serial.println(count);

}
 if(b==0){
  count--;
  Serial.print("count");
  Serial.println(count);
}
else{
  count==0;

}
int c =analogRead(fire);
Serial.print("fire");
Serial.println(c);
delay(1000);
if(c<=250)
{
  digitalWrite(12,HIGH);

}
else
{
  digitalWrite(12,LOW);
  }
int e=analogRead(gas);
Serial.print("gas");
Serial.println(e);
delay(1000); 

if(e<=205){
  digitalWrite(13,HIGH);
}
else{
  digitalWrite(13,LOW);
}
int d=analogRead(water);
Serial.print("water");
Serial.println(d);
delay(1000);
if(d>=150){
  digitalWrite(11,HIGH);
}
else{
  digitalWrite(11,LOW);
}
}
}
