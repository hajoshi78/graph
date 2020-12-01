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
using namespace std;

class Graph{
private:
    int nodeCount;
    vector<int>* adjList;
public:
    Graph(int numOfNodes){
        this->nodeCount = numOfNodes;
        adjList = new vector<int>[numOfNodes];
    }
    ~Graph(){
        delete []adjList;
        adjList=NULL;
    }
    //undirected Graph
    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
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
        
        count=0;
        for(it = adjList[v].begin();it!=adjList[v].end();it++){
            if(*it == u){
                break;
            }
            count++;
        }
        adjList[v].erase(adjList[v].begin()+count);
    }
    void displayGraph(){
        for( int i=0;i<nodeCount;i++){
            cout <<endl<<"Node : " <<i;
            for(auto x: adjList[i]){
                cout <<"-->" <<x;
            }
        }
    }
};



/*
 * 
 */
int main(int argc, char** argv) {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    
    g.displayGraph();
    
    g.removeEdge(0,1);
    g.removeEdge(0,2);
    g.displayGraph();
    
    return 0;
}

