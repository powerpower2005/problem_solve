#include <iostream>

using namespace std;
const int MAX = 1000000000;
long long X,Y;
int Z;
int K;


int main(){
    cin >> X >> Y;
    Z = (Y * 100) / X; //나중에 100을 하면 안됨.. 먼저 100곱하고 나눠야함.
    
    //99%는 절대 100% 될 수 없고, 100%은 절대 101%가 될 수 없음.
    if(Z == 99 || Z == 100){
        cout << "-1";
        return 0;
    }
    
    int low = 1;
    int high = MAX;
    
    while(low<=high){
        int mid = (low + high) / 2;
        //해당 탐색한 mid만큼 경기를 이겼을 경우의 확률 tmp
        int tmp = (100 * (Y + mid)) / (X + mid);
        
        //Z보다 크다면 최소 판수를 찾아야하므로 high를 내려서 범위를 좁힘
        if(tmp > Z){
            K = mid;
            high = mid - 1;
        }//여전히 확률이 같으면 판수를 늘려야함
        else{
            low = mid + 1;
        }
    }
    
    cout << K;
    return 0;
    
}