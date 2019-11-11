#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int curr;
    for(int i=0 ; i < n - 1; i++){
        cin>>curr;
        if(curr >= 100){
            cout<<100<<" ";
        } else if(curr >= 10){
            cout<<10<<" ";
        } else {
            cout<<1<<" ";
        }
    }
    cout<<1;
    return 0;
}
