#include <bits/stdc++.h>
using namespace std;
// 4! = 3! * 2! * 2!
// 5! = 4! * 5 = 5 * 3! * 2! = 5!
// 6! = 5! * 6 = 3! * 5!
// 7! = 6! * 7 = 3! * 3! * 2! * 5 * 7 = 7!
// 8! = 7! * 2! * 2 *2 = 7! * 2! * 2! * 2!
// 9! = 8! * 9 = 7! * 2! * 2! * 2! * 3 * 3 = 7! * 3! * 3! *2!
// (Mai mergea facut si cu un count sort folosind aceleasi transformari, nu mai era nevoie de ltrim,sortam O(N) si foloseam mai putina memorie)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](char ch) {
        return !(ch=='0');
    }));
}
int main()
{
    string A,rez;
    cin>>A;
    cin>>A;
    ltrim(A);
    for(auto &i:A)
        if(i=='0' || i=='1')
            continue;
        else if(i =='2' || i=='3' || i=='5' || i=='7')
            rez.push_back(i);
        else if(i=='4')
            rez+="322";
        else if(i=='6')
            rez+="53";
        else if(i=='8')
            rez+="7222";
        else
            rez+="7332";
    sort(rez.rbegin(),rez.rend());
    cout << rez;
    return 0;
}
