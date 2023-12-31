import turtle

swidth, sheight, pSize = 300, 300, 3

turtle.title('안드로이드')
turtle.shape('turtle')
turtle.pensize(pSize)
turtle.setup(width = swidth + 30, height = sheight + 30)
turtle.screensize(swidth, sheight)
turtle.color("green")
turtle.begin_fill()
turtle.penup()

turtle.goto(40,-30)
turtle.pendown()
turtle.goto(40,40)
turtle.goto(-40,40)
turtle.goto(-40,-30)
turtle.left(270)
turtle.circle(10,90)
turtle.goto(-25,-40)
turtle.goto(-25,-70)
turtle.left(270)
turtle.circle(10,180)
turtle.goto(-5,-40)
turtle.goto(5,-40)
turtle.goto(5,-70)
turtle.left(180)
turtle.circle(10,180)
turtle.goto(25,-40)
turtle.goto(30,-40)
turtle.left(270)
turtle.circle(10,90)
turtle.end_fill()
turtle.penup()
turtle.goto(45,-25)
turtle.pendown()
turtle.begin_fill()
turtle.goto(45,25)
turtle.left(180)
turtle.circle(10,-180)
turtle.goto(65,-25)
turtle.circle(10,-180)
turtle.penup()
turtle.goto(-45,-25)
turtle.pendown()
turtle.goto(-45,25)
turtle.left(180)
turtle.circle(10,180)
turtle.goto(-65,-25)
turtle.circle(10,180)
turtle.end_fill()
turtle.penup()
turtle.goto(-40,45)
turtle.pendown()


turtle.begin_fill()
turtle.goto(40,45)
turtle.circle(40,180)
turtle.end_fill()

turtle.penup()
turtle.goto(-15,70)
turtle.pendown()
turtle.color("white")
turtle.begin_fill()
turtle.circle(2)
turtle.end_fill()
turtle.penup()
turtle.goto(15,70)
turtle.pendown()
turtle.begin_fill()
turtle.circle(2)
turtle.end_fill()
turtle.penup()

turtle.color("green")
turtle.goto(16,84)
turtle.pendown()
turtle.goto(25,100)
turtle.pendown()
turtle.penup()
turtle.goto(-16,84)
turtle.pendown()
turtle.goto(-25,100)


turtle.done()
