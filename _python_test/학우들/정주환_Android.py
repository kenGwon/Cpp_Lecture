import turtle

swidth, sheight = 500, 500

turtle.title('안드로이드 그리기')
turtle.shape('turtle')
turtle.setup(width = swidth + 50, height = sheight + 50)
turtle.screensize(swidth, sheight)
turtle.pencolor('green')
turtle.color('green')
turtle.speed(100)


## 몸통

turtle.penup()
turtle.goto(-50, -100)
turtle.pendown()
turtle.begin_fill()
turtle.forward(100)
turtle.left(90)
turtle.forward(150)
turtle.left(90)
turtle.forward(100)
turtle.left(90)
turtle.forward(150)
turtle.end_fill()

## 다리
# 왼쪽
turtle.begin_fill()
turtle.left(90)
turtle.forward(20)
turtle.right(90)
turtle.forward(40)
turtle.left(90)
turtle.forward(20)
turtle.left(90)
turtle.forward(40)
turtle.right(90)
turtle.forward(20)
turtle.end_fill()

#오른쪽
turtle.begin_fill()
turtle.right(90)
turtle.forward(40)
turtle.left(90)
turtle.forward(20)
turtle.left(90)
turtle.forward(40)
turtle.end_fill()

# 왼쪽 팔
turtle.penup()
turtle.goto(-55, 50)
turtle.pendown()
turtle.begin_fill()
turtle.left(90)
turtle.forward(20)
turtle.left(90)
turtle.forward(130)
turtle.left(90)
turtle.forward(20)
turtle.left(90)
turtle.forward(130)
turtle.end_fill()

# 오른쪽 팔
turtle.penup()
turtle.goto(55, 50)
turtle.pendown()
turtle.begin_fill()
turtle.right(90)
turtle.forward(20)
turtle.right(90)
turtle.forward(130)
turtle.right(90)
turtle.forward(20)
turtle.right(90)
turtle.forward(130)
turtle.end_fill()

# 머리
turtle.penup()
turtle.goto(-50, 55)
turtle.pendown()
turtle.begin_fill()
turtle.right(90)
turtle.forward(100)
turtle.left(90)
turtle.circle(50, 180)
turtle.end_fill()


# 뿔
turtle.penup()
turtle.goto(-25, 93)
turtle.pendown()
turtle.right(120)
turtle.goto(-29, 110)
turtle.penup()
turtle.goto(25, 93)
turtle.pendown()
turtle.right(120)
turtle.goto(29, 110)

# 눈
turtle.penup()
turtle.goto(-25, 80)
turtle.pendown()
turtle.color('white')
turtle.begin_fill()
turtle.circle(4)
turtle.end_fill()
turtle.penup()
turtle.goto(25, 80)
turtle.pendown()
turtle.begin_fill()
turtle.circle(4)
turtle.end_fill()

turtle.penup()
turtle.home()
turtle.pendown()



turtle.done()
