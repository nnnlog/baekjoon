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
	
	int a, b, c; cin >> a >> b >> c;
    vector<pair<int, string>> vec = {
        {a, "Soongsil"},
        {b, "Korea"},
        {c, "Hanyang"}
    };
    sort(all(vec));
    if (a + b + c >= 100) cout << "OK";
    else cout << vec[0].second;
}
