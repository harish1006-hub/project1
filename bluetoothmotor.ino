String a;
 
void setup() {
pinMode(13,OUTPUT);   
pinMode(12,OUTPUT);   
pinMode(11,OUTPUT);   
pinMode(10,OUTPUT);   
Serial.begin(9600);
 
}
 
void loop() {
while(Serial.available()>0)
{
  a=Serial.readString();
  Serial.println(a);
}
 
if(a =='F'){         
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
}
 
else if(a == 'B'){      
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
  
else if(a == 'L'){      
  digitalWrite(11,HIGH);
}
 
else  if(a == 'R'){      
  digitalWrite(13,HIGH);
}
delay(100);
}
