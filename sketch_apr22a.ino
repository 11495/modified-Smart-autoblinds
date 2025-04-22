#include <ESP8266WiFi.h>
#include <Servo.h>
#include <Blink.h>

const int LDR_PIN_INSIDE = A0;   // LDR for inside light
const int LDR_PIN_OUTSIDE = A1;  // LDR for outside light
const int IR_PIN = D2;           // IR sensor for motion detection
const int SERVO_PIN = D3;        // Servo motor to control blinds

Servo myservo;

int insideLightLevel = 0;
int outsideLightLevel = 0;
int motionDetected = 0;

const int thresholdLight = 300;  // Light threshold for adjusting blinds

// Blink app credentials (replace with your own)
const char* authToken = "your_Blink_Auth_Token";
const char* deviceName = "SmartAutoBlinds";

// Replace with your Wi-Fi credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

Blink blink(authToken, deviceName);

void setup() {
  Serial.begin(115200);
  pinMode(LDR_PIN_INSIDE, INPUT);
  pinMode(LDR_PIN_OUTSIDE, INPUT);
  pinMode(IR_PIN, INPUT);
  myservo.attach(SERVO_PIN);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Connect to Blink cloud
  blink.begin();
}

void loop() {
  insideLightLevel = analogRead(LDR_PIN_INSIDE);
  outsideLightLevel = analogRead(LDR_PIN_OUTSIDE);
  motionDetected = digitalRead(IR_PIN);

  // Adjust blinds based on light levels
  if (insideLightLevel < thresholdLight && outsideLightLevel > thresholdLight) {
    openBlinds();
  } else if (insideLightLevel >= thresholdLight || outsideLightLevel <= thresholdLight) {
    closeBlinds();
  }

  // Close blinds if motion is detected outside
  if (motionDetected == HIGH) {
    closeBlinds();
  }

  // Control blinds remotely using Blink app
  if (blink.buttonPressed(1)) { // If the first button in the Blink app is pressed
    openBlinds();
  }
  if (blink.buttonPressed(2)) { // If the second button in the Blink app is pressed
    closeBlinds();
  }

  blink.run();  // Keep Blink app running
  delay(1000);  // Update every second
}

void openBlinds() {
  myservo.write(90);  // Adjust the angle to open blinds
  Serial.println("Blinds opened");
}

void closeBlinds() {
  myservo.write(0);  // Adjust the angle to close blinds
  Serial.println("Blinds closed");
}
