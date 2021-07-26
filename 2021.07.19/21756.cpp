#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    //if (pow(2, log2(n)) != n) return 0;
    //if (n > 8) return 0;
    vector<int> vec(n);
    iota(vec.begin(), vec.end(), 1);
    while (vec.size() > 1) {
        vector<int> tmp;
        for (int i = 0; i < vec.size(); i += 2) vec[i] = 0;
        for (const auto &i : vec) if (i) tmp.push_back(i);
        vec.swap(tmp);
    }
    cout << vec.front();
}
