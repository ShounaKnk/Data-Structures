
#include <iostream>
using namespace std;
#define MAX 10

void printGChart(int n, double burst_time[], double arrival_time[], double waiting_time[], double turn_around_time[]) {

    double ganttChart[MAX] = {0};
    cout << endl << endl << "Gantt Chart : " << endl;
    for(int i={}; i<n; i++) {
        cout << "+----------";
    } cout << "+";

    cout << endl << "|    ";
    for(int i=0; i<n; i++) {
        cout << "P" << i << "    |    ";
    }
    cout << endl;
    for(int i={}; i<n; i++) {
        cout << "+----------";
    } cout << "+";
    ganttChart[0] = arrival_time[0];
    for(int i=1; i<=n; i++) ganttChart[i] = ganttChart[i-1] + burst_time[i-1];

    cout << endl << arrival_time[0] << " ";
    for(int i=0; i<n; i++) {
        cout << "         " << ganttChart[i];
    }
}
void firstComeFirstServe(int n, double burst_time[], double arrival_time[], double waiting_time[], double turn_around_time[]) {

    waiting_time[0] = 0;
    for(int i=1; i<n; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }
    cout << endl << "Process\t\tBurstTime\tArrivalTime\tWaitingTime\tTurnAroundTime" << endl;
    for(int i={}; i<n; i++) {
        turn_around_time[i] = waiting_time[i] + burst_time[i]; // computing turn_around_time....
        cout << endl << "P" << i << "\t\t"<< burst_time[i] << "\t\t"<< arrival_time[i] << "\t\t"<< waiting_time[i] << "\t\t"<< turn_around_time[i];
    }
    float sum_w = {};
    float sum_t = {};
    for(int i={}; i<n; i++) {
        sum_w += waiting_time[i];
        sum_t += turn_around_time[i];
    }
    cout << endl << endl << "Average waiting time     : " << (sum_w / n);
    cout << endl << "Average turn around time : " << (sum_t / n);

    printGChart(n, burst_time, arrival_time, waiting_time, turn_around_time);
}

int main() {

    int n = {};
    cout << "Enter the no. of processes : ";
    cin >> n;

    double burst_time[MAX];
    double arrival_time[MAX];
    double waiting_time[MAX];
    double turn_around_time[MAX];

    cout << "Enter the burst time for each process : ";
    for(int i{}; i<n; i++) {
        cin >> burst_time[i];
        arrival_time[i] = i;
    }
    firstComeFirstServe(n, burst_time, arrival_time, waiting_time, turn_around_time);
    return 0;
}