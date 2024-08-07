#include <stdio.h>
typedef struct {
    int id, priority, burstTime;
} Process;
void scheduleProcesses(Process p[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (p[j].priority < p[j + 1].priority) {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
}
int main() {
    Process p[10];
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);   
    for (int i = 0; i < n; i++) {
        printf("Enter ID, Priority, Burst Time: ");
        scanf("%d %d %d", &p[i].id, &p[i].priority, &p[i].burstTime);
    }
    scheduleProcesses(p, n);
    printf("\nScheduled Processes:\n");
    for (int i = 0; i < n; i++)
        printf("ID: %d, Priority: %d\n", p[i].id, p[i].priority);

    return 0;
}

