#ifndef BLOOM_H_INCLUDED
#define BLOOM_H_INCLUDED
#pragma once
#include <bits/stdc++.h>
#include "fnv.h"
using namespace std;
class BloomFilter {
    double p; // Probability of false positive
    int n; // Nr de elemente
    size_t m; // Dimensiune array
    vector<bool> arr;
    int k; // Nr de hashes

  public:
    BloomFilter(int n, double p);
    uint32_t getBits(uint64_t value, int startBit, int X) ;
    void insert(uint64_t val);
    bool isThere(uint64_t val);
};

#endif // BLOOM_H_INCLUDED
