#include <bits/stdc++.h>

using namespace std;

int dist[16][16], dp[16][131072], finish, n;

int solve(int current, int vis) {
    //cout << bitset<16>(vis).to_string() << " " << current << "\n";
    if (vis == finish)
        if (dist[current][0]) return dist[current][0];
        else return 1e9;

    if (dp[current][vis]) return dp[current][vis];

    int ret = 1e9;
    for (int j = 0; j < n; j++) {
        if (((vis >> j) & 1) == 0 && dist[current][j]) {
            ret = min(ret, solve(j, vis | (1 << j)) + dist[current][j]);
        }
    }

    return dp[current][vis] = ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    finish = (1 << n) - 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    cout << solve(0, 1);
}
