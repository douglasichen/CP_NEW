list_len = int(input())
running = []
running_len = 1
number_list = []
see = 0
num = int(input())
running.append(num)
for i in range(0,list_len-1):
    num = int(input())
    number_list.append(num)

for i in number_list:
    print(running)
    print(running_len)
    print(see)
    if running[running_len-1] >= i:
        see += running_len
        running_len += 1
        running.append(i)
    else:
        while running[running_len-1] < i:
            see+=1
            running.pop()
            running_len-=1
            if running_len == 0:
                running_len += 1
                running.append(i)
                break
        else:
            see += running_len
            running.append(i)
            running_len += 1

    
print(see)