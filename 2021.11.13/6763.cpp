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
	
	int a, b; cin >> a >> b;
    int c = b - a;
    if (c <= 0) cout << "Congratulations, you are within the speed limit!";
    else {
        int ans = 100;
        if (c >= 21) ans = 270;
        if (c >= 31) ans = 500;
        cout << "You are speeding and your fine is $" << ans << ".";
    }
}
