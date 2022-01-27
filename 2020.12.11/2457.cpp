#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int d2i[13][32];

struct Flower {
	pii start, end;
	bool operator<(const Flower& a) const {
		//return d2i[end.first][end.second] - d2i[start.first][start.second] > d2i[a.end.first][a.end.second] - d2i[a.start.first][a.start.second];
		return d2i[end.first][end.second] > d2i[a.end.first][a.end.second];
	}
};

int in(Flower a, int i) {
	//cout << d2i[a.start.first][a.start.second] << ":" << d2i[a.end.first][a.end.second] << endl;
	return d2i[a.start.first][a.start.second] <= i && i <= d2i[a.end.first][a.end.second];
}

vector<Flower> list;

int main() {
	int i = 0;
	for (int m = 1; m <= 12; m++) {
		int d = 30 + (m == 2 ? -2 : (m >= 8 ? (m - 1) % 2 : m % 2));
		for (int dd = 1; dd <= d; dd++) {
			//cout << m << ":" << dd << " - " << (i + 1) << "  ";
			d2i[m][dd] = i++;
		}
	}

	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		list.push_back(Flower{ pii(a, b), pii(c, d) });
	}

	//sort(list.begin(), list.end());

	//for (auto a : list) {
	//	cout << a.start.first << "/" << a.start.second << " - " << a.end.first << "/" << a.end.second << endl;
	//}
	int ans = 0, day = d2i[3][1];
	while (day <= d2i[11][30]) {
		vector<pair<Flower, int>> t;
		for (int i = 0; i < list.size(); i++) {
			Flower f = list[i];
			if (in(f, day)) {
				t.push_back(make_pair(f, i));
			}
		}//cout << endl;

		if (t.size()) {
			++ans;
			sort(t.begin(), t.end());
			//for (auto x : t) {
			//	Flower a = x.first;
			//	cout << d2i[a.start.first][a.start.second] << ":" << d2i[a.end.first][a.end.second] << endl;
			//}
			day = d2i[t[0].first.end.first][t[0].first.end.second];
			list.erase(list.begin() + t[0].second);
			//cout << t[0].end.first << " / " << t[0].end.second << endl;
		}
		else {
			cout << 0;
			return 0;
		}//cout << endl;
	}

	cout << ans;
}
