#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    queue<int> start;
    int n, k, sum = 0, ans = 1e6, flag = 0; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (a == 1) {
            sum++;
            start.push(i);

            if (sum == k) {
                sum--;
                ans = min(ans, i - start.front() + 1);
                flag = 1;
                start.pop();
            }
        }
    }

    cout << (flag ? ans : -1);
}