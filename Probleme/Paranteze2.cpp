#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
ifstream in("paranteze2.in");
ofstream out("paranteze2.out");

int main() {
    // ) = -1  ( = 1
    stack<int> B;
    char x;
    int nr = 0;
    while(in >> x) {
        if(x == ')') {
            if (B.empty()) {
                B.push(1);
                nr++;
            } else {
                B.pop();
            }
        } else
            B.push(1);
    }
    nr += B.size() / 2;
    out << nr;
    return 0;
}
