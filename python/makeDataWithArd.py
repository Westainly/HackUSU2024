import serial
import time
import sys

f = open("randomNumbers.txt", "w")

port = "/dev/ttyACM0"

ard = serial.Serial(port, 9600, timeout=5)

# This will read what is in the buffer :D
def recieveData():
    try:
        while True:
            msg = ard.read(ard.in_waiting)
            msg = msg.decode()
            msg = msg.split(",")
            if msg != ['']:
                return msg
    except:
        recieveData()

def returnNumber(data):
    if data is None:
        return None
    for num in data:
        if num != "":
            return num
    return None
def main():
    for i in range(1000):
        data = recieveData()
        for num in data:
            if num != "":
                num = int(num) / 2
                num = int(num % 3)
                f.write(f"{num}\n")
        # f.write(f"{data}\n")

def rockPaperScisors():
    userInput = input("Rock Paper or Scissors (r,p,s): ".lower())
    while userInput not in ["r","p","s"]:
        userInput = input("Please do a propper input (r,p,s): ".lower())
    if userInput == "r":
        userInput = 0
    elif userInput == "p":
        userInput = 1
    elif userInput == "s":
        userInput = 2
    while True:
        data = recieveData()
        number = returnNumber(data)
        if number is not None:
            break
    number = int(int(number) / 2) % 3

    if number == 0:
        print("Computer chose ROCK!")
        print("""
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
""")
    elif number == 1:
        print("Computer chose Paper!")
        print("""
     ___________
---'    ________)____
           __________)
          ___________)
         ___________)
---.______________)
""")
    elif number == 2:
        print("Computer chose Scissors")
        print("""
    _______
---'   ____)________
          __________)
       ______________)
      (____)
---.__(___)
""")
    else:
        print(number)

    if userInput == number:
        print("It was a tie")
    elif userInput == 0:
        if number == 1:
            print("Computer won!")
        elif number == 2:
            print("You won!")
    elif userInput == 1:
        if number == 2:
            print("Computer won!")
        elif number == 0:
            print("You won!")
    elif userInput == 2:
        if number == 0:
            print("Computer won!")
        elif number == 1:
            print("You won!")
    else:
        print("Something went wrong...")

rockPaperScisors()

f.close