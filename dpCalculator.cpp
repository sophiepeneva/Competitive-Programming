#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include<map> 

using namespace std;

int n;
map<int, int> dp;

int fastestGrowth(int at){
    if(at == 0){
        return -1;
    }
    if(dp.count(at) > 0){
        return dp[at];
    }
    int minSteps = INT_MAX;
    if(at >= 3 && at % 3 == 0){
        minSteps = min(minSteps, fastestGrowth(at/3) + 1);
    }
    if(at >= 2 && at % 2 == 0){
        minSteps =min(minSteps, fastestGrowth(at/2) + 1);
    }
    minSteps = min(minSteps, fastestGrowth(at - 1) + 1);
    dp[at] = minSteps;
    return minSteps;
}

int main(){

    cin>>n;
    cout<<fastestGrowth(n);
    return 0;
}




