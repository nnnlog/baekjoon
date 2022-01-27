#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    vector<ll> prime;

    priority_queue<ll, vector<ll>, greater<>> pq;

    int k, n;
    cin >> k >> n;
    while (k--) {
        int a;
        cin >> a;
        prime.push_back(a);
        pq.push(a);
    }
    ll sel = 0;
    while (n--) {
        int pop = pq.top();
        pq.pop();
        for (const auto &a : prime) {
            pq.push(a * pop);
            if (!(pop % a)) break;
        }


        sel = pop;
    }

    cout << sel;
}
