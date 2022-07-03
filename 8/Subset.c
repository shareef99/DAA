

#include<stdio.h>
#include<conio.h>

int s[10], x[10], d;

void sumOfSub(int, int, int);

void main() {
  int n, sum = 0;int i;
  printf("Enter the size of the set: ");
  scanf("%d", &n);
  printf("Enter the set in increasing order: \n");
  for (i = 1; i <= n; i++)
    scanf("%d", &s[i]);
  printf("Enter the value of d: ");
  scanf("%d", &d);
  for (i = 1; i <= n; i++)
    sum = sum + s[i];
  if (sum < d || s[1] > d)
    printf("\nNo subset possible");
  else
    sumOfSub(0, 1, sum);
}

void sumOfSub(int m, int k, int r) {
  int i = 1; x[k] = 1;
  if ((m + s[k]) == d) {
    printf("Subset:");
    for (i = 1; i <= k; i++)
      if (x[i] == 1)
        printf("\t%d", s[i]);
    printf("\n");
  }
  else if (m + s[k] + s[k + 1] <= d)
    sumOfSub(m + s[k], k + 1, r - s[k]);
  if ((m + r - s[k] >= d) && (m + s[k + 1] <= d)) {
    x[k] = 0;
    sumOfSub(m, k + 1, r - s[k]);
  }
}


/*

OUTPUT:-
Enter the size of the set: 5
Enter the set in increasing order:
1 2 5 6 8
Enter the value of d: 9
Subset: 1       2       6
Subset: 1       8

*/