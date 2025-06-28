#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

static const uint8_t PIN_MP3_TX = 5; 
static const uint8_t PIN_MP3_RX = 4;  
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

// Create the Player object
DFRobotDFPlayerMini player;

// Pin Definitions for color sensor (TCS3200 example)
const int S0 = 12;
const int S1 = 13;
const int S2 = 6;
const int S3 = 11;
const int sensorOut = 7;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup() {
  // Init USB serial port for debugging
  Serial.begin(9600);
  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600);

  // Start communication with DFPlayer Mini
  if (player.begin(softwareSerial)) {
    Serial.println("DFPlayer Mini OK");
    player.volume(30); 
  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }

  // Initialize color sensor pins
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Set frequency scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

void loop() {
  Serial.println("Scanning...");
  
  // Read Red
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  redValue = pulseIn(sensorOut, LOW);

  // Read Green
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  greenValue = pulseIn(sensorOut, LOW);

  // Read Blue
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blueValue = pulseIn(sensorOut, LOW);

  // Print the RGB values for debugging
  Serial.print("R = ");
  Serial.print(redValue);
  Serial.print(" G = ");
  Serial.print(greenValue);
  Serial.print(" B = ");
  Serial.println(blueValue);
  
  // Conditions for currency detection
  if ((redValue >= 29 && redValue <= 31) &&
         (greenValue >= 41 && greenValue <= 44) &&
         (blueValue >= 40 && blueValue <= 43)) {
    Serial.println("10Rs note detected");
    player.play(6); // Play 10Rs sound
}


else if ((redValue >= 30 && redValue <= 33) &&
         (greenValue >= 37 && greenValue <= 40) &&
         (blueValue >= 43 && blueValue <= 49)) {
  Serial.println("20Rs note detected");
  player.play(2); // Play sound for 20Rs
}
 
else if ((redValue >= 30 && redValue <= 39) &&
         (greenValue >= 31 && greenValue <= 37) &&
         (blueValue >= 28 && blueValue <= 33)) {
    Serial.println("50Rs note detected");
    player.play(3); // Play 50Rs sound
}

 else if ((redValue >= 31 && redValue <= 36) &&
         (greenValue >= 37 && greenValue <= 43) &&
         (blueValue >= 26 && blueValue <= 30)) {
    Serial.println("100Rs note detected");
    player.play(1); // Play 100Rs sound
}


else if ((redValue >= 24 && redValue <= 26) &&
         (greenValue >= 41 && greenValue <= 43) &&
         (blueValue >= 41 && blueValue <= 44)) {
    Serial.println("200Rs note detected");
    player.play(4); // Play 200Rs sound
}

 else if ((redValue >= 37 && redValue <= 44) &&
    (greenValue >= 43 && greenValue <= 53) &&
    (blueValue >= 40 && blueValue <= 49)) {
  Serial.println("500Rs note detected");
  player.play(5); // Play 500Rs sound
  }
  else {
    Serial.println("Fake note");
  }
  
  delay(3000); // Delay for readability
}
