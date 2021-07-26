#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int UF[1000001], unc[1000001];
int find(int a) {
	return UF[a] = UF[a] == a ? a : find(UF[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) {
		UF[a] = b;
		unc[b] += unc[a];
		unc[a] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 1; i <= 1e6; i++) UF[i] = i, unc[i] = 1;

	int n; cin >> n;
	while (n--) {
		char c; cin >> c;
		if (c == 'I') {
			int a, b; cin >> a >> b;
			merge(a, b);
		} else {
			int q; cin >> q;
			cout << unc[find(q)] << "\n";
		}
	}
}
