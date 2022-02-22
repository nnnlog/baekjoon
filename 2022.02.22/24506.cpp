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

struct A {
    int inc_sz, inc_right, inc_skip;
    int dec_sz, dec_left, dec_skip;
    int ans;
};

vector<A> seg;
vi vec;

int kth_inc(int node, int k) {
    if (seg[node].inc_sz == k) return seg[node].inc_right;
    if (seg[node * 2].inc_sz >= k) return kth_inc(node * 2, k);
    return kth_inc(node * 2 + 1, k - seg[node * 2].inc_sz + seg[node * 2 + 1].inc_skip);
}

int kth_dec(int node, int k) {
    if (seg[node].dec_sz == k) return seg[node].dec_left;
    if (seg[node * 2 + 1].dec_sz >= k) return kth_dec(node * 2 + 1, k);
    return kth_dec(node * 2, k - seg[node * 2 + 1].dec_sz + seg[node * 2].dec_skip);
}

const A &merge(int node) {
    const A &X = seg[node * 2], &Y = seg[node * 2 + 1];

    seg[node].inc_sz = X.inc_sz, seg[node].inc_right = X.inc_right;
    if (X.inc_right < Y.inc_right) {
        int s = 1, e = Y.inc_sz;
        while (s < e) {
            int m = (s + e) >> 1;
            if (X.inc_right < kth_inc(node * 2 + 1, m)) e = m;
            else s = m + 1;
        }
        seg[node].inc_right = Y.inc_right;
        seg[node].inc_sz += Y.inc_sz - e + 1;
        seg[node * 2 + 1].inc_skip = e - 1;
    }

    seg[node].dec_sz = Y.dec_sz, seg[node].dec_left = Y.dec_left;
    if (X.dec_left > Y.dec_left) {
        int s = 1, e = X.dec_sz;
        while (s < e) {
            int m = (s + e) >> 1;
            if (kth_dec(node * 2, m) > Y.dec_left) e = m;
            else s = m + 1;
        }
        seg[node].dec_left = X.dec_left;
        seg[node].dec_sz += X.dec_sz - e + 1;
        seg[node * 2].dec_skip = e - 1;
    }

    seg[node].ans = X.ans + Y.ans;
    if (X.dec_left < Y.inc_right) {
        int s = 1, e = Y.inc_sz;
        while (s < e) {
            int m = (s + e) >> 1;
            if (X.dec_left < kth_inc(node * 2 + 1, m)) e = m;
            else s = m + 1;
        }

        //assert(s == e);
        seg[node].ans += X.dec_sz + (s - 1);
    } else {
        int s = 1, e = X.dec_sz;
        while (s < e) {
            int m = (s + e) >> 1;
            if (kth_dec(node * 2, m) > Y.inc_right) e = m;
            else s = m + 1;
        }

        //assert(s == e);
        seg[node].ans += (s - 1) + Y.inc_sz;
    }

    return seg[node];
}

const A &init(int node, int start, int end) {
    if (start == end) return seg[node] = {1, vec[start], 0, 1, vec[start], 0, 0};
    int mid = (start + end) >> 1;
    init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end);
    return merge(node);
}

const A &upd(int node, int start, int end, int k) {
    if (!(start <= k && k <= end)) return seg[node];
    if (start == end) return seg[node] = {1, vec[start], 0, 1, vec[start], 0, 0};
    int mid = (start + end) >> 1;
    upd(node * 2, start, mid, k), upd(node * 2 + 1, mid + 1, end, k);
    return merge(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vec.resize(n + 1);
    for (int &i: vec | views::drop(1)) cin >> i;

    seg.resize(n * 4);
    init(1, 1, n);
/*
    int k = 2;
    cout << seg[k].inc_sz << " " << seg[k].inc_right << "\n";
    for (int i = 1; i <= seg[k].inc_sz; i++) cout << kth_inc(k, i) << " ";
    cout << "\n";
    cout << seg[k].dec_sz << " " << seg[k].dec_left << "\n";
    for (int i = seg[k].dec_sz; i >= 1; i--) cout << kth_dec(k, i) << " ";
    cout << "\n\n";
    cout.flush();
*/
    while (q--) {
        int a;
        cin >> a;
        if (a == 2) cout << seg[1].ans << "\n";
        else {
            int b, c;
            cin >> b >> c;
            vec[b] = c;
            upd(1, 1, n, b);
/*
            cout << seg[1].inc_sz << " " << seg[1].inc_right << "\n";
            for (int i = 1; i <= seg[1].inc_sz; i++) cout << kth_inc(1, i) << " ";
            cout << "\n";
            cout << seg[1].dec_sz << " " << seg[1].dec_left << "\n";
            for (int i = seg[1].dec_sz; i >= 1; i--) cout << kth_dec(1, i) << " ";
            cout << "\n\n";
            */
        }
    }
}
