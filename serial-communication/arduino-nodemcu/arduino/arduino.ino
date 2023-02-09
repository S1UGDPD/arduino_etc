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
  //  // send integer
  //  Serial.println(10);

  windSpeed.value.sensorValue = 27.53;

//    // send each byte using Serial.print()
//    for (int i = 0; i < union_size; i++) {
//      Serial.print(windSpeed.byteArray[i]);
//    }

  // send as packet using serial write
  Serial.write(windSpeed.byteArray, sizeof(windSpeed.byteArray));

  delay(1000);
}
