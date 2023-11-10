import turtle as t


##변수 선언##
##함수 선언##
def box(pos_x,pos_y,x,y,color): #goto()로 전달될 매개변수 pos_x,pos_y 추가.
    t.penup()                #box 함수 안으로 이동
    t.goto(pos_x,pos_y)      #box 함수 안으로 이동, 좌표는 매개변수로 치환.
    t.pendown()              #box 함수 안으로 이동
    t.speed('fastest')
    t.color(color)
    t.begin_fill()
    t.fd(x)
    t.left(90)
    t.fd(y)
    t.left(90)
    t.fd(x)
    t.left(90)
    t.fd(y)
    t.end_fill()
    
def draw(angle, box):
     t.right(angle)
     box()

def arc(pos_x,pos_y,x,y,color):
    t.penup()
    t.goto(pos_x,pos_y)
    t.pendown()
    t.speed('fastest')
    t.color(color)
    t.begin_fill()
    t.circle(x,y)
    t.end_fill()
    
##메인 코드##
box(10,10,100,150,'green') #몸틍  

box(-30,160,140,30,'green') #왼팔
box(150,160,30,140,'green')  #오른팔

box(40,-50,50,30,'green')

box(80,-50,30,50,'green')

arc(9,170,50,-180,'green') #얼굴 

arc(90,200,5,360,'white') #오른눈 
arc(40,200,5,360,'white') #왼눈

t.right(50)

box(30,210,5,30,'green')


t.right(-20)

box(85,210,5,30,'green')

t.done()

ellipc
