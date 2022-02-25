#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // this code was found on https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
    int instances;
    cin >> instances;
    int numJobs;
    int s, f, w, j, k, late, curCost;
    for (int i = 0; i < instances; ++i) {
        cin >> numJobs;
        vector<tuple<int, int, int>> jobs(numJobs);
        for (j = 0; j < numJobs; ++j) {
            cin >> s;
            cin >> f;
            cin >> w;
            jobs[j] = make_tuple(s, f, w);
        }
        sort(jobs.begin(), jobs.end(), [](auto &left, auto &right) {
            return get<1>(left) < get<1>(right);
        });
        vector<int> M(numJobs); // 1D array (vector)
        M[0] = get<2>(jobs[0]);
        for (k = 1; k < numJobs; ++k) {
            curCost = get<2>(jobs[k]);
            late = -1;
            for (j = k - 1; j >= 0; --j) {
                if (get<1>(jobs[j]) <= get<0>(jobs[k])) {
                    late = j;
                    break;
                }
            }
            if (late != -1)
                curCost += M[late];
            M[k] = max(curCost, M[k - 1]);
        }
        cout << M[numJobs - 1] << "\n";
    }
    return 0;
}