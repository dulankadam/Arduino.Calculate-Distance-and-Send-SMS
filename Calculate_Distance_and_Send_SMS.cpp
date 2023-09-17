#include <NewPing.h>    // Include the NewPing library for ultrasonic sensor
#include <SoftwareSerial.h> // Include the SoftwareSerial library for GSM module

#define TRIGGER_PIN  12  // Define the pin connected to the trigger of the ultrasonic sensor
#define ECHO_PIN     11  // Define the pin connected to the echo of the ultrasonic sensor

#define GSM_RX_PIN   9   // Define the pin connected to the RX of the GSM module
#define GSM_TX_PIN   8   // Define the pin connected to the TX of the GSM module

#define MAX_DISTANCE 200 // Define the maximum distance in centimeters for the ultrasonic sensor

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Create a NewPing object

SoftwareSerial gsmModule(GSM_RX_PIN, GSM_TX_PIN); // Create a SoftwareSerial object for GSM module

void setup() {
  Serial.begin(9600);      // Initialize serial communication for debugging
  gsmModule.begin(9600);   // Initialize serial communication for GSM module
  
  delay(1000);  // Wait for a moment to let the GSM module initialize

  // Send AT commands to set up GSM module (Ensure it's connected and functional)
  gsmModule.println("AT");
  delay(1000);
  gsmModule.println("AT+CMGF=1");  // Set SMS mode to text
  delay(1000);
}

void loop() {
  delay(500); // Delay for a short time to avoid too many readings
  
  int distance = sonar.ping_cm(); // Get the distance in centimeters
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance < 50) { // Adjust this threshold as needed
    sendSMS("Alert! Object detected at " + String(distance) + " cm."); // Send SMS
    delay(5000); // Delay to avoid sending multiple messages in quick succession
  }
}

void sendSMS(String message) {
  gsmModule.println("AT+CMGS=\"+1234567890\""); // Replace with the recipient's phone number
  delay(1000);
  gsmModule.print(message); // Send the message
  delay(100);
  gsmModule.write(26); // Send Ctrl+Z to indicate end of message
  delay(1000);
}
