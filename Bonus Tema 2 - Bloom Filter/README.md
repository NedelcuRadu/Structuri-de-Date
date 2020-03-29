## Bloom Filter - Double Hashing implementation using FNV for hash function.


### What can it do?
A Bloom filter is a data structure designed to tell you, rapidly and memory-efficiently, whether an element is present in a set.
The price paid for this efficiency is that a Bloom filter is a probabilistic data structure: it tells us that the element either definitely is not in the set or may be in the set.

### How does it work? 
Given an array of *m bits*, we can store a value by hashing it using *k functions* and set those k bits to 1. We check whether or not a value is in the set by repeating this operation and checking if all those bits are set to 1.
