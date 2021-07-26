#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cout.tie(0)->sync_with_stdio(0);

    ll n, x;
    cin >> n >> x;
    vector<ll> chk(n + 1);

    for (long long i = 1; i <= n - 2 && x; i++) {
        long long size = n - 1 - i;
        if (x - size < 0) continue;
        x -= size;
        chk[i] = 1;
    }
    
    if (x) {
        cout << -1;
        return 0;
    }

    stack<ll> after;
    cout << n << " ";
    for (long long i = 1; i <= n - 2; i++)
        if (chk[i]) cout << i << " ";
        else after.push(i);
    cout << n - 1 << " ";

    while (!after.empty()) {
        cout << after.top() << " ";
        after.pop();
    }
}