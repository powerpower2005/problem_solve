#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


//자물쇠 맞는지 체크
bool check(int arr[60][60], int sizeKey, int sizeLock){
    for(int i = 0; i<sizeLock; i++){
        for(int j = 0; j<sizeLock; j++){
           if(arr[sizeKey-1+i][sizeKey-1+j] != 1)return false; 
        }
    }
    return true;
}

//회전시켜서 값을 더함
void match(int arr[60][60], vector<vector<int>> key, int rot, int r, int c){
    int n = key.size();
    
    
    //회전하는 것 중요 ★★★★★
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(rot == 0){
                arr[r + i][c + j] += key[i][j];
            }else if(rot == 1){ //시계 방향 90도
                arr[r+i][c+j] += key[j][n-1-i];
            }else if(rot == 2){ //180
                arr[r+i][c+j] += key[n-1-i][n-1-j];
            }else{ // 270
                arr[r+i][c+j] += key[n-1-j][i];
            }
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    vector<vector<int>> copyKey = key;
    int sizeKey = key.size();
    int sizeLock = lock.size();
    
    
    
    //열쇠 위치 이동
    for(int i = 0; i<sizeKey+sizeLock-1; i++){
        for(int j = 0; j<sizeKey+sizeLock-1; j++){
            //열쇠와 자물쇠 맞는지 확인
            //0,90,180,270도 회전 확인
            for(int rot = 0; rot<4; rot++){
                //자물쇠 범위의 모든 값이 1이 된다면 true
                int arr[60][60];
                memset(arr, 0, sizeof(arr));
                
                //자물쇠 중간 배치
                for(int i = 0; i<sizeLock; i++){
                    for(int j = 0; j<sizeLock; j++){
                        arr[i+sizeKey-1][j+sizeKey-1] = lock[i][j];
                    }
                }
                
                //key 위치가 r,c 이면서 rot 상태일 때 arr와 합침
                match(arr, key, rot, i, j);
                if(check(arr, key.size(), lock.size())){
                    return true;
                }
                
            } 
        }
    }
    
    
    
    
    
    return answer;
}