import turtle
import random



def turtle_init():
    turtle.setup(width=500, height=800)
def eyesmake():
    eyes = turtle.Turtle()
    eyes.shape("turtle")
    eyes.color("white")

    eyes.begin_fill()
    eyes.penup()
    eyes.goto(50, 120)  # 오른쪽 눈
    eyes.pendown()
    eyes.circle(20)
    eyes.end_fill()

    eyes.begin_fill()
    eyes.penup()
    eyes.goto(-50, 120)  # 왼쪽 눈
    eyes.pendown()
    eyes.circle(20)
    eyes.hideturtle()
    eyes.end_fill()
def headmake():
    head = turtle.Turtle()
    head.shape("turtle")
    head.color("green")

    head.begin_fill()
    head.penup()
    head.goto(100,100)
    head.left(90)
    head.pendown()
    head.circle(100,180)
    head.goto(100,100)
    head.end_fill()

    head.begin_fill()
    head.penup()
    head.goto(80,160)
    head.pendown()
    head.left(145)
    head.forward(100)
    head.circle(10,180)
    head.forward(100)
    head.end_fill()

    head.begin_fill()
    head.penup()
    head.goto(-75,160)
    head.left(250)
    head.pendown()
    head.forward(100)
    head.circle(10, 180)
    head.forward(105)
    head.hideturtle()
    head.end_fill()
def bodymake():
    body = turtle.Turtle()
    body.shape("turtle")
    body.color("green")

    body.begin_fill()
    body.penup()
    body.goto(-100,80)
    body.pendown()
    body.goto(100,80)
    body.goto(100,-150)
    body.goto(-100,-150)
    body.goto(-100,80)
    body.hideturtle()
    body.end_fill()
def armmake():
    arm = turtle.Turtle()
    arm.shape("turtle")
    arm.color("green")

    arm.begin_fill()
    arm.penup()
    arm.goto(-150, 80)
    arm.pendown()
    arm.goto(-120, 80)
    arm.goto(-120, -150)
    arm.goto(-150, -150)
    arm.goto(-150, 80)
    arm.end_fill()

    arm.begin_fill()
    arm.penup()
    arm.goto(150, 80)
    arm.pendown()
    arm.goto(120, 80)
    arm.goto(120, -150)
    arm.goto(150, -150)
    arm.goto(150, 80)
    arm.hideturtle()
    arm.end_fill()

def legmake():
    leg = turtle.Turtle()
    leg.shape("turtle")
    leg.color("green")

    leg.begin_fill()
    leg.penup()
    leg.goto(-100, -150)
    leg.pendown()
    leg.goto(-80, -150)
    leg.goto(-80, -220)
    leg.goto(-100, -220)
    leg.goto(-100, -150)
    leg.end_fill()

    leg.begin_fill()
    leg.penup()
    leg.goto(80, -150)
    leg.pendown()
    leg.goto(100, -150)
    leg.goto(100, -220)
    leg.goto(80, -220)
    leg.goto(80, -150)
    leg.hideturtle()
    leg.end_fill()
    turtle.mainloop()


if __name__ == '__main__':
    headmake()
    eyesmake()
    bodymake()
    armmake()
    legmake()