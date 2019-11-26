#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long mod = 1e9 + 7;

long long** A = new long long*[5]{new long long [5]{ 3,0,1,1,0 },
    new long long[5]{ 1,0,0,0,0 },
    new long long[5]{ 0,1,0,0,0 },
    new long long[5]{ 0,0,0,1,1 },
    new long long[5]{ 0,0,0,0,1 } };

long long** vect = new long long*[5]{ new long long[1]{0},
new long long[1]{0},
new long long[1]{0},
new long long[1]{3},
new long long[1]{1}};

long long** multiplyMatrices(long long** a, long long** b, int w) {
    long long** m = new long long*[5];
    for (int i = 0; i < 5; i++) {
        m[i] = new long long[w];
        for (int j = 0; j < w; j++) {
            m[i][j] = 0;
            for (int k = 0; k < 5; k++) {
                m[i][j] = (m[i][j] + (a[i][k] * b[k][j])%mod)%mod;
            }
        }
    }
    return m;
}

long long** raiseMatrixToThePowerOf(long long n) {
    if (n == 1) {
        return A;
    }
    if (n % 2 == 0) {
        long long** matrix = raiseMatrixToThePowerOf(n / 2);
        return multiplyMatrices(matrix, matrix, 5);
    }
    return multiplyMatrices(A,raiseMatrixToThePowerOf(n - 1),5);
}

long long f(long long n) {
    long long** m = raiseMatrixToThePowerOf(n - 2);
    long long** res = multiplyMatrices(m, vect, 1);
    return res[0][0] % mod;
}


int main() {
    long long n;
    cin >> n;
    if(n <= 2){
        cout << 0;
    }else{
        cout << f(n);
    }
}
