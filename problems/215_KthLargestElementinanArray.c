/*
https://leetcode.com/problems/kth-largest-element-in-an-array/description
difficulty: medium

Problem:
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

//Solution

int quickSelect(int* nums, int numsSize, int k) {
    int pivot = nums[rand() % numsSize];  

    // Arrays to partition elements
    int* left = (int*)malloc(numsSize * sizeof(int));
    int* mid = (int*)malloc(numsSize * sizeof(int));
    int* right = (int*)malloc(numsSize * sizeof(int));

    int leftSize = 0, midSize = 0, rightSize = 0;

    // Partitioning elements into three groups
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > pivot) {
            left[leftSize++] = nums[i];
        } else if (nums[i] < pivot) {
            right[rightSize++] = nums[i];
        } else {
            mid[midSize++] = nums[i];
        }
    }

    int result;
    if (k <= leftSize) {
        result = quickSelect(left, leftSize, k);
    } else if (k > leftSize + midSize) {
        result = quickSelect(right, rightSize, k - leftSize - midSize);
    } else {
        result = pivot;
    }

    // Free allocated memory
    free(left);
    free(mid);
    free(right);

    return result;
}

// Main function to find the k-th largest element
int findKthLargest(int* nums, int numsSize, int k) {
    return quickSelect(nums, numsSize, k);
}