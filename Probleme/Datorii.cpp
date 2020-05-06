#include <iostream>
#include <bits/stdc++.h>
using namespace std;
ifstream in("datorii.in");
ofstream out("datorii.out");
class ArbInt
{
private:
    vector<int> arbore;
public:
    ArbInt(vector<int>&nr)
    {
        arbore.reserve(nr.size()*4);
        construire(1,0,nr.size()-1,nr);
    }
    void construire(int nod, int st, int dr, vector<int> & nr)
    {
        if(st == dr)
        {
            arbore[nod] = nr[st];
            return;
        }
        int mid = (st+dr)/2;
        construire(2*nod,st,mid,nr);
        construire(2*nod+1,mid+1,dr,nr);
        arbore[nod] = arbore[nod*2]+arbore[nod*2+1];
    }
    int query(int nod, int st, int dr, int l, int r)
    {
        if(l<=st && dr<= r)
            return arbore[nod];
        int mid = (st+dr)/2;
        int lquery = 0;
        int rquery= 0;
        if(l<=mid)
            lquery = query(2*nod, st, mid, l, r);
        if(mid<r)
            rquery = query(2*nod+1,mid+1,dr,l,r);
        return lquery+rquery;
    }
    void update(int nod, int st, int dr, int val, int poz)
    {
        if(st == dr)
        {
            arbore[nod] += val;
            return;
        }
        int mid = (st+dr)/2;
        if(poz <= mid)
            update(2*nod,st,mid,val,poz);
        else
            update(2*nod+1,mid+1,dr,val,poz);
        arbore[nod] = arbore[nod*2]+arbore[nod*2+1];
    }
};

int main()
{
    int T,N,M,x,y,z,p;
    vector<int> A;
    in>>N>>M;
    A.reserve(N);
    for(int i=0; i<N; i++)
    {
        in >> x;
        A.push_back(x);
    }
    ArbInt H(A);
    while(M--)
    {
        in>>x>>y>>z;
        if(x==0)
            H.update(1,1,N,-z,y);
        else
            out<<H.query(1,1,N,y,z)<<'\n';
    }
    return 0;
}
