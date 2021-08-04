#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;

int main() {
	int T; cin >> T;
	while (T--) {
		string x, y, w; cin >> x >> y >> w;
		x.insert(x.begin(), '1');
		y.insert(y.begin(), '1');
		vector<int> xL(w.size()), xR(w.size()), yL(w.size()), yR(w.size());
		auto L_fill = [&](auto &a, auto &w, auto &vec) {
			int k = 0;
			for (int i = 0; i < w.size(); i++) {
				while (w[i] != a[k]) ++k;
				vec[i] = k++;
			}
		};
		auto R_fill = [&](auto a, auto w, auto &vec) {
			reverse(all(a));
			reverse(all(w));
			L_fill(a, w, vec);
			reverse(all(vec));
			for (auto &i : vec) i = a.size() - i - 1;
		};

		L_fill(x, w, xL);
		R_fill(x, w, xR);
		L_fill(y, w, yL);
		R_fill(y, w, yR);

		vector<vector<int>> sumX(x.size(), vector<int>('z' + 1)), sumY(y.size(), vector<int>('z' + 1));
		for (int i = 1; i < x.size(); i++) {
			sumX[i] = sumX[i - 1];
			sumX[i][x[i]]++;
		}
		for (int i = 1; i < y.size(); i++) {
			sumY[i] = sumY[i - 1];
			sumY[i][y[i]]++;
		}
/*
		for (int i = 0; i < w.size(); i++) cout << i << " " << xL[i] << " " << xR[i] << "\n";
		cout << "\n";
		for (int i = 0; i < w.size(); i++) cout << i << " " << yL[i] << " " << yR[i] << "\n";
		cout << "\n\n";
*/
		auto solve = [&](int a, int b, int c, int d) {
			if (a > b || c > d) return 0;
			for (int j = 'a'; j <= 'z'; j++) {
				if (
					sumX[b][j] - sumX[a][j] > 0 &&
					sumY[d][j] - sumY[c][j] > 0
				) return 1;
			}
			return 0;
		};

		int ans = solve(0, xR[0] - 1, 0, yR[0] - 1) | solve(xL.back(), x.size() - 1, yL.back(), y.size() - 1);
		for (int i = 0; i < w.size() - 1 && !ans; i++) {
			ans |= solve(xL[i], xR[i + 1] - 1, yL[i], yR[i + 1] - 1);
		}

		cout << ans << "\n";
	}
}

