#include<iostream>
#include<algorithm>

using namespace std;

int N, K;

long long arr[10001];
long long ans = 1;

long long M = 0;

bool func(long long n){
    long long cnt = 0;
    for(int i = 0; i<N; i++){
        cnt += arr[i]/n;
    }
    return(cnt >= K);
}

//이분탐색 사용해야함
int main(){
    cin >> N >> K;
    for(int i = 0; i<N; i++){
        int a;
        cin >> a;
        arr[i] = a;
        if(M<a){
            M = a;
        }
    }
    
    //값의 범위 2^31-1 이하의 자연수
    long long low = 1;
    long long high = M;

    
    while(low <= high){
        long long mid = (low+high)/2; // 해당숫자
        
        //해당 숫자가 K 이상의 랜선을 만들면 더 커질 수 있는 랜선이 있나 조사해야함.
        //우선 해당값을 저장하고 오른쪽 다시 탐색.
        if(func(mid)){
            if(ans<mid){
                ans = mid;
            }
            low = mid+1;
        }else{ // 못만들면 숫자를 작은 것을 선택해야함.
            high = mid-1;
        }
    }
    
    cout << ans << '\n';
    
}


//아래와 같이 하면 시간초과남.
//또한 최댓값이 주어진 수에서 가장 낮은 값부터 시작한다고 생각함


/*
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;

    for (int i = 0; i < K; i++) {
        long long a;
        cin >> a;
        arr[i] = a;
    }
    sort(arr, arr + K); // 오름차순
    standard = arr[K-1]; // 최댓값


    while (1) {
        for (int i = K-1; i > 0; i--) {
            sum += (arr[i] / standard);
        }
        if (sum >= N) {
            cout << standard;
            break;
        }
        else {
            sum = 0;
            standard--;
        }
    }
}
*/