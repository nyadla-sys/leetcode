/*
https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/
difficulty: medium

You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.

Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

 

Example 1:

Input: tasks = [2,2,3,3,2,4,4,4,4,4]
Output: 4
Explanation: To complete all the tasks, a possible plan is:
- In the first round, you complete 3 tasks of difficulty level 2. 
- In the second round, you complete 2 tasks of difficulty level 3. 
- In the third round, you complete 3 tasks of difficulty level 4. 
- In the fourth round, you complete 2 tasks of difficulty level 4.  
It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.
Example 2:

Input: tasks = [2,3,3]
Output: -1
Explanation: There is only 1 task of difficulty level 2, but in each round, you can only complete either 2 or 3 tasks of the same difficulty level. Hence, you cannot complete all the tasks, and the answer is -1.
 

Constraints:

1 <= tasks.length <= 105
1 <= tasks[i] <= 109
 

Note: This question is the same as 2870: Minimum Number of Operations to Make Array Empty.

*/

//Solution
int minimumRounds(int* tasks, int tasksSize) {
  int maxValue = 0;
  for (int i = 0; i < tasksSize; i++) {
      if (tasks[i] > maxValue)
          maxValue = tasks[i];
  }

  int* hash = (int*)calloc(maxValue + 1, sizeof(int));
  if (!hash)
      return -1;
  for (int i = 0; i < tasksSize; i++) {
      hash[tasks[i]]++;
  }

  int count = 0;
  for (int i = 0; i < tasksSize; i++) {
      if (hash[tasks[i]] == 1) {
          free(hash);
          return -1;
      } else if (hash[tasks[i]] > 0) {
          count += hash[tasks[i]]  / 3 + (hash[tasks[i]]  % 3 != 0);
          hash[tasks[i]] = 0;
      }
  }

  free(hash); 
  return count;
}