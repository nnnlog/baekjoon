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
	
	int n, m; cin >> n >> m;
    vector<string> ans;
    unordered_map<string, int> cnt;
    while (n--) {
        string a; cin >> a;
        if (a.size() >= m) ans.push_back(a), cnt[a]++;
    }
    sort(all(ans), [&](const auto &a, const auto &b) {
        if (cnt[a] != cnt[b]) return cnt[a] > cnt[b];
        if (a.size() != b.size()) return a.size() > b.size();
        return a < b;
    });
    ans.erase(unique(all(ans)), ans.end());
    for (const auto &s : ans) cout << s << "\n";
}
