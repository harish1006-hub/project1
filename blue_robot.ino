#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
bool newMessageReceived = false; 

//motor pins
#define m1 27
#define m2 26
#define m3 25
#define m4 33

void setup() {
  Serial.begin(9600);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(m3,OUTPUT);
  pinMode(m4,OUTPUT);
  SerialBT.begin("DHONI"); // Bluetooth device name
  Serial.println("The device started, now you can pair it with Bluetooth!");

  digitalWrite(m2,LOW);
  digitalWrite(m1,LOW);
  digitalWrite(m3,LOW);
  digitalWrite(m4,LOW);
}
 
void loop() { 
  if (SerialBT.available()) {
    char incomingChar = SerialBT.read();
    Serial.println(incomingChar);
    if(incomingChar == '1'){
      digitalWrite(m1,HIGH);
      digitalWrite(m2,LOW);
      digitalWrite(m3,HIGH);
      digitalWrite(m4,LOW);
      incomingChar=NULL;
    }
    if(incomingChar == '2'){
      digitalWrite(m2,HIGH);
      digitalWrite(m1,LOW);
      digitalWrite(m4,HIGH);
      digitalWrite(m3,LOW);
      incomingChar=NULL;
    }
    if(incomingChar == '3'){
      digitalWrite(m2,HIGH);
      digitalWrite(m1,LOW);
      digitalWrite(m3,HIGH);
      digitalWrite(m4,LOW);
      incomingChar=NULL;
    }
    if(incomingChar == '4'){
      digitalWrite(m1,HIGH);
      digitalWrite(m2,LOW);
      digitalWrite(m4,HIGH);
      digitalWrite(m3,LOW);
      incomingChar=NULL;
    }
    if(incomingChar == '0'){
      digitalWrite(m2,LOW);
      digitalWrite(m1,LOW);
      digitalWrite(m3,LOW);
      digitalWrite(m4,LOW);
      incomingChar=NULL;
    }
  }
  }
