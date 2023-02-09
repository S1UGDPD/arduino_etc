/*
   This program is a parsing routine of TF02 product standard output protocol on Arduino.
   The format of data package is 0x59 0x59 Dist_L Dist_H Strength_L Strength_H Sequence_L Sequence_H CheckSum_L
   Refer to the product specification for detailed description.
   For Arduino board with one serial port, use software to virtualize serial port’s functions: such as UNO board.

   red +5V
   black GND
   green TX
   white RX
*/


//#include<SoftwareSerial.h>// soft serial port header file
//SoftwareSerial Serial1(2, 3); // define the soft serial port as Serial1, pin2 as RX, and pin3 as TX

HardwareSerial Serial2(PA3, PA2);

int dist;                   // LiDAR actually measured distance value
int strength;               // LiDAR signal strength
int check;                  // check numerical value storage
int i;
int uart[9];                // store data measured by LiDAR
const int HEADER = 0x59;    // data package frame header

void setup() {
  pinMode(PC13, OUTPUT);
  Serial.begin(115200);       //set the Baud rate of Arduino and computer serial port
  Serial2.begin(115200);    //set the Baud rate of LiDAR and Arduino serial port
}

void loop() {
  digitalWrite(PC13, LOW);
  //check whether the serial port has data input
  if (Serial2.available()) {

    // determine data package frame header 0x59
    if (Serial2.read() == HEADER) {
      uart[0] = HEADER;

      //determine data package frame header 0x59
      if (Serial2.read() == HEADER) {
        uart[1] = HEADER;

        // store data to array
        for (i = 2; i < 9; i++) {
          uart[i] = Serial2.read();
        }
        check = uart[0] + uart[1] + uart[2] + uart[3] + uart[4] + uart[5] + uart[6] + uart[7];

        // check the received data as per protocols
        if (uart[8] == (check & 0xff)) {
          dist = uart[2] + uart[3] * 256;           // calculate distance value
          strength = uart[4] + uart[5] * 256;       // calculate signal strength value
        }
      }
    }
  }
  digitalWrite(PC13, HIGH);
  //Serial.print("dist = ");
  Serial.print(dist);                       // output LiDAR tests distance value
  Serial.print(' ');
  //Serial.print("strength = ");
  Serial.print(strength);                   // output signal strength value
  Serial.print('\n');
  delay(500);
}
