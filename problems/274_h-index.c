/*
https://leetcode.com/problems/h-index/description/
difficulty: medium

Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

 

Example 1:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.
Example 2:

Input: citations = [1,3,1]
Output: 1
 

Constraints:

n == citations.length
1 <= n <= 5000
0 <= citations[i] <= 1000
*/

//Solution
int compare(const void* a, const void* b) { return (*(int*)b - *(int*)a); }
int hIndex(int* citations, int citationsSize) {
    qsort(citations, citationsSize, sizeof(int), compare);
    int count = 0;
    for (int i = 0; i < citationsSize; i++) {
        if (citations[i] > i)
            count++;
    }
    return count;
}

int hIndex(int* citations, int citationsSize) {
    int* papers = (int*)calloc(citationsSize + 1, sizeof(int));
    for (int i = 0; i < citationsSize; i++) {
        int c = citations[i];
        if (c >= citationsSize)
            papers[citationsSize]++;
        else
            papers[c]++;
    }

    int k = citationsSize;
    int s = papers[citationsSize];
    while (k > s) {
        k--;
        s += papers[k];
    }

    free(papers);
    return k;
}

