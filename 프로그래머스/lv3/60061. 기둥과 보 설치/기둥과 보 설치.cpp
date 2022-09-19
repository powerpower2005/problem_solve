#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int poll[102][102] = {0};
int roof[102][102] = {0};

//기둥 설치 여부
bool checkPoll(int x,int y){
    //바닥이거나 밑에 기둥이 있다면
    if(y == 0 || poll[x][y-1] == 1)return true;
    //보 위에 위치한다면
    if(x > 0 && roof[x-1][y] || roof[x][y])return true;
    return false;
}

bool checkRoof(int x, int y){
    //기둥은 한칸 아래부터 설치
    //y>0을 보장하는 조건 : 바닥에 보를 설치 하는 경우는 없습니다.
    if(poll[x][y-1] ==1 || poll[x+1][y-1] ==1)return true;
    if(x > 0 && roof[x-1][y] == 1 && roof[x+1][y] == 1)return true;
    return false;
}

bool checkDelete(int x,int y){
    //(x,y)의 위치의 구조물 삭제로 인해 영향받는 것들
    //(x-1,y)위치, (x,y)위치 (x+1, y)위치
    // x+1,y위치 ,x+1,y+1위치 x,y+1 위치
    for(int i = max(x-1,0); i<= x+1; i++){
        for(int j = y; j<=y+1; j++){
            if(poll[i][j] && checkPoll(i,j) == false){
                return false;
            }
            if(roof[i][j] && checkRoof(i,j) == false){
                return false;
            }
        }
    }
    return true;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    
    
    for(auto bf : build_frame){
        int x = bf[0], y = bf[1];
        int type = bf[2], cmd = bf[3];
        
        //삭제
        switch(type){
            //기둥
            case 0:
                //삭제
                if(cmd == 0){
                    poll[x][y] = 0;
                    if(checkDelete(x,y) == false){
                        poll[x][y] = 1;
                    }
                }
                //설치
                else{
                    if(checkPoll(x,y)){
                        poll[x][y] = 1;
                    }
                }
                break;
            //보
            case 1:
                //삭제
                if(cmd == 0){
                    roof[x][y] = 0;
                    if(checkDelete(x,y) == false){
                        roof[x][y] = 1;
                    }
                }
                //설치
                else{
                    if(checkRoof(x,y)){
                        roof[x][y]=1;
                    }
                }
                break;
        }
    }
    
    
    //남아있는 구조물 조사 poll 부터 작은 순으로
    for(int i = 0; i<=n; i++){
        for(int j = 0; j <= n; j++){
            if(poll[i][j] == 1){
                answer.push_back({i,j,0});
            }
            if(roof[i][j] == 1){
                answer.push_back({i,j,1});
            }
        }
    }
    
    
    return answer;
}