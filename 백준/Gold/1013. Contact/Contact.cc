#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
    cin >> T;
    regex re1("(100+1+|01)+");

    while(T--){
        string sig;
        cin >> sig;
        bool x = false;
        x |= regex_match(sig, re1);
        if(x)cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}