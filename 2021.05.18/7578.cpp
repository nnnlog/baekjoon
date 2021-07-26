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

vi vec, tmp;

ll merge_sort(int s, int e) {
	ll ret = 0;
	if (s < e) {
		int mid = (s + e) >> 1;
		ret += merge_sort(s, mid) + merge_sort(mid + 1, e);
		int l = s, r = mid + 1, k = s;
		while (l <= mid || r <= e) {
			if (l > mid) tmp[k++] = vec[r++];
			else if (r > e) tmp[k++] = vec[l++];
			else if (vec[l] > vec[r]) tmp[k++] = vec[r++], ret += mid - l + 1;
			else tmp[k++] = vec[l++];
		}
		for (int i = s; i <= e; i++) vec[i] = tmp[i];
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	tmp.resize(n);
	mpii A;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		A[a] = i;
	}
	vi B(n);
	for (auto &i : B) cin >> i, i = A[i];
	vec = B;
	cout << merge_sort(0, n - 1);
}
