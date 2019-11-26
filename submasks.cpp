#include<iostream>
#include<vector>
#include<set>

using namespace std;

bool isSet(int n, int k)
{
    return n & (1 << (k));
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    set<int> s;
    s.insert(0);
    for (int i = 0; i < n; i++) {
        vector<int> v;
        v.push_back(0);
        for (int j = 0; j < 18; j++) {
            if (isSet(arr[i], j)) {
                int curr = v.size();
                for (int k = 0; k < curr; k++) {
                    int next = ((1 << j) | v[k]);
                    s.insert(next);
                    v.push_back(next);
                }
            }
        }
    }
    cout << s.size();
}
