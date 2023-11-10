import turtle

##변수 선언
t = None
t = turtle.Turtle()
t.shape('turtle')
pSize = 10
t.pencolor('springgreen')
t.pensize(pSize)

##몸통 그리기 부분

t.penup()
t.goto(-100,100)
t.pendown()
t.begin_fill()
t.color("springgreen")
for i in range(0,4) :
    t.forward(200)
    t.right(90)

t.end_fill()

#팔 그리기
#왼쪽 팔
t.penup()
t.goto(-160,90)
t.pendown()
t.begin_fill()
t.color("springgreen")
t.setheading(270)
t.forward(160)
t.circle(20,180)
t.forward(160)
t.circle(20,180)
t.end_fill()

#오른쪽 팔
t.penup()
t.goto(120,90)
t.pendown()
t.begin_fill()
t.color("springgreen")
t.setheading(270)
t.forward(160)
t.circle(20,180)
t.forward(160)
t.circle(20,180)
t.end_fill()

##다리 그리기 부분
#왼쪽 다리
t.penup()
t.goto(-65,-100)
t.pendown()
t.begin_fill()
t.color("springgreen")
t.setheading(270)
t.forward(80)
t.circle(20,180)
t.forward(80)
t.end_fill()

#오른쪽 다리
t.penup()
t.goto(25,-100)
t.pendown()
t.begin_fill()
t.color("springgreen")
t.setheading(270)
t.forward(80)
t.circle(20,180)
t.forward(80)
t.end_fill()

##머리 부분
t.penup()
t.goto(-100,130)
t.pendown()
t.begin_fill()
t.color("springgreen")
t.setheading(0)
t.forward(200)
t.setheading(90)
t.circle(100,180)
t.end_fill()

##오른쪽 귀
t.goto(100,130)
t.setheading(90)
t.circle(100,60)
t.right(90)
t.forward(40)
t.penup()

##왼쪽 귀
t.goto(100,130)
t.setheading(90)
t.circle(100,120)
t.pendown()
t.right(90)
t.forward(40)

# 눈
t.pencolor('white')
t.penup()
t.goto(-30,170)
t.pendown()
t.circle(3)
t.penup()
t.goto(40,170)
t.pendown()
t.circle(3)

t.hideturtle()
