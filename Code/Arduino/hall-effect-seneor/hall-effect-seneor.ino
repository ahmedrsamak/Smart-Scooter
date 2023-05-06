// Constants
const float wheelCircumference = 1.779;  // Wheel circumference in meters
const int hallSensorPin = 2;             // Hall effect sensor pin

// Variables
volatile unsigned long hallSensorCount = 0;
unsigned long lastTime = 0;
float speed = 0.0;
float distance = 0.0;

void setup() {
  pinMode(hallSensorPin, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(hallSensorPin), hallSensorISR, CHANGE);

  Serial.begin(38400);
}

void loop() {
  unsigned long currentTime = millis();
  unsigned long timeElapsed = currentTime - lastTime;

  if (timeElapsed >= 1000) {
    // Calculate speed in meters per second
    speed = (float(hallSensorCount/2.0) * wheelCircumference) / (float(timeElapsed) / 1000.0);

    // Reset the hall sensor count and update the last time
    hallSensorCount = 0;
    lastTime = currentTime;

    // Calculate distance in meters
    

    // Output speed and distance
    Serial.print("Speed: ");
    Serial.print(speed*3.6);
    Serial.print(" Km/h");

    Serial.print("\tDistance: ");
    Serial.print(distance);
    Serial.println(" m");

  }
}

void hallSensorISR() {
  hallSensorCount++;
  distance += wheelCircumference;
}
