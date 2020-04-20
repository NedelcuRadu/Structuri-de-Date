#include "AVL.h"
ifstream in("abce.in");
//1 - Insert
// 2 - Delete
// 3 - find
// 4 - predecesor
// 5 - succesor
// 6 - interval
int main() {
    AVL A;
    int N, x, y, z;
    in >> N;
    for(int i = 0; i < N; i++) {
        in >> x >> y;
        switch(x) {
        case 1:
            A.insert(y);
            break;
        case 2:
            A.del(y);
            break;
        case 3:
            A.find(y);
            break;
        case 4:
            A.predecesor(y);
            break;
        case 5:
            A.succesor(y);
            break;
        case 6:
            in >> z;
            A.interval(y, z);
            break;
        }
    }
    return 0;
}
