import random
 
f = open("randomNumbers.txt") 

circle_points = 0
square_points = 0

number = 10
# Total Random numbers generated= possible x
# values* possible y values
while number != "":
    # Randomly generated x and y values from a
    # uniform distribution
    # Range of x and y values is -1 to 1
    rand_x = f.readline()
    rand_y = f.readline()
    if rand_y == "":
        break
    rand_x = float(rand_x[:-1])
    rand_y = float(rand_y[:-1])
 
    # Distance between (x, y) from the origin
    origin_dist = rand_x**2 + rand_y**2
 
    # Checking if (x, y) lies inside the circle
    if origin_dist <= 1:
        circle_points += 1
 
    square_points += 1
 
    # Estimating value of pi,
    # pi= 4*(no. of points generated inside the
    # circle)/ (no. of points generated inside the square)
 
##    print(rand_x, rand_y, circle_points, square_points, "-", pi)
# print("\n")

pi = 4 * circle_points / square_points
 
print("Final Estimation of Pi=", pi)