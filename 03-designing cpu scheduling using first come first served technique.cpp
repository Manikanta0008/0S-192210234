#include <stdio.h>

typedef struct {
    int process_id;
    int burst_time;
    int start_time;
    int finish_time;
} Process;

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process processes[n];
    for (i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }
    processes[0].start_time = 0;
    processes[0].finish_time = processes[0].burst_time;
    for (i = 1; i < n; i++) {
        processes[i].start_time = processes[i - 1].finish_time;
        processes[i].finish_time = processes[i].start_time + processes[i].burst_time;
    }
    printf("\nProcess ID\tStart Time\tFinish Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].start_time, processes[i].finish_time);
    }

    return 0;
}

