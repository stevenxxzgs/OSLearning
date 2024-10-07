import turtle

def peano_curve(t, length, level):
    if level == 0:
        return
    t.forward(length)
    t.right(90)
    peano_curve(t, length / 3, level - 1)
    t.left(90)
    t.forward(length)
    t.left(90)
    peano_curve(t, length / 3, level - 1)
    t.right(90)
    t.forward(length)
    peano_curve(t, length / 3, level - 1)
    t.right(90)
    t.forward(length)
    t.right(90)
    peano_curve(t, length / 3, level - 1)
    t.left(90)
    t.forward(length)
    t.left(90)
    peano_curve(t, length / 3, level - 1)
    t.right(90)
    t.forward(length)

# 初始化画布
screen = turtle.Screen()
screen.setup(800, 800)
t = turtle.Turtle()
t.speed(0)

# 设置初始位置
t.penup()
t.goto(-300, 300)
t.pendown()

# 绘制Peano曲线
peano_curve(t, 100, 2)

# 完成绘制
turtle.done()
