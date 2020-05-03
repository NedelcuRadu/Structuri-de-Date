#include <bits/stdc++.h>
using namespace std;
// Luam cea mai mica litera din fiecare cuvant si apoi sortam cuvantul obtinut
int main() {
    int N;
    string cuv;
    string rez = "";
    char c = 'z';
    cin>>N;
    for(int i=0;i<N;i++)
        {cin>>cuv;
        c='z';
        for(auto &i:cuv)
        if (i < c)
        c=i;
        rez+=c;
        }
        sort(rez.begin(),rez.end());
        cout<<rez;
    return 0;
}
