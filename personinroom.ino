#define ir1 6
#define ir2 8
int count=0;

void setup()
 {
  Serial.begin(9600);

  pinMode(ir1, INPUT);
  pinMode(ir2,INPUT);

}

void loop() 
{

int a = digitalRead(6);
int b=digitalRead(8);

 Serial.println(a);
 Serial.println(b);

delay(2000);
{

if(a==0){
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
}
}