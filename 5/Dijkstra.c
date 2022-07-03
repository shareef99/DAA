/*
  Question
  From a given vertex in a weighted connected graph, find shortestpaths to other
  vertices using Dijkstra's algorithm.
*/

#include<stdio.h>
#include<conio.h>

#define infinity 999

void dij(int n, int v, int cost[10][10], int dist[100]) {
  int i, u, count, w, flag[10], min;
  for (i = 1;i <= n;i++)
    flag[i] = 0, dist[i] = cost[v][i];
  count = 2;
  while (count <= n) {
    min = 99;
    for (w = 1;w <= n;w++)
      if (dist[w] < min && !flag[w])
        min = dist[w], u = w;
    flag[u] = 1; count++;
    for (w = 1;w <= n;w++)
      if ((dist[u] + cost[u][w] < dist[w]) && !flag[w])
        dist[w] = dist[u] + cost[u][w];
  }
}

void main() {
  int n, v, i, j, cost[10][10], dist[10];
  printf("Enter the number of nodes: ");
  scanf("%d", &n);
  printf("Enter the cost matrix: \n");
  for (i = 1;i <= n;i++)
    for (j = 1;j <= n;j++) {
      scanf("%d", &cost[i][j]);
      if (cost[i][j] == 0)
        cost[i][j] = infinity;
    }
  printf("Enter the source matrix: ");
  scanf("%d", &v);
  dij(n, v, cost, dist);
  printf("Shortest path:\n");
  for (i = 1;i <= n;i++)
    if (i != v)
      printf("%d->%d,cost=%d\n", v, i, dist[i]);
}


/*

OUTPUT:-
Enter the number of nodes: 5
Enter the cost matrix:
0   2   12  17  999
999 0   999 8   7
999 999 0   9   999
999 999 999 0   999
999 999 999 999 0
Enter the source matrix: 1
Shortest path:
1->2,cost=2
1->3,cost=12
1->4,cost=10
1->5,cost=9

*/