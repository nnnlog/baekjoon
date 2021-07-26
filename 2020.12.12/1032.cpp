#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int n; cin >> n;
    vector<string> vec(n);
    for (auto &s : vec) cin >> s;
    for (int i = 0; i < vec[0].size(); i++) {
        int k = 0;
        for (const auto &s : vec)
            if (s[i] != vec[0][i]) k = 1;
        
        if (!k) cout << vec[0][i];
        else cout << "?";
    }
}
