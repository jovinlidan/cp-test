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

int gcdFunc(int a, int b) 
{ 
    // Everything divides 0 
    if (a == 0) 
        return b; 
    if (b == 0) 
        return a; 
  
    // base case 
    if (a == b) 
        return a; 
  
    // a is greater 
    if (a > b) 
        return gcd(a - b, b); 
    return gcd(a, b - a); 
} 

ll sn(ll n, ll a,ll b){
    return n/2.0 * (2*a + (n-1)*b);
}

void solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> fruits(n+5), height(n+5);

    ll mn = 1e18;
    for(int i = 0;i < n; i++){
        cin >> fruits[i];
        mn = min(mn, fruits[i]);
    }
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }

    ll start = -1, total = 0, ans = 0;
    for(int i = 1; i < n; i++){
        if(height[i-1] % height[i] == 0){
            if(start == -1){
                start = i-1;
                total += fruits[i-1];
                total += fruits[i];
            }else {
                total += fruits[i];
            }

            while(total > k && start < n){
                total -= fruits[start];
                start++;
            }
            if(start >= i){
                start = -1;
                total = 0;
            }

            if(start != -1){
                // cout << total << " - " << start << " - " << i << '\n';
                ans = max(ans, i - start + 1);
            }
            
        }else {
            if(start != -1){
                ans = max(ans, i - start);
            }
            start = -1;
            total = 0;
        
        }
    }
    // if( n == 1){
    //     if(fruits[0] <= k)cout << 1 << '\n';
    //     else cout << 0 << '\n';
    // }else{
    if(ans == 0 && mn <= k)cout << 1 << '\n';
    else cout << ans << '\n';
    // }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;

    while(tc--){
        solve();
    }
    
}
// 1 
// 1 1
// 1 
// 5