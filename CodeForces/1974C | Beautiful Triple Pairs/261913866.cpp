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

vector<int> vec;
ll dp[100005] = {};
ll solve(int n,int idx, int x, int y, int z){
    if(idx >= n-2 || z >= n)return 0;
        // cout << idx << ' ' << x << ' ' << y << ' ' << z << '\n';
    if(dp[idx] != -1)return dp[idx];
    int correct = 0;
    if((vec[idx] != vec[x] && vec[idx+1] == vec[y] && vec[idx+2] == vec[z]) || (vec[idx] == vec[x] && vec[idx+1] != vec[y] && vec[idx+2] == vec[z]) || (vec[idx] == vec[x] && vec[idx+1] == vec[y] && vec[idx+2] != vec[z])){
        // return dp[idx] = 1 + solve(n,idx+1,idx+1,idx+2);
        correct = 1;
        // return dp[idx] = 1 + solve(n,idx+1,x,y,z) + solve(n, idx+1, idx, idx+1, idx+2);
    }
    int pls = 0;
    if(idx == x){
        // pls = 1;
    }
    return dp[idx] = correct + solve(n,idx, x+1,y+1,z+1) + solve(n, idx+1, x + pls, y + pls, z + pls) ;
    // return dp[idx] = solve(n,idx+1,x,y,z) + solve(n, idx+1, idx, idx+1, idx+2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    map<pair<ll, ll>, ll> mpl;
    map<pair<ll, ll>, ll> mpm;
    map<pair<ll, ll>, ll> mpr;
    map<pair<ll, pair<ll, ll>>, ll> mp;
    while(tc--){
        ll ans = 0;
        int n;
        cin >> n;
        vec.clear();
        vec.resize(n+5);
        mpl.clear();
        mpm.clear();
        mpr.clear();
        mp.clear();
        
        for(int i = 0 ; i < n ; i++){
            cin >> vec[i];
        }
        for(int i = 0; i < n-2; i++){
            mpl[{vec[i], vec[i+1]}]++;
            mpm[{vec[i+1], vec[i+2]}]++;
            mpr[{vec[i], vec[i+2]}]++;

            mp[{vec[i], {vec[i+1], vec[i+2]}}]++;

            ans += mpl[{vec[i], vec[i+1]}];
            ans += mpm[{vec[i+1], vec[i+2]}];
            ans += mpr[{vec[i], vec[i+2]}];

            ans -= (mp[{vec[i], {vec[i+1], vec[i+2]}}] * 3);
        }
        cout << ans << '\n';

        



    }
    
    
}
