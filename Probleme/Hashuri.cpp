#include <iostream>
#include <vector>
#include <list>
#include <fstream>
using namespace std;
ifstream in("hashuri.in");
ofstream out("hashuri.out");
// default values recommended by https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function
const uint64_t Prime = 0x00000100000001B3; //   16777619
const uint64_t offset_basis  = 0xcbf29ce484222325; // 2166136261
class Hash
{
private:
    vector<list<long long int>> A;
    //Daca e nevoie de un hash function mai bun
/// hash a single byte
    inline uint64_t fnv1a1(unsigned char oneByte, uint64_t hash = offset_basis)
    {
        hash = offset_basis;
        return (oneByte ^ hash) * Prime;
        // FNV1: return (oneByte * Prime) ^ hash;
    }

/// hash a 64 bit integer (eight bytes)
    inline uint32_t fnv1a(uint64_t eight, uint64_t hash = offset_basis)
    {
        const unsigned char* ptr = (const unsigned char*) &eight;
        for(int i=0; i<7; i++)
            hash = fnv1a1(*ptr++, hash);
        return fnv1a1(*ptr, hash);
    }
public:
    Hash(size_t nr_elem=0)
    {
        A.resize(nr_elem);
    }

    void add_element(long long int val)
    {
        if(!find(val))
            A[val%A.size()].push_back(val);
    }
    void del_element(long long int val)
    {
        A[val%A.size()].remove(val);
    }
    bool find(long long int val)
    {
        for(auto &i:A[val%A.size()])
            if(i==val)
                return 1;
        return 0;
    }
};
int main()
{
    Hash A(1000231); // E nr prim ca sa fie distributia uniforma
    int N,x,y;
    in>>N;
    while(N--)
    {
        in>>x>>y;
        if(x==1)
            A.add_element(y);
        else if(x==2)
            A.del_element(y);
        else
            out<<A.find(y)<<'\n';
    }
    return 0;
}
