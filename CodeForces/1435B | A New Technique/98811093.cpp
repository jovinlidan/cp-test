#include <bits/stdc++.h>
#define ll long long
#define mxN 10000001
#define inf 1000000000000000000
using namespace std;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
const ll mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int n,m,x; cin >> n >> m;
        int c[m] = {}, ans[n][m] = {};
        vector <int> mp[n*m+5];
        bool cek[n*m+5] = {};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> x;
                if (i == 0) {
                    cek[x] = 1;
                    c[j] = x;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int xx;
            vector <int> v;
            for (int j = 0; j < n; j++) {
                cin >> x;
                if (cek[x]) xx = x;
                v.push_back(x);
            }
            for (int j = 0; j < n; j++) {
                mp[xx].push_back(v[j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][i] = mp[c[i]][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << '\n';
        }
    }
}
