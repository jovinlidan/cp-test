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
    vector<int> a, b;

    while(tc--){
        ll n, last, ans = 0;
        cin >> n;
        a.clear();
        b.clear();
        a.resize(n);
        b.resize(n+1);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n+1; i++){
            cin >> b[i];
            last = b[i];
        }
        int mn = 1e9;
        bool flag = false;
        for(int i = 0; i < n; i++){
            ans += abs(a[i] - b[i]);
            if(a[i] > b[i])swap(a[i], b[i]);
            if(last >= a[i] && last <= b[i]){
                flag = true;
            }
            mn = min(mn , int(abs(a[i] - last)));
            mn = min(mn , int(abs(b[i] - last)));
        }
        
        if(flag){
            cout << ans+ 1 << '\n';
        }else {
            cout << ans + mn + 1 << '\n';
        }

        

    }
    
}