import serial
import time

port = "/dev/ttyACM0"

ard = serial.Serial(port, 9600, timeout=5)

# This will read what is in the buffer :D
def recieveData():
    while True:
        msg = ard.read(ard.in_waiting)
        msg = msg.decode()
        msg = msg.split(",")
        if msg != ['']:
            return msg



def main():
    for i in range(5):
        print(recieveData())


main()