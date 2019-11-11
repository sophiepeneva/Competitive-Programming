#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<numeric>
using namespace std;

bool comparator (int a,int b){
    int sizeA = (int)log10(a) + 1;
    int sizeB = (int)log10(b) + 1;
    int size = (a < b) ? sizeA : sizeB;
    for(int i = 1; i <= size; i++){
        int digA = (int)(a/pow(10, sizeA - i))%10;
        int digB = (int)(b/pow(10, sizeB - i))%10;
        if(digA < digB){
            return true;
        }
        if(digB < digA){
            return false;
        }
    }
    return a < b;
}

int main() {

    int n, f, t;
    scanf("%d", &n);
    scanf("%d", &f);
    scanf("%d", &t);
    std::vector<int> nums(n);
    std::iota (std::begin(nums), std::end(nums), 1);
    sort(nums.begin(), nums.end(), comparator);
    for(int i=f-1; i < t;i++)std::cout<<nums[i]<<endl;
    return 0;
}

