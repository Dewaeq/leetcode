#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *newNode() {
  struct ListNode *node = malloc(sizeof(struct ListNode));
  node->next = NULL;
  node->val = 0;
  return node;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode *result = newNode();
  struct ListNode *ret = result;

  int carry = 0;

  while (l1 || l2 || carry) {
    int sum = carry;
    if (l1) {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      sum += l2->val;
      l2 = l2->next;
    }

    carry = sum / 10;

    result->val = sum % 10;

    if (l1 || l2 || carry) {
      result->next = newNode();
      result = result->next;
    }
  }

  return ret;
}

struct ListNode *createList(int *values, int n) {
  struct ListNode *head = malloc(sizeof(struct ListNode));
  struct ListNode *p = head;

  for (int i = 0; i < n; i++) {
    p->val = *values;
    if (i != n - 1) {
      p->next = newNode();
      p = p->next;
    }
    values++;
  }

  return head;
}

void printList(struct ListNode *head) {
  struct ListNode *p = head;

  while (p) {
    printf("%d\n", p->val);
    p = p->next;
  }

  assert(p != head);
}

int main(int argc, char *argv[]) {

  int values1[3] = {2, 4, 3};
  struct ListNode *l1 = createList(values1, sizeof(values1) / sizeof(int));

  printf("l1:\n");
  printList(l1);

  int values2[3] = {5, 6, 4};
  struct ListNode *l2 = createList(values2, sizeof(values2) / sizeof(int));

  printf("l2:\n");
  printList(l2);

  struct ListNode *result = addTwoNumbers(l1, l2);

  printf("result:\n");
  printList(result);

  return EXIT_SUCCESS;
}
