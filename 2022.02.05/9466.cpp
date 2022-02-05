#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef unordered_map<int, int> mpii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vi graph(n + 1), in(n + 1);
        for (int i = 1; i <= n; i++) {
            int a; cin >> a;
            graph[i] = a;
            in[a]++;
        }

        int ans = 0;
        queue<int> Q;
        for (int i = 1; i <= n; i++)
            if (!in[i]) Q.push(i), ans++;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            int v = graph[u];
            if (!--in[v]) Q.push(v), ans++;
        }
        cout << ans << "\n";
    }
}
