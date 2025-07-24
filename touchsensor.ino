const int touchPin = 2; 
const int ledPin = 9;   
int touchState = 0;     
int brightnessLevel = 0; 

void setup() {
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  touchState = digitalRead(touchPin);
  
  if (touchState == HIGH) { 
    brightnessLevel++;      
    if (brightnessLevel > 3) {
      brightnessLevel = 0;   
    }
    delay(300);   
  }

  if (brightnessLevel == 0) {
    analogWrite(ledPin, 0);   
  } else if (brightnessLevel == 1) {
    analogWrite(ledPin, 85);  
  } else if (brightnessLevel == 2) {
    analogWrite(ledPin, 170); 
  } else if (brightnessLevel == 3) {
    analogWrite(ledPin, 255); 
  }

  delay(100); 
}
