#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;

vector<int> vec;
vector<int> target;

int main(){
    cin >> N;
    //A숫자
    for(int i = 1; i<=N; i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    //B숫자 
    for(int i = 1; i <= N; i++){
        int b;
        cin >> b;
        target.push_back(b);
    }
    
    sort(target.begin(), target.end()); // 오름차순
    sort(vec.begin(), vec.end()); // 오름차순
    reverse(vec.begin(),vec.end()); // 내림차순
    
    int sum = 0;
    
    for(int i = 0; i<N; i++){
        sum += vec[i] * target[i];    
    }
    
    cout << sum <<'\n';
    
    
}