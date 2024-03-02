import serial as ser
import time

port = "/dev/ttyACM0"

ard = ser.Serial(port, 9600, timeout=5)

# This will read what is in the buffer :D
def recieveData():
    msg = ard.read(ard.in_waiting)
    return msg

def main():
    for i in range(5):
        time.sleep(1)
        print(recieveData())


main()