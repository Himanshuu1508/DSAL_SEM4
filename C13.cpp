#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <queue>
#include <list>
using namespace std;


class Graph{
private:
    int V;
    vector<vector<int> > adjmat; //creating adjacency matrix
    vector<list<int> > adjlist; //creating adjacent list
public:
    Graph(int vertex);
    void add_edge(int u,int v);
    void dfs(int start);
    void bfs(int start);
};

Graph::Graph(int vertex){
    this->V = vertex;
    adjmat.resize(V,vector<int>(V,0)); //adjacency matrix V*V filled with 0's
    adjlist.resize(V);
}
void Graph::add_edge(int u,int v){
    adjmat[u][v] = 1; //take edge input from user
    adjmat[v][u] = 1; //as graph is undirected we set both [i][j] == [j][i] == 1
    
    adjlist[u].push_back(v); //set values
    adjlist[v].push_back(u);
}

void Graph::dfs(int start){
    vector<bool> visited(V,false); //creating boolean array to store visited matrix
    stack<int> st;
    st.push(start); //adding starting point to stack
    visited[start] = true; //marking visited vertex
    while(!st.empty()){
        int curr = st.top(); //stores top
        st.pop();
        cout<<curr;//print popped element
        for(int i = 0;i<V;++i){
            if(adjmat[curr][i] == 1 && visited[i] == false){ //checking if adjmat[curr][i] is
                st.push(i);
                visited[i] = true;
            }
        }
    }
}

void Graph::bfs(int start){
    vector<bool> visited(V,false); //used to mark visited vertices
    queue<int> qu;
    qu.push(start); //steps are
    visited[start] = true;/*i)add starting vertex to queue and mark as visited
                            ii)remove front element from queue and print
                            iii)traverse through adjlist and if vertex not visited push into queue and mark as visited*/
    while(!qu.empty()){
        int curr = qu.front();
        qu.pop();
        cout<<curr;
        for(auto it = adjlist[curr].begin();it!=adjlist[curr].end();++it){
            if(visited[*it] == false){
                qu.push(*it);
                visited[*it] = true;
            }
        }
        
    }
}

int main(){
    int ch,vertex,x,y,edge;
    cout<<"Enter number of locations in college: "<<endl;
    cin>>vertex;
    Graph g1(vertex);
    cout<<"Enter number of paths: ";
    cin>>edge;
    do{
        cout<<"\t\t\t****MENU****\t\t\t"<<endl;
        cout<<"Enter:\n1)Create graph\n2)Perfrom DFS\n3)Perform BFS\n4)Exit"<<endl;
        cin>>ch;
        switch(ch){
        case 1:
                for(int i = 0;i<edge;i++){
                    cout<<"Enter starting point: ";
                    cin>>x;
                    cout<<"Enter ending point: ";
                    cin>>y;
                    g1.add_edge(x,y);
                }
                break;
        case 2:
                cout<<"Enter starting location: ";
                cin>>x;
                cout<<"The locations in college are: ";
                g1.dfs(x);
                break;
        case 3:
                cout<<"Enter starting location: ";
                cin>>x;
                cout<<"The locations in college are: ";
                g1.bfs(x);
                break;
        }
    }
    while(ch>0 && ch<4);
    return 0;
}
