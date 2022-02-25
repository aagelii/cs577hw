#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// from https://www.geeksforgeeks.org/iterative-merge-sort/
/*long long merge(vector<pair<int,int>> pairs, int left, int mid, int right);
long long mergeSort(const vector<pair<int,int>>& pairs, int left, int right){
    long long numInv = 0;
    if (left < right){
        int mid = left + (right - left) / 2;
        numInv += mergeSort(pairs, left, mid);
        numInv += mergeSort(pairs, mid + 1, right);
        numInv += merge(pairs, left, mid, right);
    }
    return numInv;
}
long long merge(vector<pair<int,int>> pairs, int left, int mid, int right){
    int count;
    long long numInv = 0;
    int frontHalf = mid - left + 1;
    int backHalf = right - mid;
    int leftArray[frontHalf], rightArray[backHalf];
    for(int i = 0; i < frontHalf; ++i)
        leftArray[i] = pairs[left + i].second;
    for(int j = 0; j < backHalf; ++j)
        rightArray[j] = pairs[mid + 1 + j].second;
    int x = 0;
    int y = 0;
    count = left;
    while (x < frontHalf && y < backHalf){
        if (leftArray[x] <= rightArray[y]){
            pairs[count].second = leftArray[x];
            ++x;
        }
        else{
            pairs[count].second = rightArray[y];
            ++y;
            numInv += mid - x + 1;
        }
        ++count;
    }
    while (x < frontHalf){
        pairs[count].second = leftArray[x];
        ++x;
        ++count;
    }
    while (y < backHalf){
        pairs[count].second = rightArray[y];
        ++y;
        ++count;
    }
    return numInv;
}*/
long long merge(vector<pair<int,int>>& pairs, int l, int m, int r);
long long mergeSort(vector<pair<int,int>>& pairs, int n){
    long long numInv = 0;
    for (int curr_size=1; curr_size<=n-1; curr_size = 2*curr_size){
        for (int left_start=0; left_start<n-1; left_start += 2*curr_size){
            int mid = min(left_start + curr_size - 1, n-1);
            cout<<"mid "<< mid<<endl;
            int right_end = min(left_start + 2*curr_size - 1, n-1);
            numInv += merge(pairs, left_start, mid, right_end);
        }
    }
    return numInv;
}
long long merge(vector<pair<int,int>>& pairs, int l, int m, int r){
    int i= 0;
    int j = 0;
    int k = l;
    long long numInv = 0;
    int n1 = m - l + 1;
    cout<<"l"<<l<< endl;
    cout<<"m"<<m<<endl;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = pairs[l + i].second;
    for (j = 0; j < n2; j++)
        R[j] = pairs[m + 1+ j].second;
    cout<<"i "<<i<<endl;
    cout<<"j "<<j<<endl;
    cout<<"n1 "<<n1<<endl;
    cout<<"n2 "<<n2<<endl;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            //pairs[k].second = L[i];
            L[i] = pairs[k].second;
            i++;
            k++;
        }
        else{
            // pairs[k].second = R[j];
            R[j] = pairs[k].second;
            j++;
            cout<<"hi"<<endl;
            numInv += m - i + 1;
        }
        k++;
        cout<<k<<endl;
    }
    while (i < n1){
        pairs[k].second = L[i];
        i++;
        k++;
    }
    while (j < n2){
        pairs[k].second = R[j];
        j++;
        k++;
    }
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
        long long numInv = mergeSort(pairs, numPairs);
        cout<<numInv<<"\n";
    }
}
/*
 * Test 1 output:
6
8
Test 2 output:
8
2
0
0
5
1
Test 3 output:
190066
27612966
830954138
4727861877
 */