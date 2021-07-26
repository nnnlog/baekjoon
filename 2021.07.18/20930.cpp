#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#include <sys/stat.h>
#include <sys/mman.h>
signed I[36];char*J=(char*)mmap(0,I[12],1,2,0,fstat(0,(struct stat*)I));
int getu(){int x=0;do x=x*10+*J-'0';while(*++J>='0');++J;return x;}
int geti(){bool e=*J=='-';J+=e;return(e?-1:1)*getu();}

int UF[200000], open[200000];
int find(int a) {
	return UF[a] = a == UF[a] ? a : find(UF[a]);
}
void merge(int a, int b) {
	a = find(a), b = find(b);
	UF[a] = b;
}

typedef pair<int, pii> A;

void sweeping(vector<A> &vec) {
	sort(vec.begin(), vec.end());
	stack<int> prv;
	for (const auto &[pos, datum] : vec) {
		int closed = datum.first, id = datum.second;
		if (closed) open[id] = 0;
		else {
			while (!prv.empty() && !open[prv.top()]) prv.pop();
			if (!prv.empty()) merge(prv.top(), id);
			prv.push(id);
			open[id] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, q;
    n = geti();
    q = geti();
	iota(UF, UF + n, 0);
	vector<A> X, Y;
    X.reserve(2 * n), Y.reserve(2 * n);
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
        a = geti();
        b = geti();
        c = geti();
        d = geti();
		if (a > c) swap(a, c);
		if (b > d) swap(b, d);
		X.push_back({a, {0, i}});
		X.push_back({c, {1, i}});
		Y.push_back({b, {0, i}});
		Y.push_back({d, {1, i}});
	}
	sweeping(X), sweeping(Y);
	while (q--) {
		int a, b;
        a = geti();
        b = geti();
		cout << (find(--a) == find(--b)) << "\n";
	}
}
