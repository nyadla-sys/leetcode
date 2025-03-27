/*
https://leetcode.com/problems/top-k-frequent-elements/description/
difficulty: medium

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

//Solution
typedef struct {
    int num;
    int freq;
} Element;

// A utility function to swap two elements
void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

// Quickselect Partition function
int partition(Element* elements, int left, int right) {
    int pivot = elements[right].freq;
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (elements[j].freq > pivot) {
            i++;
            swap(&elements[i], &elements[j]);
        }
    }
    swap(&elements[i + 1], &elements[right]);
    return i + 1;
}

void quickselect(Element *element,int left,int right,int k) {
    if(left < right){
        int pi = partition(element, left, right);
        if(pi == k-1) return;
        else if(pi >k-1) 
            quickselect(element, left, pi-1,k);
        else
            quickselect(element, pi+1, right,k);

    }
}

// Compare function for sorting the result array (used after quickselect)
int compare(const void* a, const void* b) {
    return ((Element*)b)->freq - ((Element*)a)->freq;
}

// Function to find the top k frequent elements
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    // Create a frequency map (hashmap-like) to count frequencies
    int hashMap[20001] = {0}; // To account for negative numbers (offset by +10000)
    for (int i = 0; i < numsSize; i++) {
        hashMap[nums[i] + 10000]++;
    }

    // Count unique elements
    Element* elements = (Element*)malloc(numsSize * sizeof(Element));
    int uniqueElements = 0;
    for (int i = 0; i < 20001; i++) {
        if (hashMap[i] > 0) {
            elements[uniqueElements].num = i - 10000;
            elements[uniqueElements].freq = hashMap[i];
            uniqueElements++;
        }
    }

    // Perform Quickselect to find the top k frequent elements
    quickselect(elements, 0, uniqueElements - 1, k);


    // Store the result in the output array
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = elements[i].num;
    }

    *returnSize = k; // Set return size
    free(elements);  // Free memory
    return result;   // Return the result
}