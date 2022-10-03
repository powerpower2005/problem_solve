#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main(){
    int test;
    cin >> test;
    
    for(int i = 0; i<test; i++){
        int M,N,a,b;
        cin >> M >> N >> a >> b;
        int x = a;
        int y = b;
        
        int limit = lcm(M,N);
        
        while(1){
            
            if(x > limit)break;
            if((x-1) % N + 1 == y)break;
            x += M;
        }
        
        if(x > limit){
            cout << "-1" << '\n';
        }else{
            cout << x << '\n';
        }
        
    }
    return 0;
}