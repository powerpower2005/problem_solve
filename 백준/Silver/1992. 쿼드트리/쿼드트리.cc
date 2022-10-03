#include<iostream>
#include<vector>
#include<string>
#define X first
#define Y second


using namespace std;

int N;
int pic[65][65];

//N의 크기를 가지고 왼쪽 위 좌표가 a,b인 정사각형
void func(int N, int a, int b) {

    //가장 잘게 쪼갰을 때
    if (N == 1) {
        //구현
        //해당 값 출력
        cout << pic[a][b];

        //종료
        return;
    }

    //4군데 좌표를 얻어야함
    //(a,b) , (a,b+N/2), (a+N/2,b), (a+N/2, b+N/2)
    vector<pair<int, int>> vec;
    vec.push_back({ a, b });
    vec.push_back({ a, b + N/2 });
    vec.push_back({ a + N/2, b });
    vec.push_back({ a + N/2, b + N/2 });

    int check = pic[a][b]; // 모두다 같은지 기준
    int diff = pic[a][b]; // 모두다 같은지 비교

    //전체를 뒤져서 아니면 4개로 나눔 
    // 이번 인덱스는 0부터 시작해야함...이거 틀림
    for (int i = 0; i <N; i++){
        if (check != diff) break; // 2
        for (int j = 0; j <N; j++) { // 0부터시작
            //전체가 다 같지 않으면 4개로 나눔.
            //전체가 다 같지 않으면 for문을 더 돌릴 필요 없음 break포인트 2개
            if (pic[vec[0].X +i][vec[0].Y + j] != check){
                diff = pic[vec[0].X + i][vec[0].Y + j];
                cout << "(";
                func(N / 2, vec[0].X, vec[0].Y);
                func(N / 2, vec[1].X, vec[1].Y);
                func(N / 2, vec[2].X, vec[2].Y);
                func(N / 2, vec[3].X, vec[3].Y);
                cout << ")";
                break; // 1
            }
        }
        
    }
    //만약 다 같으면 -> 해당숫자 출력
    if (check == diff) {
        cout << check;
    }
}

int main() {
    cin >> N;
    //공백없이 입력받을 때 , index는 1부터사용, N번 입력받음
    for (int i = 1; i <=N; i++) {
        string s = "";
        cin >> s;
        int seq = 1;
        //char이므로 int로 바꿔서 넣어줘야함 **이것때문에 틀림!!
        for (char c : s) {
            int x = c - '0';
            pic[i][seq++] = x;
        }
    }
    func(N, 1, 1);
}