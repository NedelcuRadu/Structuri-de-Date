#include <bits/stdc++.h>
using namespace std;
ifstream in("beri.in");
ofstream out("beri.out");
int N, K, Q, X, Y, Z;
int main() {
    in >> N >> K >> Q >> X >> Y >> Z;
    long long int C[N];
    C[0] = Q;
    for(int i = 1; i < N; i++)
        C[i] = (C[i - 1] * X + Y ) % Z + K;
    nth_element(C, C + K, C + N, std::greater<int>());
    long long int S = 0;
    for(int i = 0; i < K; i++)
        S += C[i] - i;

    out << S;
    return 0;
}
