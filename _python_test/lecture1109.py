# """
# 여러줄 주석입니다.
# """
# # 주석입니다.

# print("hello, world")

# a = 100
# print(type(a))

# def sum(a, b):
#     return a + b

# b = 3.5

# print(sum(a, b))

# c = "100"
# d = "50"


# print(c+d)
# print(int(c)+int(d))

# e = input()
# print(f"입력한 수는 {e}입니다.")


# import math
import turtle
import random

# turtle.shape('turtle')

# turtle.forward(200)
# turtle.right(90)
# turtle.forward(200)
# turtle.right(90)
# turtle.forward(200)
# turtle.right(90)
# turtle.forward(200)

# turtle.done()


# myTurtle = None
# myTurtle = turtle.Turtle()
# myTurtle.shape('turtle')

# for i in range(0, 4):
#     myTurtle.forward(200)
#     myTurtle.right(90)


def screenLeftClick(x, y):
    global r, g, b
    turtle.pencolor((r, g, b))
    turtle.pendown() # 펜을 내렸다는 것은 종이에 대고 그리기 시작한다는 의미이다.
    turtle.goto(x, y)

def screenRightClick(x, y):
    turtle.penup() # 펜을 올렸다는 것은 이동해도 그리지 않겠다는 의미이다.
    turtle.goto(x, y)

def screenMidClick(x, y):
    global r, g, b
    tSize = random.randrange(1, 10)
    turtle.shapesize(tSize)
    r = random.random()
    g = random.random()
    b = random.random()


# pSize = 10
# r, g, b = 0.0, 0.0, 0.0


# turtle.title('거북이로 그림 그리기')
# turtle.shape('turtle')
# turtle.pensize(pSize)

# turtle.onscreenclick(screenLeftClick, 1)
# turtle.onscreenclick(screenMidClick, 2)
# turtle.onscreenclick(screenRightClick, 3)

# turtle.done()

# boolVar = True
# intVar = 0
# floatVar = 0.0
# strVar = ""
# print(type(strVar))
# strVar = True
# print(type(strVar))


rad = 100

turtle.seth(-45)
turtle.circle(rad,180)
# for i in range(2):
    # turtle.circle(rad//2,90)

