#include<iostream>
#include<queue>
#include<vector>

int main(){
    int N,K;
    std::queue<int> q;
    std::vector<int> answer;
    
    
    std::cin >> N >> K;
    
    //생성
    for(int i = 1; i<=N; i++){
        q.push(i);
    }
    
    //순서대로 삭제하고 살아남은 사람은 순서대로 다시 큐에 들어감.
    while(!q.empty()){
        for(int j = 1; j< K; j++){
            q.push(q.front());
            q.pop();
        }
        //정답에 넣어줌
        answer.push_back(q.front());
        q.pop();
        
    }
    
    //츨력
    std::cout << '<' << answer[0];
    for(int i = 1; i < answer.size(); i++){
        std::cout << ", " << answer[i];
    }
    std::cout<< ">";
    
    
}