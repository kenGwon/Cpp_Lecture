import turtle

def draw_ears(Android, position, times):
    ear_distance = 50

    # 귀 그리기 위해 펜 굵기 엄청 굵게
    stored_pensize = Android.pensize()
    Android.pensize((stored_pensize + 7) * times)

    # 왼쪽귀 시작 좌표 지정 & 그리기
    Android.penup()
    Android.goto((position[0] - 10 - ear_distance) * times, (position[1] + 205) * times)
    Android.pendown()
    Android.seth(135)
    Android.forward(30 * times)

    # 오른쪽귀 시작 좌표 지정 & 그리기
    Android.penup()
    Android.goto((position[0] + 10 + ear_distance) * times, (position[1] + 205) * times)
    Android.pendown()
    Android.seth(45)
    Android.forward(30 * times)

    # 펜사이즈 원상복귀 & seth값 원상복귀
    Android.pensize(stored_pensize)
    Android.seth(0)
    return


def draw_head(Android, position, times):
    # 시작 좌표 지정
    Android.penup()
    Android.goto((position[0] + 0) * times, (position[1] + 20) * times)

    # 그리기
    Android.penup()
    Android.circle(100 * times, 90)

    Android.fillcolor("#81c147")
    Android.begin_fill()
    Android.pendown()
    Android.circle(100 * times, 180)
    Android.end_fill()

    position = Android.position()
    cur_x = int(position[0])
    cur_y = int(position[1])
    Android.goto(cur_x + 200*times, cur_y)
    return


def draw_eyes(Android, position, times):    
    eye_distance = 50

    # 왼쪽눈 시작 좌표 지정 & 그리기
    Android.penup()
    Android.goto((position[0] - 15 - eye_distance) * times, (position[1] + 150) * times)
    Android.fillcolor("white")
    Android.begin_fill()
    Android.pendown()
    Android.circle(15 * times)
    Android.end_fill()

    # 오른쪽눈 시작 좌표 지정 & 그리기
    Android.penup()
    Android.goto((position[0] - 15 + eye_distance) * times, (position[1] + 150) * times)
    Android.fillcolor("white")
    Android.begin_fill()
    Android.pendown()
    Android.circle(15 * times)
    Android.end_fill()
    return


def draw_body(Android, position, times):
    # 시작 좌표 지정
    Android.penup()
    Android.goto((position[0] + 100) * times, (position[1] + 100) * times)

    # 그리기
    Android.fillcolor("#81c147")
    Android.begin_fill()
    Android.pendown()
    for i in range(4):
        Android.forward(200 * times)
        Android.right(90)
    Android.end_fill()
    return


def draw_arms(Android, position, times):
    arm_distance = 120

    # 왼쪽팔 시작 좌표 지정
    Android.penup()
    Android.goto((position[0] + 0 - arm_distance) * times, (position[1] + 100) * times)
    
    # 왼쪽팔 그리기
    Android.fillcolor("#81c147")
    Android.begin_fill()
    Android.pendown()
    for i in range(2):
        Android.forward(180 * times)
        Android.right(90)
        Android.forward(30 * times)
        Android.right(90)
    Android.end_fill()
    
    # 오른쪽팔 시작 좌표 지정
    Android.penup()
    Android.goto((position[0] + 0 + arm_distance) * times, (position[1] + 100) * times)
    
    # 오른쪽팔 그리기
    Android.fillcolor("#81c147")
    Android.begin_fill()
    Android.pendown()
    for i in range(2):
        Android.forward(180 * times)
        Android.left(90)
        Android.forward(30 * times)
        Android.left(90)
    Android.end_fill()
    return 


def draw_legs(Android, position, times):
    leg_distance = 40

    # 왼쪽다리 시작 좌표 지정
    Android.penup()
    Android.goto((position[0] + 0 - leg_distance) * times, (position[1] - 110) * times)
    
    # 왼쪽다리 그리기
    Android.fillcolor("#81c147")
    Android.begin_fill()
    Android.pendown()
    for i in range(2):
        Android.forward(110 * times)
        Android.right(90)
        Android.forward(30 * times)
        Android.right(90)
    Android.end_fill()
    
    # 오른쪽다리 시작 좌표 지정
    Android.penup()
    Android.goto((position[0] + 0 + leg_distance) * times, (position[1] - 110) * times)
    
    # 오른쪽다리 그리기
    Android.fillcolor("#81c147")
    Android.begin_fill()
    Android.pendown()
    for i in range(2):
        Android.forward(110 * times)
        Android.left(90)
        Android.forward(30 * times)
        Android.left(90)
    Android.end_fill()
    return 


def show_android(Android, position, times = 1, draw_speed = 10, draw_color = "#81c147", pen_size = 5):
    swidth, sheight = 700 * times, 700 * times
    turtle.setup(width = swidth, height = sheight)
    turtle.screensize(swidth, sheight)

    Android.hideturtle()
    Android.speed(draw_speed)
    Android.pencolor(draw_color)
    Android.pensize(pen_size)
    draw_ears(Android, position, times)
    draw_head(Android, position, times)
    draw_eyes(Android, position, times)
    draw_body(Android, position, times)
    draw_arms(Android, position, times)
    draw_legs(Android, position, times)
    return


android_position = (0, 0) # 안드로이드 초기 위치 지정
size_times = 1.3 # 안드로이드 그리기 배율 조정

if __name__ == "__main__":
    myAndroid = turtle.Turtle()
    show_android(myAndroid, android_position, size_times)
    
    turtle.done()

    try:
        turtle.bye()
    except:
        print("bye")
