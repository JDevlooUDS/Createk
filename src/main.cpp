#include <Arduino.h>
#include "HUSKYLENS.h"

#define ID_PERSON  1
HUSKYLENS  huskyLens;

void setup() {
  Serial.begin(9600);
  Wire.begin(21,22);

  while (!huskyLens.begin(Wire))
    {
        Serial.println(F("Begin failed!"));
        delay(100);
    }

    huskyLens.writeAlgorithm(ALGORITHM_OBJECT_RECOGNITION);
}

void loop() {
  if (!huskyLens.request()) Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
  static char text[100];
  huskyLens.request();
  while (huskyLens.available()) {
    HUSKYLENSResult result = huskyLens.read();
    if (result.ID == ID_PERSON) {
      //envoyer l'information à l'autre esp
    }
    delay(1000);
  }
}


