#include <bits/stdc++.h>

using namespace std;
int T;

//좌측과 우측의 값을 순차적으로 비교
bool palindrome(string s) {
    //cout << s << '\n';
    int length = s.size();
    for (int i = 0; i < length / 2; i++)
        if (s[i] != s[length - i - 1])
            return false;
    return true;
}



int check(string s){
   
    //회문
    if(palindrome(s))return 0;
    
    //유사회문
    int left = 0;
    int right = s.size()-1;
    
    while(left < right){
        if(s[left] != s[right]){
            //왼쪽 값을 삭제
            if(palindrome(s.substr(0,left) + s.substr(left+1)))return 1;
            //오른쪽 값을 삭제
            if(palindrome(s.substr(0,right) + s.substr(right+1)))return 1;
            
            return 2;
        }
        left++;
        right--;
    }

    return 2;
}
int main(){
    cin >> T;
    cin.tie(0);
    ios::sync_with_stdio(0);
    while(T--){
        string s;
        cin >> s;
        int x = check(s);
        
        
        
        
        cout << x<<'\n';
    }
    return 0;
}