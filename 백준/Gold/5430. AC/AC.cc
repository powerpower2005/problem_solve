#include <bits/stdc++.h>

using namespace std;

int T = 0;

int main(){
    cin >> T;
    int testcase = T;
    while(testcase--){
        //함수 받기
        string com;
        cin >> com;

        // 숫자 받기
        int num;
        cin >> num;
        
        //최대 10만, 최소 0
        deque<int> deq;
        // 배열 형식 숫자 입력
        string nums;
        cin >> nums;
        
        int size = nums.size();
        //전처리
        for(int i = 0; i<size; i++){
            if(nums[i] == '[' || nums[i] == ']' || nums[i] == ','){
                nums[i] = ' ';
            }
        }
        // 숫자를 뽑아내기 위한 ss
        stringstream ss(nums);
 

        //이제부터 숫자.
        for(int i = 0; i<num; i++){
            int x = 0;
            ss >> x ;
            deq.push_back(x);
        }
        //에러처리 및 함수처리
        bool isError = false;
        bool rev = false;
        for(char c : com){
            if(c == 'R'){
                rev = !rev;
            }else{
                if(deq.empty()){
                    cout << "error" << '\n';
                    isError = true;
                    break;
                }
                //뒤집혔다는 가정하에 제거하는 위치가 다름
                if(rev){
                    deq.pop_back();
                }else{
                    deq.pop_front();
                }
            }
        }
        if(isError)continue;
        cout << '[';
        if(!deq.empty()){
            if(rev)reverse(deq.begin(), deq.end());
            for(int i = 0; i<(int)deq.size()-1; i++){
                cout << deq[i] << ',';
            }
            cout << deq.back();
        }
        cout << ']' << '\n';
        
        
    }
    
    return 0;
}