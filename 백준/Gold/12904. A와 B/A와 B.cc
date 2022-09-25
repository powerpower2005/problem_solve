#include <bits/stdc++.h>

using namespace std;

int isPossible = 0;
void func(string result, string compare){
    if(result.empty())return;
    if(result == compare){
        isPossible = 1;
        return;
    }
    if(result.back() == 'A'){
        result.pop_back();
        func(result, compare);
    }else{
        result.pop_back();
        reverse(result.begin(), result.end());
        func(result, compare);
    }
}

int main(){
    string s,t;
    cin >> s >> t;
    
    func(t, s);
    cout << isPossible << '\n';
    
    
    return 0;
}