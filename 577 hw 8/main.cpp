#include <iostream>
#include <vector>
using namespace std;

int knapSack(int capacity, vector<int>weights, vector<int> values, int numItems){
    vector<vector<int>> M(numItems + 1, vector<int>(capacity + 1));
    //int ** M= new int*[numItems+1];
    //int M[numItems+1][capacity+1];
    for(int i = 0; i<=numItems; ++i){
        for(int j = 0; j<=capacity; ++j){
            if(i==0 || j==0)
                M[i][j] = 0;
            else if(weights[i-1] <= j)
                M[i][j] = max(values[i-1]+M[i-1][j-weights[i-1]], M[i-1][j]);
            else
                M[i][j] = M[i-1][j];
        }
    }
    return M[numItems][capacity];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // this code was found on https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
    int instances;
    cin >> instances;
    int numItems, capacity, j, weight, value, l, x, k;
    for (int i = 0; i < instances; ++i) {
        cin >> numItems;
        cin >> capacity;
        vector<int> weights(numItems);
        vector<int> values(numItems);
        for(j = 0; j<numItems;++j){
            cin >> weight;
            cin >> value;
            weights[j] = weight;
            values[j] = value;
        }
        cout<<knapSack(capacity, weights, values, numItems)<<"\n";
    }
    return 0;
}