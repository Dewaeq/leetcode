#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
  int map[97] = {0};
  int best = 0;
  int start = 0;
  int end = 0;

  while (s[end] != '\0') {
    if (!map[s[end] - 32]) {
      map[s[end] - 32] = 1;

      end++;
      if (end - start > best)
        best = end - start;
    } else {
      map[s[start] - 32] = 0;
      start++;
    }
  }

  return best;
}

int main(int argc, char *argv[]) {

  printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
  printf("%d\n", lengthOfLongestSubstring("bbbbb"));
  printf("%d\n", lengthOfLongestSubstring("pwwkew"));

  return EXIT_SUCCESS;
}
