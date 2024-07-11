#include <bits/stdc++.h>
using namespace std;
#define INF -1e9
typedef long long int ll;
typedef pair <int,int> pii;
typedef pair <pii,int> piii;
const ll MOD = 1e9+7;
const int mxN = 1000005;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int kx[8] = { 2, 1, -1, -2, -2, -1, 1, 2};
int ky[8] = { 1, 2, 2, 1, -1, -2, -2, -1};
ll qpow(unsigned long long x , int y , int p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y % 2 == 1) res = (res * x) % p;
        y = y / 2;
        x = (x * x) % p;
    }
    return res;
}
ll modInverse(unsigned long long x , int p)
{
    return qpow(x, p - 2 , p);
}
double calc (ll t1 , ll t2 , ll y1 , ll y2)
{
    return (t1 * y1 + t2 * y2) * 1.0 /(y1 + y2);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;

    while(tc--){
        int n, m;
        cin >> n >> m;
        bool sisa1M = false;

        // perscreen 15;

        int ans = 0;
        ans = (m / 2);
        m = m % 2;
        if(m == 1)sisa1M = true;
        
        n = max(0, n - (ans * 7));

        if(m > 0){
            ans++;
            m = 0;
        }

        // left 11;
        if(sisa1M)n = max(0, n - 11);
        if( n > 0){
            ans += (n / 15);
            if(n % 15 != 0)ans++;
        }
        cout << ans << '\n';
    }
    
    
}
