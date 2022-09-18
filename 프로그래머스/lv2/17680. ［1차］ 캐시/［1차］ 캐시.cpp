#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    deque<string> cache;
    
    
    for(auto c : cities){
        if(cacheSize == 0 ){
            answer += cities.size() * 5;
            break;
        }
        //대소문자 구분 x        
        string city = "";
        for(char xx : c){
            city += tolower(xx);    
        }
        
        
        auto it = find(cache.begin(), cache.end(), city);
        //cache miss
        if(it == cache.end()){
            //cache 교체 (가장 덜 쓰인 것)
            if(cache.size() == cacheSize){
                cache.pop_back();
            }
            //앞에서 부터 추가시킴
            cache.push_front(city);
            answer += 5;
        }
        //cache hit => 항상 앞에 추가한다. => 최근에 쓰인건 앞에 있다.
        else{
            cache.erase(it);
            cache.push_front(city);
            answer += 1;
        }
    }
    
    
    return answer;
}