#include <string>
#include <sstream>
#include <iostream>
#include <vector>


using namespace std;

int solution(string dartResult) {
    int answer = 0;
    
    vector<int> result;
    int idx = 0;
    for(int i = 0; i<dartResult.size(); i++){
        char c = dartResult[i];
        int tmp;
        if(result.empty()){
            tmp = 0;    
        }else{
            tmp = result.back();
        }
        if(c >= '0' && c <= '9'){
            //idx 번째 시행
            tmp = c-'0';
            //10점이라면, 뒤에 숫자가 더있다면 (i+1 범위제한 안걸어도 되는 이유 : 무조건 S,D,T 가 숫자 뒤에 존재)
            if(dartResult[i+1] >= '0' && dartResult[i+1] <= '9'){
                string x;
                x += c;
                x += dartResult[i+1];
                tmp = stoi(x);
                i++; //해당 문자생략
            }
            result.push_back(tmp);
            idx++; //다음 index를 가리키고 있음.
        }else if(c == 'S' || c == 'D' || c =='T'){
            if(c == 'D'){
                result[idx-1] = tmp * tmp;
            }
            if(c == 'T'){
                result[idx-1] = tmp * tmp * tmp;
            }
        }else{
            if(c == '*'){
                int tmpidx = idx - 1;
                for(int i = 0; i<2; i++){
                    if(tmpidx < 0)break;
                    result[tmpidx--] *= 2;
                }
                
            }
            if(c == '#'){
                int tmpidx  = idx - 1;
                result[tmpidx] *= -1;
            }
        }
    }

    for(int x : result){
        answer += x;
    }
    
    return answer;
}