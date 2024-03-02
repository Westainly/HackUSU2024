import random

AMOUNT = 2000001
STARTING_RAND = -1
ENDING_RAND = 1

f = open("randomNumbers.txt", "w")

for i in range(AMOUNT):
    f.write(f"{random.uniform(STARTING_RAND, ENDING_RAND)}\n")

f.close()