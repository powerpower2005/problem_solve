import re
p = re.compile('(\d+)([SDT])([*#]?)') 


bonus = {'S' : 1, 'D' : 2, 'T' : 3} #딕셔너리로 설정
option = {'' : 1, '*' : 2, '#' : -1}



def solution(dartResult):
    answer = 0
    result = p.findall(dartResult) #정규표현식으로 나눔
    
    for i in range(len(result)): #3번 반복
        if result[i][2] == '*' and i > 0: #*이 등장했을 때 앞선 결과 반영
            result[i-1] *= 2
            
        result[i] = int(result[i][0]) ** bonus[result[i][1]] * option[result[i][2]]


    return sum(result)