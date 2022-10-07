#include <bits/stdc++.h>

using namespace std;

int N;
int L;
int arr[101][101];

int CheckRow(){
    int count = 0;
    
    //=> 행 조사
    


    int installed[101][101] = {0};
    
    //1. 행에 대해서 조사
    for(int i = 0; i<N; i++){
        int last = arr[i][0];
        int cur = arr[i][0];
        int curC = -1;
        int seq = 0;
        for(int j = 0; j<N; j++){
            //cout << i << "  " << j << '\n';
            //높이가 같으면 그냥 지나가기 가능
            if(last == arr[i][j]){
                seq++;
                cur = arr[i][j];
                curC = j;
            }//경사로 설치해야함.
            else{
                //1차이가 넘으면 경사로 해결 불가능
                if(abs(last - arr[i][j]) > 1)break;
                
                //오르막경사인지 내리막 경사인지 구분
                //오르막
                if(last < arr[i][j]){
                    //오르막이라면 지금까지 연속된 블럭의 개수가 L과 같은지
                    //다른 경사를 만드는데 쓰이진 않았는지 체크
                    if(seq < L)break;
                    //cout << "seq for up" << seq << "\n";
                    int now = j;
                    bool isPossible = true;
                    //확보된 영역에 이미 설치되어 있는 것은 아닌지 체크
                    for(int k = now; k> now-L; k--){
                        if(installed[i][k] == 1){
                            isPossible = false;
                            break;
                        }
                    }
                    if(isPossible){
                        //설치할 수 있다면 진행 가능
                        for(int k = now; k> now-L; k--){
                            installed[i][k] = 1;
                        }
                        last = arr[i][j];
                        cur = arr[i][j];
                        curC = j;
                        seq = 1;
                    }else{
                        break;
                    }
                }
                //내리막
                else{
                    //내리막이라면 내리막에서 L만큼 자리를 확보할 수 있는지 체크
                    int now = j;
                    int val = arr[i][j];
                    //자리를 확보를 보장 못하면 체크
                    if(j + L - 1 >= N)break;
                    
                    bool isPossible = true;
                    //자리를 확보했더라도 확보한 자리가 평평한지
                    for(int k = j; k < j + L; k++){
                        if(val != arr[i][k]){
                            isPossible = false;
                            break;
                        }
                    }
                    //확보한 자리가 평평하면
                    if(isPossible){
                        for(int k = j; k < j + L; k++){
                            installed[i][k] = 1;
                        }
                        //경사로 위치는 조사하지 않아도 된다.
                        last = val;
                        cur = val;
                        seq = 0;
                        //j 갱신 => 경사로는 조사할 필요없음
                        j = j + L - 1;
                        //다음 조사할 위치는 curC
                        curC = j;
                    }else{
                        break;
                    }
                }
            }
        }
        if(curC == N-1){
            //cout << "passC:" << i << "\n";
            count++;
        }
    }
    return count;
}


int CheckCol(){
    int count = 0;
    
    //=> 열 조사
    int installed[101][101] = {0};
    
    //2. 열에 대해서 조사
    for(int i = 0; i<N; i++){
        int last = arr[0][i];
        int cur = arr[0][i];
        int curR = -1;
        int seq = 0;
        for(int j = 0; j<N; j++){
            //cout << i << "  " << j << '\n';
            //높이가 같으면 그냥 지나가기 가능
            if(last == arr[j][i]){
                seq++;
                cur = arr[j][i];
                curR = j;
            }//경사로 설치해야함.
            else{
                //1차이가 넘으면 경사로 해결 불가능
                if(abs(last - arr[j][i]) > 1)break;
                
                //오르막경사인지 내리막 경사인지 구분
                //오르막
                if(last < arr[j][i]){
                    //오르막이라면 지금까지 연속된 블럭의 개수가 L과 같은지
                    //다른 경사를 만드는데 쓰이진 않았는지 체크
                    if(seq < L)break;
                    //cout << "seq for up" << seq << "\n";
                    int now = j;
                    bool isPossible = true;
                    //확보된 영역에 이미 설치되어 있는 것은 아닌지 체크
                    for(int k = now; k> now-L; k--){
                        if(installed[k][i] == 1){
                            isPossible = false;
                            break;
                        }
                    }
                    if(isPossible){
                        //설치할 수 있다면 진행 가능
                        for(int k = now; k> now-L; k--){
                            installed[k][i] = 1;
                        }
                        last = arr[j][i];
                        cur = arr[j][i];
                        curR = j;
                        seq = 1;
                    }else{
                        break;
                    }
                }
                //내리막
                else{
                    //내리막이라면 내리막에서 L만큼 자리를 확보할 수 있는지 체크
                    int now = j;
                    int val = arr[j][i];
                    //자리를 확보를 보장 못하면 체크
                    if(j + L - 1 >= N)break;
                    
                    bool isPossible = true;
                    //자리를 확보했더라도 확보한 자리가 평평한지
                    for(int k = j; k < j + L; k++){
                        if(val != arr[k][i]){
                            isPossible = false;
                            break;
                        }
                    }
                    //확보한 자리가 평평하면
                    if(isPossible){
                        for(int k = j; k < j + L; k++){
                            installed[k][i] = 1;
                        }
                        //경사로 위치는 조사하지 않아도 된다.
                        last = val;
                        cur = val;
                        seq = 0;
                        //j 갱신 => 경사로는 조사할 필요없음
                        j = j + L - 1;
                        //다음 조사할 위치는 curC
                        curR = j;
                    }else{
                        break;
                    }
                }
            }
        }
        if(curR == N-1){
            //cout << "passR:" << i << "\n";
            count++;
        }
    }
    return count;
}

int main(){
    cin >> N >> L;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    ans += CheckRow();
    ans += CheckCol();
    cout << ans << '\n';
    return 0;
}