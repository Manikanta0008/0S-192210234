#include <stdio.h>
struct Process {
    int pid;        // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int priority;   // Priority
    int remaining;  // Remaining burst time
    int waiting;    // Waiting time
    int turnaround; // Turnaround time
};

void priorityScheduling(struct Process proc[], int n) {
    int t = 0, completed = 0;
    while (completed < n) {
        int minPriority = 1e9, idx = -1;
        for (int i = 0; i < n; i++) {
            if (proc[i].arrival <= t && proc[i].remaining > 0 && proc[i].priority < minPriority) {
                minPriority = proc[i].priority;
                idx = i;
            }
        }
        if (idx != -1) {
            t++;
            proc[idx].remaining--;
            if (proc[idx].remaining == 0) {
                completed++;
                proc[idx].turnaround = t - proc[idx].arrival;
                proc[idx].waiting = proc[idx].turnaround - proc[idx].burst;
            }
        } else {
            t++;
        }
    }
}

int main() {
    struct Process proc[] = {
        {1, 0, 10, 2, 10, 0, 0},
        {2, 1, 5, 0, 5, 0, 0},
        {3, 2, 8, 1, 8, 0, 0}
    };
    int n = sizeof(proc) / sizeof(proc[0]);
    priorityScheduling(proc, n);
    for (int i = 0; i < n; i++) {
        printf("P%d: Waiting Time = %d, Turnaround Time = %d\n", proc[i].pid, proc[i].waiting, proc[i].turnaround);
    }
    return 0;
}

