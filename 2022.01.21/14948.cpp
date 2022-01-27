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
    return UF[a] = UF[a] == a ? a : find(UF[a]);
}
void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) UF[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m; cin >> n >> m;
    UF.resize(n * m);
    auto id = [&](int i, int j) {
        return i * m + j;
    };

    vector<vi> vec(n, vi(m));
    for (auto &v : vec)
        for (int &i : v) cin >> i;

    int l = max(vec[0][0], vec[n - 1][m - 1]), r = 1e9;
    while (l < r) {
        iota(all(UF), 0);

        int mid = (l + r) >> 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vec[i][j] > mid) continue;
                if (i && vec[i - 1][j] <= mid) merge(id(i, j), id(i - 1, j));
                if (j && vec[i][j - 1] <= mid) merge(id(i, j), id(i, j - 1));
            }
        }
        int start = find(id(0, 0));
        int end = find(id(n - 1, m - 1));
        int ok = start == end;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i && i + 1 < n && find(id(i - 1, j)) == start && find(id(i + 1, j)) == end) ok = 1;
                if (i && i + 1 < n && find(id(i - 1, j)) == end && find(id(i + 1, j)) == start) ok = 1;
                if (j && j + 1 < m && find(id(i, j - 1)) == start && find(id(i, j + 1)) == end) ok = 1;
                if (j && j + 1 < m && find(id(i, j - 1)) == end && find(id(i, j + 1)) == start) ok = 1;
            }
        }
        if (ok) r = mid;
        else l = mid + 1;
    }
    cout << l;
}
