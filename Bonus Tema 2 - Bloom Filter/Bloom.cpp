#include "Bloom.h"
using namespace std;
BloomFilter::BloomFilter(int n, double p): m(round(-log(p) * n / (log(2) * log(2)))), k(round(m * log(2) / n)) {
    arr.assign(m, 0);
};
uint32_t BloomFilter::getBits(const uint64_t value, int startBit, int X) {
    unsigned  mask;
    mask = ((1 << X) - 1) << startBit;
    return value & mask;
}
void BloomFilter::insert(uint64_t const val) {
    auto hashed = FNV::fnv1a(val);
    auto hasha = getBits(hashed, 0, 31);
    auto hashb = getBits(hashed, 32, 63);
    for(auto i = 0; i < k; i++)
        arr[(hasha + i * hashb) % m] = 1;
}
bool BloomFilter::isThere(uint64_t const val) {
    auto hashed = FNV::fnv1a(val);
    auto hasha = getBits(hashed, 0, 31);
    auto hashb = getBits(hashed, 32, 63);
    for(auto i = 0; i < k; i++)
        if(arr[(hasha + i * hashb) % m] == 0)
            return false;
    return true;
}

