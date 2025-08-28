#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();

        sort(tasks.rbegin(), tasks.rend());
        sort(workers.rbegin(), workers.rend());

        int count = 0;
        int i = 0, j = 0;

        auto print = [&](auto str, auto arr, int start) {
            cout << str << ": ";
            for (int i = start; i < arr.size(); ++i) cout << arr[i] << " ";
            cout << endl;
        };
        auto debug = [&]() {
            print("Tasks", tasks, i);
            print("Workers", workers, j);
            cout << "Pills: " << pills << endl;
            cout << "Count: " << count << endl
                 << endl;
        };

        debug();
        while (i < n && j < m) {
            if (workers[j] >= tasks[i]) {
                ++i;
                ++j;
                ++count;
            } else if (pills > 0 && workers[j] + strength >= tasks[i]) {
                ++i;
                ++j;
                ++count;
                --pills;
            } else {
                ++i;
            }

            debug();
        }

        return count;
    }
};