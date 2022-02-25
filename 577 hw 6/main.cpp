#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// from https://www.geeksforgeeks.org/counting-inversions/
long long mergeHelper2(vector<pair<int,int>>& pairs, int temp[], int left, int mid, int right); // removed the & in pairs
long long mergeHelper(vector<pair<int,int>>& pairs, int temp[], int left, int right){ // can look into more efficient mergesort
    int mid = 0;
    long long numInv = 0;
    if (right > left) {
        mid = (right + left) / 2;
        numInv += mergeHelper(pairs, temp, left, mid);
        numInv += mergeHelper(pairs, temp, mid + 1, right);
        numInv += mergeHelper2(pairs, temp, left, mid + 1, right);
    }
    return numInv;
}
long long mergeHelper2(vector<pair<int,int>>& pairs, int temp[], int left, int mid, int right){
    long long numInv = 0;
    int i = left;
    int j = mid;
    int k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (pairs[i].second <= pairs[j].second) {
            temp[k++] = pairs[i++].second;
        }
        else {
            temp[k++] = pairs[j++].second;
            numInv += mid - i;
        }
    }
    while (i <= mid - 1)
        temp[k++] = pairs[i++].second;
    while (j <= right)
        temp[k++] = pairs[j++].second;
    for (i = left; i <= right; ++i)
        pairs[i].second = temp[i];
    return numInv;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // this code was found on https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
    int instances;
    cin >> instances;
    int numPairs;
    for (int i = 0; i < instances; ++i) {
        cin >> numPairs;
        vector<pair<int,int>> pairs (numPairs);
        int cur;
        for(int j = 0; j<numPairs; ++j){
            cin >> cur;
            pairs[j].first=cur;
        }
        for(int k = 0; k<numPairs; ++k){
            cin >> cur;
            pairs[k].second=cur;
        }
        sort(pairs.begin(), pairs.end());
        int temp[numPairs];
        long long numInv = mergeHelper(pairs, temp, 0, numPairs-1);
        cout<<numInv<<"\n";
    }
}