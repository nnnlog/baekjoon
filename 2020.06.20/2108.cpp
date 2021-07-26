#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<int> l;
vector<pii> cnt;
unordered_map<int, int> cnt_list;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, sum = 0;
	cin >> n;

	while (n--) {
		int a;
		cin >> a;
		l.push_back(a);
		cnt_list[a]++;

		sum += a;
	}

	sort(l.begin(), l.end());

	for (auto c : cnt_list) cnt.emplace_back(c.second, c.first);


	sort(cnt.begin(), cnt.end(), greater<>());
	int mx = cnt[0].first, ans;

	sort(cnt.begin(), cnt.end(), less<>());
	int start = lower_bound(cnt.begin(), cnt.end(), pii(mx, -1e9)) - cnt.begin();
	ans = cnt[min(start + 1, (int)cnt.size() - 1)].second;

	//for (auto c : cnt) cout << c.first << " " << c.second << "\n";

	n = l.size();
	cout << round((double) sum / n) << "\n" << l[n / 2] << "\n" << ans << "\n" << l.back() - l[0];

}