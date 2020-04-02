## Bloom Filter - Double Hashing implementation using FNV for hash function.


### What can it do?
A Bloom filter is a data structure designed to tell you, rapidly and memory-efficiently, whether an element is present in a set.
The price paid for this efficiency is that a Bloom filter is a probabilistic data structure: it tells us that the element either definitely is not in the set or may be in the set.

### How does it work? 
Given an array of *m bits*, we can store a value by hashing it using *k functions* and set those k bits to 1. We check whether or not a value is in the set by repeating this operation and checking if all those bits are set to 1.

## Probability of False Positive VS Filter Size

Below is a table showcasing the required space for each element in the filter in relation to the probability of false positive, assuming that the number of hash functions is optimal.

| False Positive Chance 	|  Bits/Element 	| Total Size For 10^7 elements 	|
|:---------------------:	|:-------------:	|:----------------------------:	|
|          10%          	|      4.8      	|              6MB             	|
|           5%          	|      6.2      	|            7.75MB            	|
|           3%          	|      7.3      	|            9.12MB            	|
|           1%          	|      9.6      	|             12MB             	|
|          0.1%         	|     14.35     	|             18MB             	|
|         0.01%         	|     19.13     	|             24MB             	|

Because computer memory isn't such a big concern nowadays, we can use a false positive chance of 0.01% to ensure the Bloom Filter's accuracy even though is makes the required space to be 4 times bigger than using a 10% probability of false positive.
