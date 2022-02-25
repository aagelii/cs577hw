#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(vector<vector<int>> &adjMatrix, int m, vector<bool>& seen, vector<int>& parents, int n){
    for(int i=0; i<n;++i){
        if (adjMatrix[m][i] && !seen[i]){
            seen[i]=true;
            if (parents[i]<0 || bfs(adjMatrix, parents[i], seen, parents, n)){
                parents[i]=m;
                return true;
            }
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // this code was found on https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
    int instances;
    cin >> instances;
    int m, n, edges, j, source, destination, maxFlow;
    vector<vector<int>> adjMatrix;
    vector<int> parent;
    vector<bool> seen;
    for (int i=0; i<instances; ++i) {
        maxFlow = 0;
        cin >> m; // 2
        cin >> n; // 2
        cin >> edges; // 4
        adjMatrix = vector<vector<int>>(m, vector<int>(n, 0));
        for(j=0; j<edges; ++j){
            cin>>source;
            cin>>destination;
            adjMatrix[source-1][destination-1] = 1;
        }
        parent= vector<int>(m, -1);
        for(int k=0; k<m; ++k){
            seen = vector<bool>(n, false);
            if(bfs(adjMatrix, k, seen, parent, n)){
                maxFlow++;
            }
        }
        if(maxFlow == m)
            cout<<maxFlow<<" Y"<<"\n";
        else
            cout<<maxFlow<<" N"<<"\n";
    }
    return 0;
}