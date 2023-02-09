import serial

arduino = serial.Serial("COM10", 115200, timeout=2)

while True:
    for i in range(11):
        line = arduino.readline()
        if line:
            string = line.decode()
            num = float(string)
            print(num)