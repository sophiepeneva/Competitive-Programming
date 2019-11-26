#include<iostream>
#include<map>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

long long* nums;
int n;
map<int, int> dp;

int max(int a, int b) {
    return a >= b ? a : b;
}

int longest(int i, int last) {
    long long num = nums[last];
    if( i == n - 1){
        return nums[i] % nums[last] == 0 ? 1 : 0;
    }
    if(i >= n){
        return 0;
    }
    if (dp.count(last) > 0) {
        return dp[last];
    }
    if (nums[i] % num != 0) {
        int ans = longest(i + 1, last);
        dp[last] = ans;
        return ans;
    }
    int with = 1 + longest(i + 1, i);
    int without = longest(i + 1, last);
    int ans = max(with, without);
    dp[last] = ans;
    return ans;
}

int main() {
    cin >> n;
    nums = new long long[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int l = INT_MIN;
    for(int i = 0; i < n; i++){
        l = max(l, longest(i  + 1, i) + 1);
    }
    cout << l;
    // for(const auto e : dp){
    //     cout<<e.first <<" :  "<<e.second<<endl;
    // }
}
