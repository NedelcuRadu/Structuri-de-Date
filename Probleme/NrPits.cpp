#include <fstream>
#include <stack>
using namespace std;
ifstream in("nrpits.in");
ofstream out("nrpits.out");
int main() {
    stack<int> A;
    int n, x, nr = 0;
    in >> n;
    for(int i = 0; i < n; i++) {
        in >> x;
        while(!A.empty() && x > A.top()) {
            A.pop();
            if(!A.empty())
                nr++;
        }
        A.push(x);
    }
    out << nr << endl;
    return 0;
}
