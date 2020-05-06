#include <iostream>
#include <bits/stdc++.h>
using namespace std;
ifstream in("hotelier.in");
void left_add(bool A[10])
{
    for(int i=0; i<10; i++)
        if(A[i]==0)
        {
            A[i]=1;
            return;
        }
}
void right_add(bool A[10])
{
    for(int i=9; i>-1; i--)
        if(A[i]==0)
        {
            A[i]=1;
            return;
        }
}
void afis(bool rez[10])
{
     for(int i=0;i<10;i++)
    cout<<rez[i];
    cout<<'\n';
}
int main()
{
    int N;
    string A;
    bool rez[10];
    for(int i=0;i<10;i++)
        rez[i]=0;
    cin>>N>>A;
    for(auto &i:A)
        {
            if(i=='L')
            left_add(rez);
        else
            if(i=='R')
            right_add(rez);
        else
            {
                rez[i-'0']=0;}
            }
            afis(rez);
    return 0;
}
