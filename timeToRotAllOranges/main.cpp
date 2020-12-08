/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: harsh
 *
 * Created on December 8, 2020, 10:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

#define MAXR 5
#define MAXC 5
class Graph{
private:
    int edges[MAXR][MAXC];
public:
    Graph(int arr[MAXR][MAXC]){
        for(int i=0;i<MAXR;i++){
            for(int j=0;j<MAXC;j++){
                edges[i][j] = arr[i][j];
            }
        }
    }
    bool  rotOrange(int i, int j){
        if( i<0 || i>MAXR || j<0 || j>MAXC){
            return false;
        }
        else{
            if(edges[i][j] == 1){
                edges[i][j]=2;
                return true;
            }
        }
        return false;
    }
    int getTimeToRotAllOranges(){
        queue<pair<int,int>> roq;
        int timeCount =0;
        int rotOrangeCount=0;
        for(int i=0;i<MAXR;i++){
            for(int j=0;j<MAXC;j++){
                if(edges[i][j] ==2){
                    roq.push(make_pair(i,j));
                    rotOrangeCount++;
                }
            }
        }
        if( rotOrangeCount ==0){
            return 0;
        }
        else{
            roq.push(make_pair(-1,-1));
            while(!roq.empty()){
                int flag = false;
                while(roq.front().first !=-1 && roq.front().second!=-1){
                    int x= roq.front().first;
                    int y = roq.front().second;
                    if( rotOrange(x-1, y) ){
                        if( flag == false){
                            flag = true;
                            timeCount++;
                        }
                        roq.push(make_pair(x-1,y));
                    }
                    if( rotOrange(x+1, y) ){
                        if( flag == false){
                            flag = true;
                            timeCount++;
                        }
                        roq.push(make_pair(x+1,y));
                    }
                    if( rotOrange(x, y+1) ){
                        if( flag == false){
                            flag = true;
                            timeCount++;
                        }
                        roq.push(make_pair(x,y+1));
                    }
                    if( rotOrange(x, y-1) ){
                        if( flag == false){
                            flag = true;
                            timeCount++;
                        }
                        roq.push(make_pair(x,y-1));
                    }
                    roq.pop();
                }
                roq.pop();
                if(!roq.empty()){
                    roq.push(make_pair(-1,-1)); 
                }
               
            }
            
        }
        
//        for(int i=0;i<MAXR;i++){
//             cout<<endl;
//            for(int j=0;j<MAXC;j++){
//                cout<<edges[i][j]<<"\t";
//            }
//        }
        for(int i=0;i<MAXR;i++){
            for(int j=0;j<MAXC;j++){
                if(edges[i][j] ==1){
                    return -1;  
                }
            }
        }
        return timeCount;
        
    }
};

/*
 * 
 */
int main(int argc, char** argv) {
    
    int arr[MAXR][MAXC]={
        {2,0,1,1,1},
        {1,0,2,1,0},
        {1,0,0,1,1},
        {2,0,0,0,2},
        {0,0,0,0,0}
    };
    Graph g(arr);
    cout <<endl<<"Time taken to rot all Oranges is  " <<g.getTimeToRotAllOranges();
    return 0;
}

