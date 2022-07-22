#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>


int n;
std::vector<std::vector<int>>  capacity;
std::vector<std::vector<int>>  adj;
int parseInput();
int bfs(int, int, std::vector<int>&);
int maxflow(int, int);


int bfs(int s, int t, std::vector<int>& parent) {
    std::fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    std::queue<std::pair<int, int>> q;
    q.push({s, 1000000000});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = std::min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int parseInput(){
    char in[100];
    int n1,v1,v2;
    float c;

    std::fgets(in,sizeof(in),stdin);//dl
    std::fgets(in,sizeof(in),stdin);//edgelist1
    std::fgets(in,sizeof(in),stdin);//n=10\n

    std::sscanf(in,"n=%d\n",&n1);

    for(int i = 0;i<n1;i++){
        std::vector<int> capVec(n1);
        std::vector<int> adjVec;
        capacity.push_back(capVec);
        adj.push_back(adjVec);
    }
    std::fgets(in,sizeof(in),stdin);//data:
    while(std::fgets(in,sizeof(in),stdin)!=NULL){
        if(std::sscanf(in,"%d %d %f\n",&v1,&v2,&c)!=3){
            break;
        }
       capacity[v1-1][v2-1] = c;
       adj[v1-1].push_back(v2-1);
       adj[v2-1].push_back(v1-1);

    }
    n=n1;
    return n1-1;
}

int main(int argc, char const *argv[])
{
    int numNodes = parseInput();
    int flow = maxflow(0,numNodes);
    std::cout << flow;

}

int maxflow(int s, int t) {
    int flow = 0;
    std::vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}