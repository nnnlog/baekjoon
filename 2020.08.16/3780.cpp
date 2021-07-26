#include <bits/stdc++.h>

using namespace std;

int UF[20001], weight[20001];

void init(int sz) {
    for (int i = 1; i <= sz; i++) {
        UF[i] = i;
        weight[i] = 0;
    }
}

int find(int x) {
    if (x == UF[x]) return x;
    int t = find(UF[x]);
    weight[x] += weight[UF[x]];
    return UF[x] = t;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        init(n);
        while (1) {
            char c; cin >> c;
            if (c == 'O') break;
            if (c == 'E') {
                int a; cin >> a;
                find(a);
                cout << weight[a] << "\n";
            }else{
                int a, b; cin >> a >> b;
                weight[a] = abs(a - b) % 1000;
                UF[a] = b;
            }
        }
    }
}
