#include "dna.h"

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

vector<vi> sum1, sum2;
vector<vector<vi>> diff;

char conv(char c) {
	if (c == 'A') return 0;
	if (c == 'T') return 1;
	return 2;
}

void init(std::string a, std::string b) {
	sum1.assign(a.size() + 1, vi(3));
	sum2.assign(b.size() + 1, vi(3));
	diff.assign(a.size() + 1, vector<vi>(3, vi(3)));
	for (int i = 1; i <= a.size(); i++) sum1[i] = sum1[i - 1], sum2[i] = sum2[i - 1], sum1[i][conv(a[i - 1])]++, sum2[i][conv(b[i - 1])]++;
	for (int i = 1; i <= a.size(); i++) diff[i] = diff[i - 1], diff[i][conv(a[i - 1])][conv(b[i - 1])]++;
}

int get_distance(int x, int y) {
	++x, ++y;
	for (int i = 0; i <= 2; i++) if (sum1[y][i] - sum1[x - 1][i] != sum2[y][i] - sum2[x - 1][i]) return -1;
	auto K = diff[y];
	for (int i = 0; i <= 2; i++) for (int j = 0; j <= 2; j++) K[i][j] -= diff[x - 1][i][j];
	int ans = 0;
	auto solve = [&](int i, int j) {
		int t = min(K[i][j], K[j][i]);
		K[i][j] -= t;
		K[j][i] -= t;
		ans += t;
	};
	for (int i = 0; i < 2; i++) for (int j = i + 1; j <= 2; j++) solve(i, j);
	return ans + max(K[1][2], K[2][1]) * 2;
}
