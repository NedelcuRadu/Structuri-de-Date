#include <bits/stdc++.h>
#define MOD  10007
using namespace std;
ifstream in("muzica.in");
ofstream out("muzica.out");
long long int N,M,A,B,C,D,E,x;
long long int counter = 0;
vector<int> filtru[MOD];
bool search(int val)
{
    int hash = val%MOD;
    auto i = find(filtru[hash].begin(),filtru[hash].end(),val);
    if(i!=filtru[hash].end())
    {
        filtru[hash].erase(i);
        return 1;
    }
 
    return 0;
}
int main()
{ //Tinem minte melodiile lui Vasile + aparent unordered_set iese din limite
    in>>M>>N;
    in>>A>>B>>C>>D>>E;
    while(M--)
    {
        in>>x;
        filtru[x%MOD].push_back(x);
    }
    counter+=search(A);
    counter+=search(B);
    for(int i=2; i<N; i++)
    {
        int melodie = (C*B+D*A)%E;
        counter+=search(melodie);
        A=B;
        B = melodie;
    }
    out << counter << endl;
    return 0;
}
