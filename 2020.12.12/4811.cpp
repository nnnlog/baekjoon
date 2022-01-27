#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

ll dp[100][100];
ll solve(int w, int h) {
    if (w < 0) return 0;
    if (!w) return 1;
    ll &ret = dp[w][h];
    if (ret) return ret;
    return ret = solve(w - 1, h + 1) + (h > 0? solve(w, h - 1):0LL);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  do{
      int i; cin >> i;
      if(!i) return 0;
      cout<<solve(i,0)<<"\n";
      }while(1);
}
