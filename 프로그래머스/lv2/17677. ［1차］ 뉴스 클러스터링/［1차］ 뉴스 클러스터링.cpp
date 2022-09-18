#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    string sstr1 = "";
    string sstr2 = "";
    //대문자 소문자 구분 x
    for(char c : str1){
        sstr1 += tolower(c);
    }
    for(char c : str2){
        sstr2 += tolower(c);
    }
    
    vector<string> vec1;
    //2개씩 짝지어서 추가.
    for(int i = 0; i<sstr1.size()-1; i++){
        string tmp = sstr1.substr(i,2);
        if(!isalpha(tmp[0]) || !isalpha(tmp[1]))continue;
        vec1.push_back(tmp);
    }
    vector<string> vec2;
    for(int i = 0; i<sstr2.size()-1; i++){
        string tmp = sstr2.substr(i,2);
        if(!isalpha(tmp[0]) || !isalpha(tmp[1]))continue;
        vec2.push_back(tmp);
    }
    
    //교집합 구하기
    vector<string> common;
    for(auto it1 = vec1.begin(); it1 != vec1.end(); it1++){
        auto it2 = find(vec2.begin(), vec2.end(), *it1);
        if(it2 != vec2.end()){
            common.push_back(*it2);
            //B에서는 B-A가 되는 것임
            vec2.erase(it2);
        }
    }
    // A + B-A = A U B
    int uni = vec1.size() + vec2.size();
    // A 교집합 B
    int com = common.size();

    double x = (double)com / uni;
    cout << x ;
    if(uni == 0 && com == 0)x=1; 

    answer = (x * 65536);
    
    
    
    
    return answer;
}