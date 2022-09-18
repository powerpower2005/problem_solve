#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

string func(int x){
    if(x>= 10){
        return to_string(x);
    }else{
        return "0" + to_string(x);
    }
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    deque<int> people;
    
    for(auto t : timetable){
        stringstream ss(t);
        string hh,mm;
        int time = 0;
        getline(ss, hh, ':');
        getline(ss, mm);
        int ht,mt;
        ht = stoi(hh);
        mt = stoi(mm);
        time = 60*ht + mt;
        people.push_back(time);
        
    }
    
    //사람들을 시간순서대로 정렬
    sort(people.begin(), people.end());
    
    //버스시간
    int start = 60 * 9;
    int count = n;
    int interval = t;
    int idx = 0;
    
    //마지막에 탄 사람 시간
    int lastTime = 0;
    int lastBusPeople = 0;
    int lastBusTime = 0;
    
    //버스태우기 (n회 태움)
    while(n--){
        //버스시간
        int now = start + (idx++)*interval;
        //버스 인원
        int busPeople = 0;
        //비어있으면 버스를 태우지 않음.
        if(people.empty())break;
        
        
        
        //버스에 m명만큼 태울 수 있음
        while(people.front() <= now && !people.empty()){
            int person = people.front();
            if(busPeople < m){
                //정원 미초과
                busPeople++;
                people.pop_front();
                lastTime = person;
            }else{
                break;
            }
        }
        lastBusPeople = busPeople;
        lastBusTime = now;
    }
    if(lastBusPeople < m){
        answer = func(lastBusTime/60) + ":" + func(lastBusTime%60);
    }else{
        answer = func((lastTime-1)/60) + ":" + func((lastTime-1)%60);
    }
    
    
    return answer;
}