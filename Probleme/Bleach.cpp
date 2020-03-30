#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
ifstream in("bleach.in");
ofstream out("bleach.out");
int main() {
    vector<int> A;
    long long N, K, S, add = 0;
    in >> N >> K;
    for(auto i = 0; i < N; i++) {
        in >> S;
        A.push_back(S);
    }
    sort(A.begin(), A.end());
    S = 0;
    for(auto i = 0; i < A.size(); i++)
        if(S < A[i]) {
            add += A[i] - S;
            S = A[i] * 2;
        } else
            S += A[i];
    out << add;
    return 0;
}
