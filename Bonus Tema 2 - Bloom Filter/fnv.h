
#pragma once

#include <string>
#include <cassert>


// 32 bit integers
#ifdef _MSC_VER
typedef unsigned int uint32_t;
#else
#include <stdint.h>
#endif


namespace FNV {
// default values recommended by https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function
const uint64_t Prime = 0x00000100000001B3; //   16777619
const uint64_t offset_basis  = 0xcbf29ce484222325; // 2166136261

/// hash a single byte
inline uint64_t fnv1a(unsigned char oneByte, uint64_t hash = offset_basis) {
    return (oneByte ^ hash) * Prime;
    // FNV1: return (oneByte * Prime) ^ hash;
}

/// hash a 64 bit integer (eight bytes)
inline uint32_t fnv1a(uint64_t eight, uint64_t hash = offset_basis) {
    const unsigned char* ptr = (const unsigned char*) &eight;
    for(int i=0;i<7;i++)
        hash = fnv1a(*ptr++, hash);
    return fnv1a(*ptr, hash);
}


}
