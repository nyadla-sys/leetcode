/*
https://leetcode.com/problems/word-pattern/description/
difficulty: easy

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.
 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"

Output: true

Explanation:

The bijection can be established as:

'a' maps to "dog".
'b' maps to "cat".
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"

Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"

Output: false

 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.

*/

//solution
bool wordPattern(char* pattern, char* s) {
  char* hash[26] = {0};
  char* word;
  int wordcount = 0;
  char* words[strlen(s)];

  word = strtok(s, " ");

  while (word != NULL) {
    words[wordcount] = malloc(strlen(word) + 1);
    strcpy(words[wordcount], word);
    wordcount++;
    word = strtok(NULL, " ");
  }

  if (wordcount != strlen(pattern)) {
      return false;
  }
  for (int i = 0; i < strlen(pattern); i++) {
    int index = pattern[i]-'a';
    if (hash[index]) {
      if (strcmp(hash[index], words[i]) != 0)
          return false;

    } else {
        for (int j = 0; j < 26; j++) {
          if (hash[j] && strcmp(hash[j], words[i]) == 0)
              return false;
        }
        hash[index] = malloc(strlen(words[i]) + 1);
        strcpy(hash[index], words[i]);
    }
  }
  return true;
}