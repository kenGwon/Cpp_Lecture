 

import turtle

rad = 100

turtle.seth(-95)
for i in range(2):
    turtle.circle(rad,90)
    turtle.circle(rad//2,90)

turtle.done()

try:
    turtle.bye()
except:
    print("bye")