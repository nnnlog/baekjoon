#include <deque>
#include <stdio.h>

#include <sys/stat.h>
#include <sys/mman.h>
signed I[36];char*J=(char*)mmap(0,I[12],1,2,0,fstat(0,(struct stat*)I));
int getu(){int x=0;do x=x*10+*J-'0';while(*++J>='0');++J;return x;}

using namespace std;

int main() {
	//도도, 수연
	deque<char> A, B;
	deque<char> X, Y;

	int n = getu(), m = getu();
	for (int i = 0; i < n; i++) {
		A.push_back(getu());
		B.push_back(getu());
	}

	for (int i = 0; i < m; i++) {
		if (i % 2 == 0) {
			if (A.empty()) {
				puts("su");
				return 0;
			}
			X.push_back(A.back()); A.pop_back();
			if (A.empty()) {
				puts("su");
				return 0;
			}
			if (!Y.empty() && X.back() + Y.back() == 5) { //수연
				for (const auto &k : X) B.push_front(k);
				for (const auto &k : Y) B.push_front(k);
				X.clear(), Y.clear();
				continue;
			}
			if (X.back() == 5) { //도도
				for (const auto &k : Y) A.push_front(k);
				for (const auto &k : X) A.push_front(k);
				X.clear(), Y.clear();
				continue;
			}
		} else {
			if (B.empty()) {
				puts("do");
				return 0;
			}
			Y.push_back(B.back()); B.pop_back();
			if (B.empty()) {
				puts("do");
				return 0;
			}
			if (!X.empty() && X.back() + Y.back() == 5) { //수연
				for (const auto &k : X) B.push_front(k);
				for (const auto &k : Y) B.push_front(k);
				X.clear(), Y.clear();
				continue;
			}
			if (Y.back() == 5) { //도도
				for (const auto &k : Y) A.push_front(k);
				for (const auto &k : X) A.push_front(k);
				X.clear(), Y.clear();
				continue;
			}
		}
	}

	puts(A.size() == B.size() ? "dosu" : (A.size() > B.size() ? "do" : "su"));
}
