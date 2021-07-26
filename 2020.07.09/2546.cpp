#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		double N, M, C_sum = 0, E_sum = 0;
		cin >> N >> M;
		vector<int> C(N);
		for (int i = 0; i < N; i++) {
			cin >> C[i];
			C_sum += C[i];
		}
		for (int i = 0; i < M; i++) {
			int a; cin >> a;
			E_sum += a;
		}

		double C_avr = C_sum / N, E_avr = E_sum / M, ans = 0;
		for (int i = 0; i < N; i++) {
			if (C[i] < C_avr && C[i] > E_avr) ans++;
		}

		cout << ans << "\n";
	}
}