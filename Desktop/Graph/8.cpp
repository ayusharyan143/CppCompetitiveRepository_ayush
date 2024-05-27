#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b)
{
    return (a.profit > b.profit);
}

int findMaxDeadline(vector<Job> &jobs)
{
    int max_deadline = 0;
    for (const Job &job : jobs)
    {
        if (job.deadline > max_deadline)
            max_deadline = job.deadline;
    }
    return max_deadline;
}

int jobSequencing(vector<Job> &jobs)
{

    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = findMaxDeadline(jobs);

    int result[maxDeadline] = {0};

    bool slot[maxDeadline] = {false};

    int totalProfit = 0;

    for (const Job &job : jobs)
    {

        for (int j = min(maxDeadline, job.deadline) - 1; j >= 0; j--)
        {
            if (!slot[j])
            {
                result[j] = job.id;
                slot[j] = true;
                totalProfit += job.profit;
                break;
            }
        }
    }

    cout << "Scheduled Jobs: ";
    for (int i = 0; i < maxDeadline; i++)
    {
        if (result[i] != 0)
            cout << result[i] << " ";
    }
    cout << endl;

    return totalProfit;
}

int main()
{
    vector<Job> jobs = {
        {1, 3, 50},
        {2, 4, 10},
        {3, 5, 40},
        {3, 6, 70},
    };

    int maxProfit = jobSequencing(jobs);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
