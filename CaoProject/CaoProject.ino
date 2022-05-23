 #define timeSeconds 10
int temp=26;
// Set GPIOs for LED and PIR Motion Sensor
const int motionSensor = 27;



// Checks if motion was detected, sets LED HIGH and starts a timer
void IRAM_ATTR detectsMovement() {
  Serial.println("MOTION DETECTED!!!");

}

void setup() {
  // Serial port for debugging purposes
  Serial.begin(115200);
  pinMode(temp,OUTPUT);
  // PIR Motion Sensor mode INPUT_PULLUP
  pinMode(motionSensor, INPUT_PULLUP);
  // Set motionSensor pin as interrupt, assign interrupt function and set RISING mode
  attachInterrupt(digitalPinToInterrupt(motionSensor), detectsMovement, RISING);

 
}

void loop() {

  // when motion is detected it will on the led light
  int out=digitalRead(motionSensor);
  if(out==HIGH){
    digitalWrite(temp,HIGH);
    delay(10000);
     digitalWrite(temp,LOW);
     //it will be off for 2 sec if it sense motion again it will on the led light
    Serial.println("off");
    delay(2000);
  }

}
