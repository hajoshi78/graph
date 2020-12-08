/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on December 6, 2020, 8:31 PM
 */

#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class UnDirectedGraph{
private: 
    int vertexCount;
    vector<int> *edges;
public:
    UnDirectedGraph(int numOfVertices){
        vertexCount = numOfVertices;
        edges = new vector<int>[vertexCount];
    }
    ~UnDirectedGraph(){
        delete [] edges;
    }
    void addEdge(int u, int v){
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    void displayGraph(){
        for(int i=0;i<vertexCount;i++){
            cout <<endl<<"Vertex " << i;
            for(auto x :edges[i]){
                cout<< "-->"<<x;
            }
        }    
    }
    bool isCycleUtil( int curentVertex, set<int>& setOfvisitedVertices, int parent){
        setOfvisitedVertices.insert(curentVertex);
        set<int>::iterator it;
        for(int i=0; i<edges[curentVertex].size();i++){
            int vertex = edges[curentVertex][i];
            if(vertex!= parent){
                if(setOfvisitedVertices.find(vertex)!=setOfvisitedVertices.end() ){
                    return true;
                }
                else{
                    if(isCycleUtil(vertex, setOfvisitedVertices, curentVertex)){
                        return true;
                    }
                }
            }
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


class DirectedGraph{
private: 
    int vertexCount;
    vector<int> *edges;
public:
    DirectedGraph(int numOfVertices){
        vertexCount = numOfVertices;
        edges = new vector<int>[vertexCount];
    }
    ~DirectedGraph(){
        delete [] edges;
    }
    void addEdge(int u, int v){
        edges[u].push_back(v);
        //edges[v].push_back(u);
    }
    void displayGraph(){
        for(int i=0;i<vertexCount;i++){
            cout <<endl<<"Vertex " << i;
            for(auto x :edges[i]){
                cout<< "-->"<<x;
            }
        }    
    }
    bool isCycleUtil( int curentVertex, set<int>& setOfvisitedVertices, int parent){
        setOfvisitedVertices.insert(curentVertex);
        set<int>::iterator it;
        for(int i=0; i<edges[curentVertex].size();i++){
            int vertex = edges[curentVertex][i];
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
    
    void dfsUtil(int currentVertex, bool (&visited)[] ){
        visited[currentVertex]= true;
        int vertex=0;
        for(int i=0;i<edges[currentVertex].size();i++){
            vertex= edges[currentVertex][i];
            if(!visited[vertex]){
                dfsUtil(vertex, visited);
            }
        }
    }
    
};

/*
 * 
 */
int main(int argc, char** argv) {
    UnDirectedGraph g(8);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    //g.addEdge(5,2); uncommenting this should return 0
    //g.addEdge(5,6);//uncommenting this should return 1
    g.addEdge(6,7);//commenting this should return 1
    cout << "Is Graph a Tree? " <<g.checkIfTree();
    
    
    
    DirectedGraph dg(8);
    dg.addEdge(0,1);
    dg.addEdge(0,2);
    dg.addEdge(2,3);
    dg.addEdge(3,4);
    dg.addEdge(4,5);
    dg.addEdge(5,2); 
    //dg.addEdge(5,6);
    dg.addEdge(6,7);
    //dg.addEdge(1,0);
    cout <<endl<< "Is Graph a Tree? " <<dg.checkIfTree();
    return 0;
}

