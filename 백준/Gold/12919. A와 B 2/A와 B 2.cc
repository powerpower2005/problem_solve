#include <bits/stdc++.h>

using namespace std;

int isPossible = 0;
void func(deque<char> deq, string compare, bool rev){

    //cout << compare << '\n';
    if(deq.size() == compare.size()){
        string temp = "";
        for(auto x : deq){
            temp += x;
        }
        //cout << temp << '\n';
        if(rev){
            reverse(temp.begin(), temp.end());
        }
        //cout << temp << '\n';
        if(temp == compare) isPossible = 1;
        return;
    }
    //이전에 B작업을 했다면

    auto copy1 = deq; //A작업
    auto copy2 = deq; //B작업
    //out << copy1.back() << " " << copy2.front() << "\n";
    
    //뒤집혀있는지 확인 후 작업
    if(rev){
        if(copy1.front() == 'A'){
            copy1.pop_front();
            func(copy1, compare, rev);
        }
    }else{
        if(copy1.back() == 'A'){
        copy1.pop_back();
        //cout << "A\n";
        func(copy1, compare, rev);
     }
    }
    if(rev){
        if(copy2.back() == 'B'){
        copy2.pop_back();
        //cout << "B\n";
        func(copy2, compare, !rev);
        }
    }else{
        if(copy2.front() == 'B'){
        copy2.pop_front();
        //cout << "B\n";
        func(copy2, compare, !rev);
        }
    }

}

int main(){
    string a,b;
    cin >> a >> b;
    
    deque<char> deq;
    for(auto c : b){
        deq.push_back(c);
    }
    
    func(deq, a, false);
    
    
    
    cout << isPossible << '\n';
    
    return 0;
}