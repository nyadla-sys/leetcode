/*
https://leetcode.com/problems/subarray-sum-equals-k/description
difficulty: medium

Problem:
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107

*/

//Solution
// Hash map implementation for storing sum frequencies
typedef struct HashNode {
    int key;
    int value;
    struct HashNode* next;
} HashNode;


#define HASH_SIZE 1000

typedef struct {
    HashNode* table[HASH_SIZE];
} HashMap;

unsigned int hash(int key) {
    return (key % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
}

void insert(HashMap* map, int key, int value) {
    unsigned int index = hash(key);
    HashNode* node = map->table[index];
    while (node) {
        if (node->key == key) {
            node->value += value;
            return;
        }
        node = node->next;
    }
    node = (HashNode*)malloc(sizeof(HashNode));
    node->key = key;
    node->value = value;
    node->next = map->table[index];
    map->table[index] = node;
}

int get(HashMap* map, int key) {
    unsigned int index = hash(key);
    HashNode* node = map->table[index];
    while (node) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return 0;
}

void free_map(HashMap* map) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashNode* node = map->table[i];
        while (node) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
}

int subarraySum(int* nums, int numsSize, int k) {
    int count = 0, sum = 0;
    HashMap map;
    memset(map.table, 0, sizeof(map.table));
    insert(&map, 0, 1); // Initialize with sum 0

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        count += get(&map, sum - k);
        insert(&map, sum, 1);
    }

    free_map(&map);
    return count;
}
