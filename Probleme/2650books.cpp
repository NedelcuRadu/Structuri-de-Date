#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
ifstream in("nrpits.in");
ofstream out("nrpits.out");
int n;
bool exista(vector<int> A, int val) {
    for(int i = 0; i < A.size(); i++)
        if (A[i] == val)
            return 1;
    return 0;
}
int main() {
    int x;
    deque<int> A;
    vector<int> B;
    in >> n;
    for(int i = 0; i < n; i++) {
        in >> x;
        A.push_back(x);
    }
    for(int i = 0; i < n; i++) {
        in >> x;
        if (exista(B, x)) {
            cout << '0' << " ";
        } else {
            int j = 1;
            while(A.front() != x) {
                B.push_back(A.front());
                j++;
                A.pop_front();
            }

            B.push_back(A.front());
            cout << j << " ";
            A.pop_front();
        }
    }
    return 0;
}
