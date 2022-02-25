#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool bfs(vector<vector<int>> &resMatrix, int &sourceNode, int &sinkNode, vector<int> parent, int nodes){
    vector<bool> visit(nodes, false);
    queue<int> nodeCheck;
    nodeCheck.push(sourceNode);
    visit[sourceNode] = true;
    parent[sourceNode] = -1;
    int frontNode, capacity;
    while(!nodeCheck.empty()){
        frontNode = nodeCheck.front();
        nodeCheck.pop();
        for(int i = 0; i < nodes; ++i){
            capacity = resMatrix[frontNode][i];
            if(!visit[i] && capacity > 0){
                nodeCheck.push(i);
                parent[i] = frontNode;
                visit[i] = true;
            }
        }
    }
    if(visit[sinkNode])return true;
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // this code was found on https://www.geeksforgeeks.org/fast-io-for-competitive-programming/
    int instances;
    cin >> instances;
    int nodes, edges, j, source, destination, capacity, maxFlow, sink, pathFlow;
    string temp;
    for (int i = 0; i < instances; ++i) {
        maxFlow = 0;
        cin >> nodes;
        cin >> edges;
        vector<vector<int>> adjMatrix(nodes, vector<int>(nodes,0));
        for(j = 0; j<edges; ++j){
            cin>>source;
            cin>>destination;
            cin>>capacity;
            adjMatrix[source-1][destination-1] += capacity;
        }
        vector<vector<int>> resMatrix = adjMatrix;
        // int parent[nodes];
        // memset(parent, -1, sizeof(parent[0])*nodes);
        vector<int> parent(nodes, -1);
        source = 0;
        sink = nodes-1;
        while(bfs(resMatrix, source, sink, parent, nodes)){
            pathFlow = 2147483647; // INT_MAX
            int tempChild = sink;
            while(tempChild != source){
                int tempParent = parent[tempChild];
                int tempCapacity = resMatrix[tempParent][tempChild];
                pathFlow = min(pathFlow, tempCapacity);
                tempChild = tempParent;
            }
            tempChild = sink;
            while(tempChild != source){
                int tempParent = parent[tempChild];
                resMatrix[tempParent][tempChild] -= pathFlow;
                resMatrix[tempChild][tempParent] += pathFlow;
                tempChild = tempParent;
            }
            maxFlow += pathFlow;
        }
        cout<<maxFlow<<"\n";
    }
    return 0;
}