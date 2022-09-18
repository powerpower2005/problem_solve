#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int> alpha;

vector<int> solution(string msg) {
    vector<int> answer;
    int idx = 27;
    alpha["A"]=1;
    alpha["B"]=2;
    alpha["C"]=3;
    alpha["D"]=4;
    alpha["E"]=5;
    alpha["F"]=6;
    alpha["G"]=7;
    alpha["H"]=8;
    alpha["I"]=9;
    alpha["J"]=10;
    alpha["K"]=11;
    alpha["L"]=12;
    alpha["M"]=13;
    alpha["N"]=14;
    alpha["O"]=15;
    alpha["P"]=16;
    alpha["Q"]=17;
    alpha["R"]=18;
    alpha["S"]=19;
    alpha["T"]=20;
    alpha["U"]=21;
    alpha["V"]=22;
    alpha["W"]=23;
    alpha["X"]=24;
    alpha["Y"]=25;
    alpha["Z"]=26;
    string temp = msg;
    
    while(!temp.empty()){
        //2단계 일치하는 가장 긴 문자열 탐색
        for(int i = temp.size(); i>=1; i--){
            string comp = temp.substr(0,i);
            //가장 긴 문자열 w 찾음
            if(alpha.count(comp) == 1){
                //색인 출력
                answer.push_back(alpha[comp]);
                //w를 뺀 문자열 업데이트
                temp = temp.substr(i);
                
                //비어있지 않다면 4단계 실행
                if(temp.empty())break;
                alpha[comp+temp[0]] = idx++;
                //다시 2단계
                break;
            }
            
        }
    }

    return answer;
}