#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

int n;
int m;
vector<vector<int>> graph;
int* dp;

int findLongestPath(int start){
    if(dp[start] != -1){
        return dp[start];
    }
    if(graph[start].size() == 0){
        return 0;
    }
    int longest = INT_MIN;
    for(int i = 0; i < graph[start].size(); i++){
        longest = max(longest, 1 + findLongestPath(graph[start][i]));
    }
    dp[start] = longest;
    return longest;
}

int main(){
    
    cin>>n>>m;
    graph.resize(n+1);
    dp = new int[n+1];
    int from, to;

    for(int i = 0; i < m; i ++){
        cin>>from>>to;
        graph[from].push_back(to);
    }

    for(int i = 0; i <= n; i++){
        dp[i] = -1;
    }
    int res = INT_MIN;
    for(int i = 1; i <= n; i++){
        res = max(res, findLongestPath(i));
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j < graph[i].size(); j++){
    //         cout<<i<<" -> "<<graph[i][j]<<endl;
    //     }
    // }

    cout<<res;
    return 0;
}

/*

1-2-3-4
  \ |
    5
*/
