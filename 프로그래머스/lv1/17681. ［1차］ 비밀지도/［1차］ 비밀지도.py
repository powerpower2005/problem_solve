def func(n,z):
    s = ''
    while(True):
        a = n%2
        s += str(a)
        b = n//2
        if b == 1 or b == 0:
            s += str(b)
            break
        else:
            n=b
    s = s[::-1].zfill(z)
    return list(map(int, s))
    
def solution(n, arr1, arr2):
    answer = []
    column = 0
    for i in arr1:
        line = func(i,n)
        answer.append(line)
        
    column = 0
    for j in arr2:
        line = func(j,n)
        print(line)
        for k in range(n):
            if answer[column][k] == line[k] == 0:
                answer[column][k] = ' '
            else:
                answer[column][k] = '#'
        column += 1
    lst = []
    for i in answer:
        lst.append(''.join(i))
    return lst