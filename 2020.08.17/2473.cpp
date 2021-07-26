#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long n, ans = 1e18;
    vector<long long> ans_comb;
    cin >> n;

    vector<long long> origin(n);
    for (int i = 0; i < n; i++) cin >> origin[i];

    sort(origin.begin(), origin.end());
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            long long sum = origin[i] + origin[j], tmp = 1e18;

            auto it = lower_bound(origin.begin(), origin.end(), -sum), sel = origin.begin();
            for (auto k = max(origin.begin(), it - 2); k <= it + 2 && k < origin.end(); k++) {
                if (*k != origin[i] && *k != origin[j]) {
                    if (tmp > abs(*k + sum)) {
                        tmp = abs(*k + sum);
                        sel = k;
                    }
                }
            }

            if (ans > tmp) {
                ans = tmp;
                ans_comb = {origin[i], origin[j], *sel};
            }
        }

    sort(ans_comb.begin(), ans_comb.end());
    for (const auto &v : ans_comb) cout << v << " ";
}
