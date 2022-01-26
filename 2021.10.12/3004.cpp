#include <bits/stdc++.h>
using namespace std;
int main(){
    int a; cin >> a;
    int b = a/2, c=a/2;
    c+=a%2;
    cout << (b+1)*(c+1);
    }