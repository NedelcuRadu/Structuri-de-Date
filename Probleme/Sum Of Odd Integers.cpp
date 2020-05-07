#include <iostream>
#include <fstream>
using namespace std;
ifstream in("nr.in");
int main()
{   long long int N,x,y; // Cand erau int aparent dadea overflow
    cin>>N;
    while(N--)
    {
        cin>>x>>y;
        if((x%2 == y%2) && y*y<=x) 
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
