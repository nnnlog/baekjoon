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

vi UF;

int find(int a) {
	return UF[a] = a == UF[a] ? a : find(UF[a]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	UF[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	auto id = [&](int x, int y) {
		return x * m + y;
	};
	UF.resize(n * m);
	iota(all(UF), 0);
	vector<vi> vec1(n, vi(m)), vec2(n, vi(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> vec1[i][j];
			if (i && vec1[i - 1][j] == vec1[i][j]) merge(id(i - 1, j), id(i, j));
			if (j && vec1[i][j - 1] == vec1[i][j]) merge(id(i, j - 1), id(i, j));
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> vec2[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vec1[i][j] != vec2[i][j]) {
				for (int x = 0; x < n; x++)
					for (int y = 0; y < m; y++)
						if (find(id(x, y)) == find(id(i, j))) vec1[x][y] = vec2[i][j];
				goto chk;
			}
		}
	}

	chk:;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (vec1[i][j] != vec2[i][j]) {
				cout << "NO";
				return 0;
			}
	cout << "YES";
}
