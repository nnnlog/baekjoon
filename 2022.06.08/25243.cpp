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

enum DIRECTION {
	FROM_BUBAL_TO_CHUNG = 1, FROM_CHUNG_TO_BUBAL = -1,
};

int required_time[] = {7, 7, 8, 10,};

enum STATUS {
	GO, WAIT, FINISH
};

struct Train {
	DIRECTION direction;
	int section; // 0 1 2 3
	STATUS status;
	int step;
	int lock_time;
	int start_time;
	int id;
	int finish_time;
};

int current_time = -1;
vector<Train> vec;

int wait_time = 1; // 역 대기 시간

bool tick() {
	++current_time;

	vector<vi> waiting(4);
	vi locked(4);
	for (int i = 0; i < vec.size(); i++) {
		auto &train = vec[i];
		if (train.lock_time > current_time) continue;
		if (train.status == GO) {
			if (++train.step == required_time[train.section]) {
				train.section += train.direction;
				if (train.section < 0 || train.section > 3) train.status = FINISH, train.finish_time = current_time;
				else train.status = WAIT, train.lock_time = current_time + wait_time;
			} else locked[train.section] = 1;
		}
	}

	for (int i = 0; i < vec.size(); i++) {
		auto &train = vec[i];
		if (train.lock_time > current_time) continue;
		if (train.status == WAIT) waiting[train.section].push_back(i);
	}

	for (int i = 0; i < 4; i++) {
		if (locked[i] || waiting[i].empty()) continue;
		sort(all(waiting[i]), [](const auto &x, const auto &y) {
			const Train &a = vec[x], &b = vec[y];
			if (a.start_time != b.start_time) return a.start_time < b.start_time;
			return a.id < b.id;
		});

		auto &train = vec[waiting[i][0]];
		train.status = GO;
		train.step = 0;
	}

	return ranges::any_of(all(vec), [](const auto &a) {
		return a.status != FINISH;
	});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b; cin >> a >> b;
	for (int i = 0; i < a + b; i++) {
		int id, h, m;
		char c;
		cin >> id >> h >> c >> m;

		int start_time = h * 60 + m;

		vec.push_back({
			i < a ? FROM_BUBAL_TO_CHUNG : FROM_CHUNG_TO_BUBAL,
			i < a ? 0 : 3,
			WAIT,
			0,
			start_time,
			start_time,
			id,
			0,
		});
	}

	while (tick());

	sort(all(vec), [](const auto &a, const auto &b) {
		return a.id < b.id;
	});

	for (const auto &i : vec) cout << setw(2) << setfill('0') << ((i.finish_time / 60) % 24) << ":" << setw(2) << setfill('0') << (i.finish_time % 60) << "\n";
}
