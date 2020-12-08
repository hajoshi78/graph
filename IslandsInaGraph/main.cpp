/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on December 8, 2020, 12:12 PM
 */

#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Graph{
private:    
    int vertexCount;
    int *edges[];
public:
    Graph(int numOfVertex){
        vertexCount = numOfVertex;
        for(int i=0;i<vertexCount;i++){
            edges[i] = new int[vertexCount];
        }
    }
    Graph(int numOfVertex, int arr[][5]){
        vertexCount = numOfVertex;
        for(int i=0;i<vertexCount;i++){
            edges[i] = new int[vertexCount];
        }
        
        
        for(int i=0;i<vertexCount;i++){
            for(int j=0;j<vertexCount;j++){
                edges[i][j] = arr[i][j];
            }
        }
    }
    ~Graph(){
        for(int i=0;i<vertexCount;i++){
            delete edges[i];
        }
    }
    void addEdge(int u, int v){
        edges[u][v]=1;
    }
    void removeEdge(int u, int v){
        edges[u][v]=0;
    }
    void displayGraph(){
        cout<<"[";
        for(int i=0;i<vertexCount;i++){
            for(int j=0;j< vertexCount;j++){
                cout <<edges[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<"]";
    }
    void dfs(int i, int j){
        if( i>=vertexCount || i<0 || j>=vertexCount || j<0){
            return;
        }
        if(edges[i][j] ==1 ){
            edges[i][j]=0;
            dfs(i+1,j);
            dfs(i-1,j);
            dfs(i,j-1);
            dfs(i,j+1);
        }
    }
    
    int numOfIslandsInGraph(){
        int islandCount=0;
        for(int i=0;i<vertexCount;i++){
            for(int j=0;j< vertexCount;j++){
                if(edges[i][j]==1){
                    islandCount++;
                    dfs(i,j);
                }
            }
        }
        
        return islandCount;
    }
};

/*
 * 
 */
int main(int argc, char** argv) {
    int arr[][5]={
                     { 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 } 
                };
    Graph g(5, arr);
    
    cout<<"Number of islands in Graph is " << g.numOfIslandsInGraph();
    return 0;
}

