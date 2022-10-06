#include <bits/stdc++.h>

using namespace std;

int maxNumber = -1;
int N; // N*N size

vector<vector<int>> vec;


void DFS(int cnt, vector<vector<int>>& board);
void shiftBlock(int type, vector<vector<int>>& board);


//1
int solution(vector<vector<int>>& board)
{
    DFS(0, board);
    return maxNumber;
}

//2
void DFS(int cnt, vector<vector<int>>& board){
    //모든 경우를 고려해서 조사해야함
    //5번까지 가능
    if(cnt == 5){
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                maxNumber = max(maxNumber, board[i][j]);
            }
        }
        return;
    }
    int backup[N][N];
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            backup[i][j] = board[i][j];
        }
    }

    //4가지 방향 중 선택
    for(int i = 0; i<4; i++){
        shiftBlock(i, board); //선택
        DFS(cnt+1, board); //진행
        //복구
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                board[i][j] = backup[i][j];
            }
        }
    }
}


//3
//주어지는 보드는 N*N이라고 가정.
//주어진 보드에 대해서 수행 어떤 shift를 할 것인지
void shiftBlock(int type, vector<vector<int>>& board){
    queue<int> q;
    //방향대로 숫자를 집어넣어 같으면 병합하기 위함.
    //0: 좌 1: 우 2: 상 3: 하
    switch(type){
        case 0:
            for(int i = 0; i<N; i++){
                for(int j = 0; j<N; j++){
                    //큐에 넣고 (shift하고)
                    if(board[i][j]){q.push(board[i][j]);}
                    //해당 칸 없앰
                    board[i][j] = 0;
                }


                //해당 줄의 모든 칸을 옮겼다면.
                int index = 0; // => 해당 줄의 첫번째 칸부터 병합
                while(!q.empty()){
                    int num = q.front();
                    q.pop();
                    //만약 빈칸이라면 그냥 옮김
                    if(board[i][index] == 0){
                        board[i][index] = num;
                    }
                    //빈칸이 아니고 숫자가 같을 경우 병합
                    else if(board[i][index] == num){
                        board[i][index] *= 2;
                        index++;
                    }
                    //빈칸도 아니고 숫자가 다르면 그냥 그대로
                    else{
                        index++;
                        board[i][index] = num;
                    }
                }
            }
            break;


        //우측은 좌측과 반대로 큐에 넣음 => 우측부터 넣음
        case 1:
            for(int i = 0; i<N; i++){
                    for(int j = N-1; j>=0; j--){
                        //큐에 넣고 (shift하고)
                        if(board[i][j]){q.push(board[i][j]);}
                        //해당 칸 없앰
                        board[i][j] = 0;
                    }
                    //해당 줄의 모든 칸을 옮겼다면.
                int index = N-1; // => 해당 줄의 마지막 칸(가장 오른쪽)부터 병합
                while(!q.empty()){
                    int num = q.front();
                    q.pop();
                    //만약 빈칸이라면 그냥 옮김
                    if(board[i][index] == 0){
                        board[i][index] = num;
                    }//빈칸이 아니고 숫자가 같을 경우 병합
                    else if(board[i][index] == num){
                        board[i][index] *= 2;
                        index--;
                    }
                    //빈칸도 아니고 숫자가 다르면 그냥 그대로
                    else{
                        index--;
                        board[i][index] = num;
                    }
                }
            }
            break;


        //위쪽도 원리는 같음 다만 이번엔 행으로 조사하는 것이 아니라
        //열로 조사함. i 열의 0,1,2,3(j)행
        case 2:
            for(int i = 0; i<N; i++){
                for(int j = 0; j<N; j++){
                    if(board[j][i]){q.push(board[j][i]);}
                    board[j][i] = 0;
                }
                int index = 0;

                while(!q.empty()){
                    int num = q.front();
                    q.pop();

                    if(board[index][i] == 0){
                        board[index][i] = num;
                    }else if(board[index][i] == num){
                        board[index][i] *= 2;
                        index++;
                    }else{
                        index++;
                        board[index][i] = num;
                    }
                }
            }
            break;

        //아래쪽
        case 3:
        for(int i = 0; i<N; i++){
                for(int j = N-1; j>=0; j--){
                    if(board[j][i]){q.push(board[j][i]);}
                    board[j][i] = 0;
                }
                int index = N-1;

                while(!q.empty()){
                    int num = q.front();
                    q.pop();

                    if(board[index][i] == 0){
                        board[index][i] = num;
                    }else if(board[index][i] == num){
                        board[index][i] *= 2;
                        index--;
                    }else{
                        index--;
                        board[index][i] = num;
                    }
                }
            }   
            break;

        default:
            cout << "오류" <<'\n';
            break;
    }
}


int main(){
    cin >> N;
    for(int i = 0; i<N; i++){
        vector<int> temp;
        vec.push_back(temp);
        for(int j = 0; j<N; j++){
            int x;
            cin >> x;
            vec[i].push_back(x);
        }
    }
    
    
    int ans = solution(vec);
    cout << ans;
    
    

    return 0;
}
