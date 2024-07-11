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
        int n;
        cin  >> n;
        if( n == 2)cout << 2 << '\n';
        else if(n ==3 ) cout << 3 << '\n';
        else {
            int mx = -1e9, ans = 2;
            for(int i = 2; i<= n;i++){
                int cnt = n/i;
                int sn = (((cnt * 1.0)/ 2) * (i + (i * cnt)));
                if(sn > mx){
                    mx = sn;
                    ans = i;
                }
            }
            cout << ans << '\n';
        }

    }
    
}
