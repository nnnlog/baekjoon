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
	
	auto input = [&]() {
        int a, b, c;
        char _;
        cin >> a >> _ >> b >> _ >> c;
        return a * 3600 + b * 60 + c;
    };
    
    int a = input();
    int b = input();
    
    if (a >= b) b += 60 * 60 * 24;
    
    int r = b - a;
    cout << setw(2) << setfill('0');
    cout << r / 3600 << ":";
    r %= 3600;
    cout << setw(2) << setfill('0');
    cout << r / 60 << ":";
    cout << setw(2) << setfill('0');
    cout << r % 60;
}
