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
	
	while (1) {
        int a, b, c; cin >> a >> b >> c;
        if (!a && !b && !c) return 0;
        if (a < b) swap(a, b);
        if (a < c) swap(a, c);
        if (a >= b + c) cout << "Invalid\n";
        else if (a == b && b == c) cout << "Equilateral\n";
        else if (a == b || b == c || a == c) cout << "Isosceles\n";
        else cout << "Scalene\n";
    }
}
