#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include <bits/stdc++.h> 

using namespace std;

int n;
int** matrix;
int** dp;
//map<int, set<int>> visited;

bool isValid(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < n;
}

int getCheapestPath(int i, int j){
    if(i == n - 1){
        dp[i][j] = matrix[i][j];
        return matrix[i][j];
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int cheapest = INT_MAX;

    if(isValid(i + 1, j - 1)){
        cheapest = min(cheapest, matrix[i][j] + getCheapestPath( i + 1, j - 1));
    }
    if(isValid(i + 1, j)){
        cheapest = min(cheapest, matrix[i][j] + getCheapestPath( i + 1, j));
    }
    if(isValid(i + 1, j + 1)){
        cheapest = min(cheapest, matrix[i][j] + getCheapestPath( i + 1, j + 1));
    }
    //visited[i].insert(j);
    dp[i][j] = cheapest;
    return cheapest;
}

int main(){
    
    cin>>n;
    cin.ignore();
    matrix = new int*[n];
    dp = new int*[n];
    for(int i = 0; i < n; i++){
        matrix[i] = new int[n];
        dp[i] = new int[n];
    }

    for(int i = 0; i < n; i++){    
        string row;
        getline(cin, row);
        for(int j = 0; j < n; j++){
            dp[i][j] = -1;
            matrix[i][j] = row[j] - '0';
        }    
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j ++){
    //         cout<<matrix[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int cheapest = INT_MAX;
    for(int i = 0; i < n; i++){
        //visited.clear();
        cheapest = min(cheapest, getCheapestPath(0, i));
    }
    cout<<cheapest;
    return 0;
}
