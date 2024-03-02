import serial as ser

port = "/dev/ttyACM0"

ard = ser.Serial(port, 9600, timeout=5)

# This will read what is in the buffer :D
def recieveData():
    msg = ard.read(ard.in_waiting)
    print(msg)