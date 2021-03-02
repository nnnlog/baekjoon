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

#include <sys/stat.h>
#include <sys/mman.h>

signed I[36];
char *J = (char *) mmap(0, I[12], 1, 2, 0, fstat(0, (struct stat *) I));

int getu() {
	int x = 0;
	do x = x * 10 + *J - '0'; while (*++J >= '0');
	++J;
	return x;
}

int ok[799'994];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int w, n;
	w = getu();
	n = getu();
	vi vec(n);
	for (auto &i : vec) i = getu();

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (w > vec[i] + vec[j] && ok[w - (vec[i] + vec[j])]) {
				cout << "YES";
				return 0;
			}
		}
		for (int j = 0; j < i; j++) if (vec[i] + vec[j] < w) ok[vec[i] + vec[j]] = 1;
	}

	cout << "NO";
}
