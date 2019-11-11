#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int* arr;
int* dp_false;
int* dp_true;

long long getMinThread(int at, bool hasToBeTied){
    if(at == n - 1){
        if(hasToBeTied){
            dp_true[at] = arr[at] - arr[at - 1];
            return arr[at] - arr[at - 1];
        } else {
            dp_false[at] = 0;
            return 0;
        }
    }
    int connectCost = arr[at + 1] - arr[at];
    int minForPosition;
    if(hasToBeTied){
        if(dp_true[at] != -1){
            return dp_true[at];
        }
        minForPosition = connectCost + getMinThread(at + 1, false);
        dp_true[at] = minForPosition;
    } else {
        if(dp_false[at] != -1){
            return dp_false[at];
        }
        int withTie = connectCost + getMinThread(at + 1, false);
        int withoutTie = getMinThread(at + 1, true);
        minForPosition = min(withTie, withoutTie);
        dp_false[at] = minForPosition;
    }
    return minForPosition;
}

int main(){

    cin>>n;
    arr = new int[n];
    dp_false = new int[n];
    dp_true = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        dp_false[i] = -1;
        dp_true[i] = -1;
    }
    sort(arr, arr + n);
    cout<<getMinThread(0, true);
    return 0;
}
