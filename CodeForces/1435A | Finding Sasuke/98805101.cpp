#include <bits/stdc++.h>
#define ll long long
#define mxN 200005
#define inf 1000000000000000000
using namespace std;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i += 2) {
            cout << -1*a[i+1] << " ";
            cout << a[i] << " ";
        }
        cout << '\n';
    }
}
