#include <stdio.h>

int main(void)
{
    int n, m, i, j, k;
    int alloc[10][10], max[10][10];
    int need[10][10], avail[10];
    int finish[10] = {0};
    int safe[10], count = 0, found;

    printf("Enter number of processes (max 10): ");
    scanf("%d", &n);

    printf("Enter number of resources (max 10): ");
    scanf("%d", &m);

    if (n < 1 || n > 10 || m < 1 || m > 10) {
        printf("Invalid number of processes or resources.\\n");
        return 1;
    }

    printf("Enter Allocation Matrix:\\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Maximum Matrix:\\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available Resources:\\n");
    for (j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    /* Calculate Need Matrix */
    printf("\\nNeed Matrix:\\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (max[i][j] < alloc[i][j]) {
                printf("Invalid input: Maximum cannot be less than Allocation.\\n");
                return 1;
            }
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\\n");
    }

    /* Banker's Safety Algorithm */
    while (count < n) {
        found = 0;

        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j])
                        break;
                }

                if (j == m) {
                    for (k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0)
            break;
    }

    if (count == n) {
        printf("\\nSystem is in SAFE state.\\n");
        printf("Safe Sequence: ");
        for (i = 0; i < n; i++)
            printf("P%d%s", safe[i], (i == n - 1) ? "\\n" : " -> ");
    } else {
        printf("\\nSystem is in UNSAFE state.\\n");
        printf("No safe sequence exists.\\n");
    }

    return 0;
}
