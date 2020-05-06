#include <iostream>

using namespace std;

int main()
{   int N,x,y;
    cin>>N;
    while(N--)
    {
        cin>>x>>y;
        if(y*y <= x && (x+y)%2 ==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
