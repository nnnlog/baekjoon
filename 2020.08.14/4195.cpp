#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> mp;
int UF[200000], unc[200000];

int find(int a) {
	return UF[a] = a == UF[a] ? a : find(UF[a]);
}

void merge(int a, int b) {
	int x = find(a), y = find(b);
	if (x == y) return;
	UF[x] = y;
	unc[y] += unc[x];
	unc[x] = 0;
}

void init(int size) {
	mp.clear();
	for (int i = 0; i < size * 2; i++) {
		UF[i] = i;
		unc[i] = 1;
	}
}

int getIdFromName(string &name) {
	return mp[name] = !mp[name] ? mp.size() : mp[name];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int f; cin >> f;
		init(f);

		while (f--) {
			string a, b; cin >> a >> b;
			int x = getIdFromName(a), y = getIdFromName(b);
			merge(x, y);
			cout << unc[find(x)] << "\n";
		}
	}
}
