sum = 0
for x in range(101):
    sum += x
print(sum)


sum = 0
for x in range(2, 101, 2):
    sum += x
print(sum)

"""
猜数字游戏

Version: 0.1
Author: 骆昊
"""
import random

answer = random.randint(1, 100)
counter = 0
while True:
    counter += 1
    number = int(input('请输入: '))
    if number < answer:
        print('大一点')
    elif number > answer:
        print('小一点')
    else:
        print('恭喜你猜对了!')
        break
print('你总共猜了%d次' % counter)
if counter > 7:
    print('你的智商余额明显不足')