#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id, deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void scheduleJobs(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);
    int n = jobs.size();
    vector<bool> slot(n, false);
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = i;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (slot[i]) cout << jobs[result[i]].id << " ";
    }
    cout << "\n";
}

int main() {
    int testcase, n, d, p;
    cin >> testcase;
    while (testcase--) {
        cin >> n;
        vector<Job> jobs;
        for (int i = 0; i < n; i++) {
            cin >> d >> p;
            jobs.push_back({i + 1, d, p});
        }    
        scheduleJobs(jobs);
    }
    return 0;
}
