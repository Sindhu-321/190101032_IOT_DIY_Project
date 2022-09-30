
#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space

#include <CayenneMQTTESP8266.h>

int SensorPin = 4;
int LEDOutputPin = 5;


//Make a wifi name and password as access point

char wifissid[] = "Oneplus10RT";  // your SSID

char wifiPassword[] = "62eea6c3"; // YOUR WIFI PASSWORD


// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.

char user_name[] = "f5bc39b0-409d-11ed-baf6-35fab7fd0ac8"; // YOURS

char password[] = "ee9cfea7d5213330e3cebebfd2a3bcbd1e5c7e76"; // YOURS

char client_ID[] = "febe9760-409d-11ed-baf6-35fab7fd0ac8";// YOURS

int SensorValue;

void setup()

{

  pinMode(LEDOutputPin, OUTPUT);
  pinMode(SensorPin, INPUT);

  Serial.begin(9600);

  Serial.print("Setup");

  Cayenne.begin(user_name, password, client_ID, wifissid, wifiPassword);

}


void loop()

{

  //Run Cayenne Functions

  Cayenne.loop();

}


CAYENNE_OUT(V0){

    SensorValue = digitalRead(SensorPin);

  Serial.print("IRSensorValue : ");

  Serial.println(SensorValue);
  delay(1000);

  if (SensorValue==HIGH){ // HIGH MEANS Object Detected
    digitalWrite(LEDOutputPin, HIGH);
    delay(1000);
  }
  else
  {
    digitalWrite(LEDOutputPin, LOW);
    delay(1000);
  }

  //Write to Cayenne Dashboard`
  Cayenne.virtualWrite(V0, SensorValue);
}
