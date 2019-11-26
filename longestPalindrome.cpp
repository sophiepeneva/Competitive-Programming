#include<iostream>
#include<string>
#include<map>

using namespace std;

map<pair<int, int>, int> dp;

int max(int a, int b) {
    return a >= b ? a : b;
}

int getLenMaxPal(string s, int i , int j) {
    if (i == j) {
        return 1;
    }
    if (i > j) {
        return 0;
    }
    if (dp.count({ i,j }) > 0) {
        return dp[{i,j}];
    }
    if (s[i] == s[j]) {
        return 2 + getLenMaxPal(s, i + 1, j - 1);
    }
    int ans = max(getLenMaxPal(s, i + 1, j), getLenMaxPal(s, i, j - 1));
    dp[{i, j}] = ans;
    return ans;
}

int main() {
    string str;
    cin >> str;
    cout << getLenMaxPal(str, 0, str.length());
}
