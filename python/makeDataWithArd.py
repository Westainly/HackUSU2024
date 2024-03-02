import serial
import time

f = open("randomNumbers.txt", "w")

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
    for i in range(1000):
        data = recieveData()
        for num in data:
            if num != "":
                f.write(f"{num}\n")



main()