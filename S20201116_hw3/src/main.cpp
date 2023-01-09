// C++ Program for Floyd Warshall Algorithm
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>
#define INF 1000000000

using namespace std;

int main(int argc, const char * argv[]) {
    
   if (argc < 2) { //no argument passed -> exit
        cout << "Enter File Name. Exiting...";
        return -1;
    }
    ifstream fp(argv[1]);

    string path = argv[1];
    string filename = path.substr(path.find_last_of("/\\") + 1);
    string::size_type const p(filename.find_last_of('.'));
    string file_without_extension = filename.substr(0, p);
    int V = stoi(file_without_extension);
    cout << "number of vertices" << V <<endl;
    
    int u; int v; int w;
    
    vector<vector<int>> graph(V,vector<int> (V, INF));

    if(fp.is_open() && fp.good()){//if opened, get data
        string line = "";
        while (getline(fp, line) >> u >> v >> w ){
            graph[u][v]=w;
        }
    }
    else cout << "Failed to open file..";

    vector<vector<int>> dist(V,vector<int>(V));
   
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    
   
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if(dist[i][k]!=INF and dist[i][k]!=INF){
                    int temp = dist[i][k] + dist[k][j];
                    if (dist[i][j]==INF or dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = temp;
                }
                }
            }
        }
    }
    /* using queue
    priority_queue<pair<int, pair<int, int> > > longest;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            longest.push(make_pair(dist[i][j], make_pair(i,j)));
            printf("%3d", dist[i][j]);
        }
        printf("\n");
    }
    while(!longest.empty()){
        if(longest.top().first!=INF){
            cout << "longest shortest path"<<endl;
            cout << "source: " << longest.top().second.first<<endl;
            cout << "destination: " << longest.top().second.second<<endl;
            cout << "shortest path: " << longest.top().first<<endl;
            break;
        }
        else longest.pop();
    }
    if(longest.empty()) cout << "longest shortest-path not found"<<endl;
 
 */
    //not using queue
    int longest=0; int source=0; int destination=0;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if(dist[i][j] > longest){
                longest =dist[i][j];
                source=i;
                destination =j;
            }
        }
    }
    cout << "longest shortest path"<<endl;
    cout << "source: " << source <<endl;
    cout << "destination: " << destination <<endl;
    cout << "shortest path: " << longest <<endl;
    return 0;
}


