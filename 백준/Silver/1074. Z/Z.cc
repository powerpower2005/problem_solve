#include<iostream>
#include<cmath>

using namespace std;

int N;
int r, c;
int cnt = -1; // 방문을 0부터 시작함***

//////////////////
//++아래와 같이하면 무조건 처음부터 끝까지 돌아야함...

void func(int N, int a, int b) {
    //최소 N 길이가 2임.
    if (N == 2) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cnt++;
                int x = a+i;
                int y = b+j;
                if (x == r && y == c) {
                    cout << cnt;
                    return;
                }
            }
        }
        return;
    }
    // ++ 4개다 조사할 필요는 없다. -> 행과 열을 아니까.
    if (r < a + N / 2 && c < b + N / 2) {
        func(N / 2, a, b);
    }
    else if (r < a + N / 2 && c >= b + N / 2) {
        cnt += pow(N / 2, 2);
        func(N / 2, a, b + N / 2);
    }
    else if (r >= a + N / 2 && c < b + N / 2) {
        cnt += 2 * pow(N / 2, 2);
        func(N / 2, a + N / 2, b);
    }
    else {
        cnt += 3 * pow(N / 2, 2);
        func(N / 2, a + N / 2, b + N / 2);
    }

    return;
}

int main() {
    cin >> N >> r >> c;
    N = pow(2, N); // 사각형이 제곱으로 늘어남.****

    func(N, 0, 0); // 인덱스가 0부터 시작함 얘는****
}