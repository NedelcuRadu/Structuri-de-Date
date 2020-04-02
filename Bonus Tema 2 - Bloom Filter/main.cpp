#include <bits/stdc++.h>
#include "Bloom.h"
using namespace std;
ifstream in("data.in");
ofstream out("data.out");
//Format fisier: NR elemente - N
// N linii cu un nr natural pe 64 biti
// Nr queries Q
// Q linii cu nr natural pe 64 biti
int main() {
    int n, mode;
    double p;
    cout << "Fisier(0) sau Consola(1):\n ";
    cin >> mode;
    if (mode) {
        cout << "Cate nr de elemente vrei sa introduci:\n";
        cin >> n;
        cout << "Probabilitatea tolerata pentru fals pozitiv (double):\n";
        cin >> p;
        BloomFilter bloom(n, p);
        cout << "Bloom filter construit.\n";
        cout << "Introduceti cele " << n << " elemente.\n";
        uint64_t a;
        for(auto i = 0; i < n; i++) {
            try {
                cin >> a;
                bloom.insert(a);
            } catch(...) {
                cout << "Elementul nu a putut fi introdus, incercati iar.\n";
                cin >> a;
            }
        }
        uint64_t b;
        while(b != -1) {
            cout << "Dati elementul de verificat (-1 pentru exit): ";
            cin >> b;
            if(bloom.isThere(b))
                cout << b << " are " << 100 - p << " sanse sa fie in filtru\n";
            else
                cout << b << " NU se afla in filtru\n";
        }
    } else
    {   in>>n; // Nr elemente
        p=0.0001; // Probabilitate de false positive de 0.01%
        BloomFilter bloom(n, p);
        uint64_t a;
        for(int i=0;i<n;i++)
            {in>>a;
            bloom.insert(a);}
        in>>n; // Nr queries
        for(int i=0;i<n;i++)
            {in>>a;
            if(bloom.isThere(a))
                out << a << " are " << 100 - p << " sanse sa fie in filtru\n";
            else
                out << a << " NU se afla in filtru\n";}
    }
        return 0;
}
