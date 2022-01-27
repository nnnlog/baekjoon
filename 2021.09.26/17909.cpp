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

vi UF, cnt;

int find(int a) {
	return UF[a] = UF[a] == a ? a : find(UF[a]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) cnt[b] += cnt[a], cnt[a] = 0, UF[a] = b;
	++cnt[b];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	vl vec(n);
	for (auto &i: vec) cin >> i;

	UF.resize(n);
	cnt.resize(n);
	iota(all(UF), 0);
	while (m--) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}

	unordered_map<int, pair<pii, ll>> S;
	for (int i = 0; i < n; i++) {
		int a = find(i);
		S[a].first.first++; // 정점 수
		S[a].first.second = cnt[a]; // 간선 수
		S[a].second += vec[i]; // 소켓 합
	}

	priority_queue<pair<pll, int>> pq;
	for (const auto &[_, x]: S) {
		//cout << _ << " " << x.first.first << " " << x.first.second << " " << x.second << "\n";
		pq.push({{x.second - 2 * x.first.second, x.first.second - x.first.first + 1}, 0});
	}
//k+=1e9;
/*
	while (!pq.empty())
		cout << pq.top().first.first << " " << pq.top().first.second << " " << pq.top().second << "\n", pq.pop();
*/
	//return 0;
	while (k >= 0) {
		if (pq.size() == 1) {
			cout << "yes";
			//cout << "\n" << k;
			return 0;
		}


		auto A = pq.top();
		pq.pop();
		auto B = pq.top();
		pq.pop();
/*
		cout << k << " " << pq.size() << "\n";
		cout << "A: " << A.first << " " << A.second << "\n";
		cout << "B: " << B.first << " " << B.second << "\n";
*/
		if (B.first.first) {
			A.first.first += B.first.first - 2;
			A.first.second += B.first.second;
			--k; // A - B 간선 추가
		} else if (B.first.second) {
			if (!A.first.first) --A.first.second, A.first.first += 2, --k; // A 간선 제거
			A.first.second += B.first.second - 1;
			--k; // B 간선 제거
			--k; // A - B 간선 추가
			//if (B.second) k += 2;
		} else {
			if (A.first.first + 2 * A.first.second < 2) break;
			--k; // B 분할
			ll remove = min(2LL, A.first.first);
			A.first.first -= remove;
			if (remove <= 1) {
				--k; // A 간선 제거
				--A.first.second;
				if (remove == 1) ++A.first.first;
			}
			--k; // A - B_1 간선 추가
			--k; // A - B_2 간선 추가
			if (B.second) k += 2;
		}

		A.second = 1;
		pq.push(A);
	}

	cout << "no";
}
