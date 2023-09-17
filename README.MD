To calculate distance using an Arduino, you can use an ultrasonic sensor like the HC-SR04. This sensor measures distance by sending out an ultrasonic sound wave and timing how long it takes for the wave to bounce back.

To send an SMS from an Arduino, you'll need a GSM module (like the SIM800L) and a SIM card with SMS capabilities.

Here's an example code that combines distance measurement and sending an SMS:



Hardware Setup:

Connect the HC-SR04 ultrasonic sensor to the Arduino.
Connect the GSM module to the Arduino.
Insert a SIM card with SMS capabilities into the GSM module.
Install Necessary Libraries:

You'll need libraries for both the ultrasonic sensor and the GSM module. For the ultrasonic sensor, you can use the "NewPing" library. For the GSM module, you'll need a specific library that corresponds to your module (e.g., "SIM800L" library).


Please replace +1234567890 with the recipient's actual phone number (including the country code), and adjust the distance threshold as needed.

This code will measure distance using the ultrasonic sensor and send an SMS if an object is detected within 50 cm. Make sure you have the necessary power supply and wiring connections for both the ultrasonic sensor and GSM module.