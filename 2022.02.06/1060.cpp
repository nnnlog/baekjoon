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

    int l;
    cin >> l;

    vi vec(l);
    for (int &i: vec) cin >> i;
    sort(all(vec));

    unordered_map<int, ll> vis;
    priority_queue<pair<ll, pair<int, pii>>, vector<pair<ll, pair<int, pii>>>, greater<>> pq;
    auto push = [&](int a, int s, int e) {
        if (!(s <= a && a <= e)) return;
        if (!a) return;
        ll w = max(0LL, ll(a - s) * (e - a) - 1);
        if (vis.count(a)) return;
        vis[a] = 1;
        pq.push({w, {a, {s, e}}});
    };

    int prv = 0;
    push(1, 0, vec[0]);

    for (int nxt: vec) {
        push(nxt, nxt, nxt);

        push(prv + 1, prv, nxt);
        push(nxt - 1, prv, nxt);

        prv = nxt;
    }

    int n;
    cin >> n;

    while (!pq.empty()) {
        if (n-- <= 0) return 0;
        auto top = pq.top();
        pq.pop();

        int curr = top.second.first;
        //if (vis[curr] == -1) continue;
        vis[curr] = -1;
        cout << curr << " ";

        push(curr - 1, top.second.second.first, top.second.second.second);
        push(curr + 1, top.second.second.first, top.second.second.second);
    }

    for (int i = 1;; i++) {
        if (vis[i] == -1) continue;
        if (n-- <= 0) return 0;
        cout << i << " ";
    }
}
