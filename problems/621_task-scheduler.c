/*
https://leetcode.com/problems/task-scheduler/description/
difficulty: medium

You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:

Input: tasks = ["A","C","A","B","D","B"], n = 1

Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:

Input: tasks = ["A","A","A", "B","B","B"], n = 3

Output: 10

Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

 
 */
 
 //Solution
 int leastInterval(char* tasks, int tasksSize, int n) {
    if (tasksSize == 0)
        return 0;
    int freq[26] = {0};
    int maxFreq = 0;      
    //count the frequency and max freq count
    for (int i = 0; i < tasksSize; i++) {
        int index = tasks[i] - 'A';
        freq[index]++;
        if (freq[index] > maxFreq)
            maxFreq = freq[index];        
    }

    //cal total time needed for execution
    int time = ((maxFreq - 1) * (n + 1)) ;

    for (int i = 0; i < 26; i++) {
        if (freq[i] == maxFreq)
            time++;
    }    
    
    if (time > tasksSize)
        return time;
    return tasksSize;
}