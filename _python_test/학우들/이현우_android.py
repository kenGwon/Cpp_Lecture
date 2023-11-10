import turtle

##변수 선언 부분##
myT = None
myT = turtle.Turtle()
myT.shape('turtle')
pSize = 10
myT.pencolor('springgreen')
myT.pensize(pSize)

##몸통 그리기 부분##

myT.penup()
myT.goto(-100,100)
myT.pendown()
myT.begin_fill()
myT.color("springgreen")
for i in range(0,4) :
    myT.forward(200)
    myT.right(90)

myT.end_fill()
#팔 그리기#
#왼쪽 팔
myT.penup()
myT.goto(-160,90)
myT.pendown()
myT.begin_fill()
myT.color("springgreen")
myT.setheading(270)
myT.forward(160)
myT.circle(20,180)
myT.forward(160)
myT.circle(20,180)
myT.end_fill()

#오른쪽 팔
myT.penup()
myT.goto(120,90)
myT.pendown()
myT.begin_fill()
myT.color("springgreen")
myT.setheading(270)
myT.forward(160)
myT.circle(20,180)
myT.forward(160)
myT.circle(20,180)
myT.end_fill()

##다리 그리기 부분##
#왼쪽 다리
myT.penup()
myT.goto(-65,-100)
myT.pendown()
myT.begin_fill()
myT.color("springgreen")
myT.setheading(270)
myT.forward(80)
myT.circle(20,180)
myT.forward(80)
myT.end_fill()

#오른쪽 다리
myT.penup()
myT.goto(35,-100)
myT.pendown()
myT.begin_fill()
myT.color("springgreen")
myT.setheading(270)
myT.forward(80)
myT.circle(20,180)
myT.forward(80)
myT.end_fill()

##머리 부분##
myT.penup()
myT.goto(-100,130)
myT.pendown()
myT.begin_fill()
myT.color("springgreen")
myT.setheading(0)
myT.forward(200)
myT.setheading(90)
myT.circle(100,180)
myT.end_fill()
myT.goto(100,130)
myT.setheading(90)
myT.circle(100,60)
myT.right(90)
myT.forward(40)
myT.penup()
myT.goto(100,130)
myT.setheading(90)
myT.circle(100,120)
myT.pendown()
myT.right(90)
myT.forward(40)

myT.pencolor('white')
myT.penup()
myT.goto(-40,170)
myT.pendown()
myT.circle(3)
myT.penup()
myT.goto(40,170)
myT.pendown()
myT.circle(3)

myT.hideturtle()

myT.done()
