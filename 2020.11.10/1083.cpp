#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, s;
	cin >> n;
	vector<int> vec(n);
	for (auto &i : vec) cin >> i;
	cin >> s;
	
	for (int i = 0; i < n && s > 0; i++) {
		int mx = -1, pos = 0;
		for (int j = i; j <= i + s && j < n; j++) {
			if (vec[j] > mx) {
				mx = vec[j];
				pos = j;
			}
		}
				
		for (int j = pos; j > i; j--) --s, swap(vec[j], vec[j - 1]);
	}
	
	for (const auto &i : vec) cout << i << " ";
}
