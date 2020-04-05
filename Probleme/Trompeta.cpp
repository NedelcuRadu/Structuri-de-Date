#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
ifstream in("trompeta.in");
ofstream out("trompeta.out");

int main() {
    std::ios::sync_with_stdio(false);
    string A,B; // Folosim strings pe post de stack
    int N, M;
    int eliminate = 0;
    in >> N >> M;
    int deeliminat = N - M;
    in>>A;
    for (auto &i : A){
            while(!B.empty() && eliminate < deeliminat && i> B.back()) {
                B.pop_back();
                eliminate++;
            }
        B.push_back(i);
    }
    out<<B;

    return 0;
}
