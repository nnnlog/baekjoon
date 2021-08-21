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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	deque<pii> deq;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		deq.emplace_back(a, i);
	}
	while (1) {
		auto front = deq.front(); deq.pop_front();
		cout << front.second << " ";
		if (deq.empty()) break;
		int a = front.first;
		//if (deq.size() == 1) continue;
		if (a > 0) {
			for (int i = 1; i < a; i++) deq.push_back(deq.front()), deq.pop_front();
		} else {
			for (int i = 0; i < -a; i++) deq.push_front(deq.back()), deq.pop_back();
		}
	}
}
