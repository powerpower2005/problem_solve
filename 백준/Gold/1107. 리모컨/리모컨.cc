#include <bits/stdc++.h>

using namespace std;



bool button[10]; //false


//해당 채널로 이동하기 위한 숫자입력 횟수
int possible(int n){
    //0번 채널로 이동하는 경우
    if(n == 0){
        //고장나면 숫자로 이동 불가능
        if(button[n]){
            return 0;
        }else{
            return 1;
        }
    }
    
    int len = 0;
    while(n > 0){
        //버튼 고장나면 이동 불가
        if(button[n%10]){
            return 0;
        }
        //고장안났으면 횟수 추가
        len += 1;
        n /= 10;
    }
    return len;
}

int main(){
    
    int target;
    cin >> target;
    
    int broken;
    cin >> broken;
    if(broken > 0){
        for(int i = 0; i<broken; i++){
            int num;
            cin >> num;
            button[num] = true; //고장난 버튼 true
        }
    }
    
    
    //100번에서 시작
    int ans = abs(target - 100); //100번과 목표 채널의 차 => 100번 이하가 목표면 음수이기에 절댓값
    // => 위의 값은 숫자 없이 +,-로 이동하는 것임
    
    //숫자 이동 후 +,- 하기
    for(int i=0; i<=1000000; i++){
        int x = i; // 해당 채널로 번호로 이동 후 목표 채널로 이동하기
        int len = possible(x); //해당 채널로 이동할 때 숫자 버튼 누를 횟수
        //숫자 버튼 이동 후 +,-이동
        if(len > 0){
            int press = abs(x - target); //숫자버튼 이동 후 +,-
            
            if(ans > len + press){
                ans = len + press;
            }
        }
        
    }
    
    
    cout << ans ;
    
    
    
    return 0;
}