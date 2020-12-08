/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on December 1, 2020, 4:36 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;
enum {
    UNVISITED=-1,
    EXISTS_IN_STACK=0,
    VISITED_REMOVED=1
};
class Graph{
private:
    int nodeCount;
    vector<int>* adjList;
    void DFSUtil(int v, bool visited[])
    {
        // Mark the current node as visited and
        // print it
        visited[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent
        // to this vertex
        vector<int>::iterator i;
        for (i = adjList[v].begin(); i!= adjList[v].end(); ++i){
            if (!visited[*i])
                DFSUtil(*i, visited);
        }   
    }
public:
    Graph(int numOfNodes){
        this->nodeCount = numOfNodes;
        adjList = new vector<int>[numOfNodes];
    }
    ~Graph(){
        delete []adjList;
        adjList=NULL;
    }
    //Directed Graph
    void addEdge(int u, int v){
        adjList[u].push_back(v);
    }
    void removeEdge(int u, int v){
        vector<int>::iterator it;
        int count=0;
        for(it = adjList[u].begin();it!=adjList[u].end();it++){
            if(*it == v){
                break;
            }
            count++;
        }
        adjList[u].erase(adjList[u].begin()+count);
    }
    void displayGraph(){
        for( int i=0;i<nodeCount;i++){
            cout <<endl<<"Node : " <<i;
            for(auto x: adjList[i]){
                cout <<"-->" <<x;
            }
        }
    }
    void DFS(){
        cout<<endl<<"Peforming DFS on Graph :: ";
        bool* visited= new bool[nodeCount];
        for(int i=0;i<nodeCount;i++){
            visited[i]= false;
        }
        int node=0;
        stack<int> dfsStack;
        dfsStack.push(node);
        
        while(!dfsStack.empty()){
            int tempNode = dfsStack.top();
            cout << tempNode <<"\t";
            visited[tempNode]= true;
            dfsStack.pop();
            vector<int>::iterator it;
            for(it= adjList[tempNode].begin();it!=adjList[tempNode].end();it++){
                if(visited[*it]== false){
                    dfsStack.push(*it);
                }
            }
        }
        
    }
    
    void BFS(int src){
        cout<<endl<<"Peforming BFS on Graph :: ";
        bool* visited= new bool[nodeCount];
        for(int i=0;i<nodeCount;i++){
            visited[i]= false;
        }
        int node=src;
        queue<int> bfsQ;
        bfsQ.push(node);
        
        while(!bfsQ.empty()){
            int tempNode = bfsQ.front();
            cout << tempNode <<"\t";
            visited[tempNode]= true;
            bfsQ.pop();
            vector<int>::iterator it;
            for(it =adjList[tempNode].begin();it!=adjList[tempNode].end();it++){
                if(!visited[*it]){
                    visited[*it] = true;
                    bfsQ.push(*it);
                }
            }
            
        }
    }
    
 
    // DFS traversal of the vertices reachable from v.
    // It uses recursive DFSUtil()
    void DFSNew(int v){
        // Mark all the vertices as not visited
        bool* visited = new bool[nodeCount];
        for (int i = 0; i < nodeCount; i++)
            visited[i] = false;
        // Call the recursive helper function
        // to print DFS traversal
        DFSUtil(v, visited);
    }
    
    bool detectCycleIngraph(){
        //USING DFS
        int *nodeTraverseStatus = new int[nodeCount];
        for(int i=0;i<nodeCount;i++){
            nodeTraverseStatus[i] = UNVISITED;
        }
        int srcNode =0;
        map<int,int> parentMap;
        stack<int> dfsStack;
        
        dfsStack.push(srcNode);
        parentMap[srcNode] = -1;
        nodeTraverseStatus[srcNode] = EXISTS_IN_STACK;
        while(!dfsStack.empty()){
            int tempNode = dfsStack.top();

            vector<int>::iterator it;
            for(it = adjList[tempNode].begin();it!= adjList[tempNode].end();it++){
                parentMap[*it]= tempNode;
                if(nodeTraverseStatus[*it]==EXISTS_IN_STACK){
                    return true;
                }
               if(nodeTraverseStatus[*it]==UNVISITED){
                   dfsStack.push(*it);
                   nodeTraverseStatus[*it]=EXISTS_IN_STACK;
               }
            }
            dfsStack.pop();
            nodeTraverseStatus[tempNode]= VISITED_REMOVED;
        }
        return false;
    }
 
};



/*
 * 
 */
int main(int argc, char** argv) {
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(5,6);
    
    g.displayGraph();
    g.DFS();
    cout<<endl;
    
    g.DFSNew(0);
    cout <<endl;
    g.BFS(0);
    
    cout <<endl<<"Checking Cycle in the graph   ::  "<<g.detectCycleIngraph();
    g.removeEdge(0,1);
    g.removeEdge(0,2);
    g.displayGraph();
    
    return 0;
}

