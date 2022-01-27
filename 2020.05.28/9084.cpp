#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long ull;
 
vector<ull> l;
vector<vector<ull>> dp(10001, vector<ull>(21));
 
ull solve(ull i, ull money) {
    if (dp[money][i]) return dp[money][i];
    if (!money) {
        return 1;
    }
    if (i == l.size()) return 0;
    ull div = l[i], ans = 0;
    if (i + 1 == l.size() && money % div) return 0;
    //if (div == 1) return dp[money][i] = money;
    for (int k = 0; k <= money / div; k++) {
        ans += solve(i + 1, money - k * div);
    }
    dp[money][i] = ans;
    return ans;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while(T--) {
        int n;
        cin >> n;
    
        dp.assign(10001, vector<ull>(21));
        l.resize(n);
        for (int i = n - 1; i >= 0; i--) cin >> l[i];
    
        int m;
        cin >> m;
    
        cout << solve(0, m) << "\n";
    }
}
