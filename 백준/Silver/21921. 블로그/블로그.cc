#include <bits/stdc++.h>

using namespace std;

int N, X;


int main(){
    cin >> N >> X;
    //큐로 담아서 항상 X개의 개수를 유지하게 한다.
    //앞의 일자를 빼면서 뒤의 일자를 집어넣는 식이다.
    queue<int> q;
    int cnt = 0;
    int sum = 0;
    
    unordered_map<int, int> number;    //{방문자수,횟수}
    int M = 0;
    while(N--){
        
        int visit;
        cin >> visit;
        sum += visit;
        q.push(visit);
        cnt++;
        
        //X일동안
        if(cnt>=X){
            //방문자수 합과 이전에 있던 방문자수 합의 비교
            M = max(M,sum);
            //해당 방문자수 카운트
            number[sum]++;
            //다음에 진행할 때 X의 크기를 유지하기 위하 맨 앞의 원소제거
            sum -= q.front();
            q.pop();
            cnt--;
        }
    }
    
    
    
    if(M == 0){
        cout << "SAD" << '\n';
    }else{
        cout << M <<'\n';
        cout << number[M] << '\n';
    }
    
    return 0;
}