#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  *returnSize = 2;
  int *result = malloc(sizeof(int) * (*returnSize));
  int mapSize = 65536;
  int *map = calloc(mapSize, sizeof(int));

  for (int i = 0; i < numsSize; i++) {
    int n1 = nums[i];
    int n2 = target - n1;

    if (map[(n2 % mapSize + mapSize) % mapSize]) {
      int j = map[(n2 % mapSize + mapSize) % mapSize] - 1;

      if (n1 + nums[j] == target) {
        result[0] = j;
        result[1] = i;
        return result;
      }
    }

    map[(n1 % mapSize + mapSize) % mapSize] = i + 1;
  }

  *returnSize = 0;
  return NULL;
}

int main(int argc, char *argv[]) {
  int nums[4] = {-500000000, 2, 4, -500000000};
  int target = -1000000000;
  int resultSize = 0;

  int *result = twoSum(nums, sizeof(nums) / sizeof(int), target, &resultSize);
  printf("result size: %d\n", resultSize);

  for (int i = 0; i < resultSize; i++) {
    printf("%d ", result[i]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
