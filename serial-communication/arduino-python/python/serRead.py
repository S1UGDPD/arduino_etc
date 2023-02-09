import serial

arduino = serial.Serial("COM5", 115200, timeout=0)

while True:
    data = arduino.readline()
    data_sensor = data.decode('utf8')
    print(data_sensor)