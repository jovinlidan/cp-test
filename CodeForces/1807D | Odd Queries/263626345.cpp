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

string getBit(int n){
    string s = "";
    while(n){
        s += (n % 2) + '0';
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

vector<ll> returnBit(ll xx){
    vector<ll> ret;
    for(int i = 0; i < 31; i++){
        if(xx & (1ll << i)){
            ret.push_back(1);
        }
        else{
            ret.push_back(0);
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;

    while(tc--){
        int n , q;
        cin >> n >> q;
        vector<int> v(n);
        vector<int> prefixSum;
        vector<int> suffixSum;
        int sum = 0;
        for(int i = 0; i< n;i++){
            cin >> v[i];
            sum += v[i];
            prefixSum.push_back(sum);
        }
        sum = 0;
        for(int i = n-1; i>= 0; i--){
            sum += v[i];
            suffixSum.push_back(sum);
        }
        reverse(suffixSum.begin(), suffixSum.end());



        int l, r, k;
        for(int i = 0;i < q; i++){
            cin >> l >> r >> k;
            int ans = 0;
            if(l-2 >= 0){
                ans += prefixSum[l-2];
            }
            if(r < n){
                ans += suffixSum[r];
            }
            // cout << ans << '\n';

            ans += (k * (r-l+1));

            if(ans % 2 == 0)cout << "NO\n";
            else cout << "YES\n";
        }
    }
    
}