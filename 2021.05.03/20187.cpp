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

int arr[257][257];

void cpy(pii origin, pii sz, pii target, int vertical) {
	if (vertical) origin.first += sz.first;
	else origin.second += sz.second;
	for (int i = 0; i <= sz.first; i++)
		for (int j = 0; j <= sz.second; j++) {
			int x = target.first + i, y = target.second + j;
			arr[x][y] = arr[origin.first + i * (vertical ? -1 : 1)][origin.second + j * (vertical ? 1 : -1)];
			if (vertical) arr[x][y] = (arr[x][y] + 2) % 4;
			else if (arr[x][y] < 2) arr[x][y] = (arr[x][y] + 1) % 2;
			else arr[x][y] = (arr[x][y] + 1) % 2 + 2;
		}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int k; cin >> k;
	pii A = {1, 1}, B = {pow(2, k), pow(2, k)};
	vector<char> vec;
	for (int i = 0; i < 2 * k; i++) {
		char c; cin >> c;
		vec.push_back(c);
		if (c == 'R') A.second = (A.second + B.second + 1) / 2;
		if (c == 'L') B.second = (A.second + B.second) / 2;
		if (c == 'D') A.first = (A.first + B.first + 1) / 2;
		if (c == 'U') B.first = (A.first + B.first) / 2;
	}

	assert(A.first == B.first);
	assert(A.second == B.second);

	int a; cin >> a;
	arr[A.first][A.second] = a;

	reverse(all(vec));
	for (const auto &c : vec) {
		pii x = A, y = B;
		if (c == 'R') {
			A.second -= B.second - A.second + 1;
			cpy(x, {y.first - x.first, y.second - x.second}, A, 0);
		}
		if (c == 'L') {
			B.second += B.second - A.second + 1;
			cpy(x, {y.first - x.first, y.second - x.second}, {A.first, y.second + 1}, 0);
		}
		if (c == 'D') {
			A.first -= B.first - A.first + 1;
			cpy(x, {y.first - x.first, y.second - x.second}, A, 1);
		}
		if (c == 'U') {
			B.first += B.first - A.first + 1;
			cpy(x, {y.first - x.first, y.second - x.second}, {y.first + 1, A.second}, 1);
		}
	}
	assert(A.first == 1);
	assert(B.first == pow(2, k));
	assert(A.second == 1);
	assert(B.second == pow(2, k));
	for (int i = A.first; i <= B.first; i++) {
		for (int j = A.second; j <= B.second; j++) cout << arr[i][j] << " ";
		cout << "\n";
	}
	//cout << A.first << " " << A.second << " " << B.first << " " << B.second;
}
