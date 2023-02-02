import time

a = 0
b = 0
i = 0
for i in range(1000):
    i = i + (a*b)
    if i < 1000:
        a = a + 1
        print ('a의 값', a)
        time.sleep(0.1)
        if a <1000:
            b = b + 2
            print ('b의 값', b)
            time.sleep(0.2)

    print('i의 값 =', i)
    time.sleep(0.5)
    if i > 1000:
        break
    