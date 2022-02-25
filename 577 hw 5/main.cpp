#include <iostream>
#include <vector>
#include <sstream>
#include <set>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // this code was found on https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
    int instances;
    cin >> instances;
    int numElements;
    for (int i = 0; i < instances; ++i) {
        cin >> numElements;
        vector<int> elements(numElements);
        string input;
        getline(cin, input); // flush
        getline(cin, input);
        istringstream ss(input);
        int curNum;
        int count = 0;
        while (ss>>curNum) {
            elements[count] = curNum;
            count++;
        }
        multiset<int> invSet;
        int numInv = 0;
        multiset<int>::iterator it;
        for (int j=numElements-1; j>=0; j--){
            invSet.insert(elements[j]);
            it = invSet.lower_bound(elements[j]);
            numInv += distance(invSet.begin(), it); // https://www.geeksforgeeks.org/counting-inversions-using-set-in-c-stl/
        }
        cout<<numInv<<"\n";
    }
}
