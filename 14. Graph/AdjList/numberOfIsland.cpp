class Graph{
public:
    map<int, vector<int>> adjList;

    void add(int from, int to){
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }


    void dfs(int src, map<int, bool> &visited){
        visited[src] = true;

        for(auto i: adjList[src]){
            if(!visited[i]){
                dfs(i, visited);
            }
        }
    }

    void print(){
        for(auto i: adjList){
            cout<<i.first<<" ";
            for(int j: i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){

    

    return 0;
}