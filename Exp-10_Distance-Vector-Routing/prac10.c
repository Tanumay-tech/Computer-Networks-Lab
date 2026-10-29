#include <stdio.h>

#define MAX_NODES 10
#define INF 999

struct node {
    int dist[MAX_NODES];
    int via[MAX_NODES];
} rt[MAX_NODES];

int main() {
    int cost[MAX_NODES][MAX_NODES];
    int nodes, i, j, k, count = 0;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("\nEnter the Cost Matrix (%d x %d):\n", nodes, nodes);
    printf("(Enter 999 for infinity / no direct link)\n");
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            scanf("%d", &cost[i][j]);
            cost[i][i] = 0;
            rt[i].dist[j] = cost[i][j];
            rt[i].via[j] = j;
        }
    }

    do {
        count = 0;
        for (i = 0; i < nodes; i++) {
            for (j = 0; j < nodes; j++) {
                for (k = 0; k < nodes; k++) {
                    if (rt[i].dist[k] + rt[k].dist[j] < rt[i].dist[j]) {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].via[j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count != 0);

    for (i = 0; i < nodes; i++) {
        printf("\n=================================");
        printf("\n   Routing Table for Node %d", i + 1);
        printf("\n=================================");
        printf("\n Destination | Next Hop | Distance ");
        printf("\n-------------|----------|----------");
        for (j = 0; j < nodes; j++) {
            printf("\n     %d       |    %d     |    %d", j + 1, rt[i].via[j] + 1, rt[i].dist[j]);
        }
        printf("\n");
    }

    return 0;
}