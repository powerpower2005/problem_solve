#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;
int n;


void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
}

ll func(ll x, ll y){
    ll dist = y-x;
    ll k = sqrt(dist);
    //제곱수이면, 16이라면 4+3의 개수를 가짐
    if(k*k == dist)return(2*k-1);
    else{
        //아니면 그 사이의 범위를 나눠야함
        //제곱수 사이의 숫자는 항상 짝수이다 9~16 -> 10,11,12   13,14,15
        //제곱수가 아니라면 그 숫자, y는 ex 15이면 y는 3(o), 4(x)
        if(dist<= k*k+k){
            // 12라면 3의 제곱인 9가 가지는 개수보다 하나 많음 (2k-1 + 1)
            return 2*k;
        }else{
            //15라면 3의 제곱인 9가 가지는 개수보다 1개 많음
            return 2*k+1;
        }
    }
    
}

int main(){
    init();
    cin >> n;

    
    
    for(int i = 0; i<n; i++){
        ll a, b;
        cin >> a >> b;
        ll ans = func(a,b);
        cout << ans << "\n";
    }
}