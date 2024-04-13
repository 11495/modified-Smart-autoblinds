# modified-Smart-autoblinds
The project aims to design, develop, and implement a system that automates the operation of window blinds based on user preferences and environmental factors. The system enhances user convenience, energy efficiency, and comfort by providing an intelligent solution for controlling natural light and privacy within indoor spaces.
// skeletonTech
//Control DC Motor Using Blynk and ESP8266

#define BLYNK_PRINT Serial


#define BLYNK_TEMPLATE_ID "TMPL2zS7XPPiH"
#define BLYNK_TEMPLATE_NAME "AutoWindowBlind"
#define BLYNK_AUTH_TOKEN "iq7R9zpvVFjJ-PDyO7rnP4iem3qehU6d"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "WiFi Username";  // type your wifi name
char pass[] = "WiFi Password";  // type your wifi password
 
int Blind1PWM = D5;
int Blind_Up = D1; //GPIO5
int Blind_Down = D2; //GPIO4

int pinValue1;

BLYNK_WRITE(V1)
{
  int pinValue1 = param.asInt();
  analogWrite(Blind1PWM,pinValue1);
  Blynk.virtualWrite(V1,pinValue1);
  Serial.print("V1 Slider Value is ");
  Serial.println(pinValue1);
}
 

void setup(){
  pinMode(Blind1PWM, OUTPUT);
  pinMode(Blind_Up, OUTPUT);
  pinMode(Blind_Down, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
  
}

void loop(){
  Blynk.run();
 
}
