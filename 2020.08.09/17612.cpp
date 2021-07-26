#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
queue<pair<ll, ll>> q;
vector<pair<ll, ll>> l;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		ll id, w;
		cin >> id >> w;
		q.push({id, w});
	}
    
    l.resize(k);
	for (int i = 0; i < k && !q.empty(); i++) {
		l[i] = q.front();
		q.pop();
	}

	ll exit = 1;
	ll ans = 0;
	while (exit <= n) {
		ll minimum = 20;
		vector<pair<ll, int>> out;
		for (const auto &a : l) if (a.second > 0) minimum = min(a.second, minimum);
        
		for (int i = k - 1; i >= 0; i--) 
            if (l[i].second > 0 && !(l[i].second -= minimum))
                ans += exit++ * l[i].first;
        
		for (int i = 0; i < k; i++) 
            if (!(l[i].second)) {
                l[i].second = -1;
                if (q.empty()) break;
                l[i] = q.front();
			    q.pop();
            }
    }

	cout << ans;
}
