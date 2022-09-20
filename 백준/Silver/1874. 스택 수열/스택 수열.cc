#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //1~N까지
    int N;
    cin >> N;
    
    stack<int> stk;
    vector<char> v;
    queue<int> q;
    
    //만들 수열
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        q.push(n);
    }


    //1~N까지 탐색하면서 만들 수 있는지 체크
    for (int i = 1; i <= N; i++) {
        stk.push(i);
        v.push_back('+');
        
        //뺄 수 있는 한 계속 뺀다.
        while (!stk.empty() && stk.top() == q.front()) {
            stk.pop();
            q.pop();
            v.push_back('-');
        }
    }
    
    //다 뺐다면 만들 수 있음.
    if (stk.empty()) {
        for (char c : v) {
            cout << c << '\n';
        }
    }
    else { //못만듬
        cout << "NO";
    }

}