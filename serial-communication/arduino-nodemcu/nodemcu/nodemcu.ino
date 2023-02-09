typedef struct dat {
  float sensorValue;
};

const int union_size = sizeof(dat);

typedef union btPacket {
  dat value;
  byte byteArray[union_size];
};

btPacket windSpeed;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  //  // receive integer
  //  if (Serial.available() > 0) {
  //    Serial.write(Serial.read());
  //  }

//    // receive each byte using Serial.read()
//    if (Serial.available() > 0) {
//      for (int i = 0; i < union_size; i++) {
//        windSpeed.byteArray[i] = Serial.read();
//      }
//    }

  // receive packet using Serial.readBytes(buffer, length)
  if (Serial.available() > 0) {
    Serial.readBytes(windSpeed.byteArray, sizeof(windSpeed.byteArray));
  }

  Serial.println(windSpeed.value.sensorValue);
}
