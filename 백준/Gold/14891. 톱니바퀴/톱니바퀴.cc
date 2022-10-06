#include <bits/stdc++.h>

using namespace std;


deque<int> deq[5];
bool rot[5];
int dir[5];

void rotate(int index, int dir){
    if(index < 1 || index > 4)return;
    if(dir == 1){
        int temp = deq[index].back();
        deq[index].pop_back();
        deq[index].push_front(temp);
    }else if(dir == -1){
        int temp = deq[index].front();
        deq[index].pop_front();
        deq[index].push_back(temp);
    }
}

int score(int index){
    if(deq[index][0] == 0)return 0;
    else{
        return pow(2, index-1);
    }
}
//3번과 7번 이 맞닿는 부위임
int main(){
    
    
    for(int i = 1; i<=4; i++){
        string s;
        cin >> s;
        for(auto x : s){
            deq[i].push_back(x - '0');
        }
    }
    
    int K;
    cin >> K;
    for(int i = 0; i<K; i++){
        int index, direction;
        cin >> index >> direction;
        
        //초기화
        for(int i = 1; i<=4; i++){
            rot[i] = false;
            dir[i] = 0;
        }
        
        
        rot[index] = true;
        dir[index] = direction;
        //cout << index << '\n';
        
        //회전시키고자하는 톱니의 왼쪽 것들에 대한 조사
        for(int i = index; i>1; i--){
            if(deq[i][6] != deq[i-1][2] && rot[i] == true){
                //cout << deq[i][7] <<" " << deq[i-1][3] << '\n';
                rot[i-1] = true;
                dir[i-1] = -dir[i];
            }    
        }
        //회전시키고자하는 톱니의 오른쪽 것들에 대한 조사
        for(int i = index; i<4; i++){
            if(deq[i][2] != deq[i+1][6] && rot[i] == true){
                rot[i+1] = true;
                dir[i+1] = -dir[i];
            }    
        }
        for(int i = 1; i<=4; i++){
            if(rot[i] == true){
                rotate(i,dir[i]);
                for(int j = 0; j<8; j++){
                    //cout << deq[i][j];
                }
                //cout << "deq: "<< i <<"\n";
            }
        }
        
        

    }
    
    int ans = 0;
    for(int i = 1; i<=4; i++){
        ans += score(i);
    }
    cout << ans << '\n';
    
    return 0;
}