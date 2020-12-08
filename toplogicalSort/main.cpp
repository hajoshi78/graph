/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on December 7, 2020, 8:18 AM
 */

#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 
 */

class Graph{
private:
    int vertexCount;
    vector<int>*adjList;
public:
    Graph(int vertCnt){
        vertexCount = vertCnt;
        adjList = new vector<int>[vertexCount];
    }
    void addEdge(int u, int v){
        adjList[u].push_back(v);
    }
    void dfsUtil(int src, set<int>& visitedSet, stack<int>& vertStack){
        visitedSet.insert(src);
        for(int i=0; i<adjList[src].size();i++){
            int vert = adjList[src][i];
            if(visitedSet.find(vert)== visitedSet.end()){
                dfsUtil(vert, visitedSet, vertStack);
            }
        }
        vertStack.push(src);
    }
    void topologicalSort(){
        
        set<int> setOfvisitedVertices;
        if(isCycleUtil(0,setOfvisitedVertices, -1)){
            cout<<"We cannot do a topological sorting in a cyclic gaph...";
            return ;
        }
        set<int> visitedSet;
        stack<int> vertStack;
        for(int i=0; i< vertexCount;i++){
            if(visitedSet.find(i)== visitedSet.end()){
                dfsUtil(i, visitedSet, vertStack);
            }
        }
        while(!vertStack.empty()){
            cout<<vertStack.top()<<"-->";
            vertStack.pop();
        }
    }
    
     bool isCycleUtil( int curentVertex, set<int>& setOfvisitedVertices, int parent){
        setOfvisitedVertices.insert(curentVertex);
        set<int>::iterator it;
        for(int i=0; i<adjList[curentVertex].size();i++){
            int vertex = adjList[curentVertex][i];
            //if(vertex!= parent){ // This is allowed in a Directed Graph
            if(setOfvisitedVertices.find(vertex)!=setOfvisitedVertices.end() ){
                return true;
            }
            else{
                if(isCycleUtil(vertex, setOfvisitedVertices, curentVertex)){
                    return true;
                }
            }
           // }
        }
        return false;
    }
    bool checkIfTree(){
        //Graph is a tree
        //if 
        //1. There is no Cycle
        //2. All Nodes are connected
        set<int> setOfvisitedVertices;
        bool result = false;

        if(isCycleUtil(0,setOfvisitedVertices, -1)){
            return false;
        }
        else{
            for( int i=0; i< vertexCount;i++){
                if(setOfvisitedVertices.find(i)== setOfvisitedVertices.end()){
                    return false;
                };
            }
        }
        return true;
    }
};
int main(int argc, char** argv) {
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.topologicalSort();
    return 0;
}

