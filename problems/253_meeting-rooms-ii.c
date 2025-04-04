/*
https://leetcode.com/problems/meeting-rooms-ii/description/
difficulty: medium

Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1
 

Constraints:

1 <= intervals.length <= 104
0 <= starti < endi <= 106

*/

//Solution
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize) {
  int start[intervalsSize];
  int end[intervalsSize];
  for (int i = 0; i < intervalsSize; i++) {
      start[i] = intervals[i][0];
      end[i] = intervals[i][1];
  }
  qsort(start, intervalsSize, sizeof(int), compare);
  qsort(end, intervalsSize, sizeof(int), compare);
  int startindex = 0;
  int endindex = 0;
  int rooms = 0;
  int maxrooms = 0;
  while (startindex < intervalsSize) {
      if (start[startindex] < end[endindex]) {
          rooms++;
          startindex++;
      } else {
          rooms--;
          endindex++;
      }
      if (rooms > maxrooms)
          maxrooms = rooms;
  }
  return maxrooms;
}
