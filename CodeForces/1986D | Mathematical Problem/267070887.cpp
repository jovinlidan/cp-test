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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> prefix(25), suffix(25);

    if(n == 2){
        cout << stoi(s) << '\n';
        return;
    }
    // map<int, map<char, ll>> prefix, suffix;

    prefix[0] = s[0] - '0';
    suffix[n-1] = s[n-1] - '0';

    for(int i = 1; i < n; i++){
        ll num = (s[i] - '0');
        prefix[i] = min(num * prefix[i-1], num + prefix[i-1]);
        
    }

    for(int i = n-2; i >= 0; i--){
        ll num = (s[i] - '0');
        suffix[i] = min(num * suffix[i+1], num + suffix[i+1]);
    }

    ll ans = 1e18;
    for(int i = 0; i < n-1; i++){
        ll num = ((s[i] - '0') * 10 + (s[i+1] - '0'));
        ll lastIdx = i-1;
        ll nextIdx = i+2;

            // cout << num << '\n';

        if(lastIdx >= 0 && nextIdx < n){
            ll temp = num;
            temp += prefix[lastIdx];
            temp += suffix[nextIdx];
            ans = min(ans, temp);


            temp = num;
            temp *= prefix[lastIdx];
            temp *= suffix[nextIdx];
            ans = min(ans, temp);

            temp = num;
            temp += prefix[lastIdx];
            temp *= suffix[nextIdx];
            ans = min(ans, temp);

            temp = num;
            temp *= prefix[lastIdx];
            temp += suffix[nextIdx];
            ans = min(ans, temp);
            // cout << prefix[lastIdx] << " " << suffix[nextIdx] << " " << lastIdx << " " << nextIdx << '\n';
        }
        else if(lastIdx >= 0){
            ll temp = num;
            temp += prefix[lastIdx];
            ans = min(ans, temp);

            temp = num;
            temp *= prefix[lastIdx];
            ans = min(ans, temp);
        }
        else if(nextIdx < n){
            ll temp = num;
            temp += suffix[nextIdx];
            ans = min(ans, temp);

            temp = num;
            temp *= suffix[nextIdx];
            ans = min(ans, temp);
        }
        else{
        }
        
    }
    cout << ans << '\n';


    // for(int i = 0; i < n-1; i++){
    //     // cout << num << '\n';
    //     // if prefix start from sum, the even index will be sum, otherwise the odd index will be mul
        
    //     // prefix sum
    //     ll lastIdx = i-1;
    //     ll nextIdx = i+2;
    //     if(lastIdx >= 0 && nextIdx < n){
    //         ll temp = num;
    //         temp += prefix[lastIdx]['+'];
    //         temp *= suffix[nextIdx]['*'];
    //         ans = min(ans, temp);

    //         temp = num;
    //         temp += prefix[lastIdx]['*'];
    //         temp *= suffix[nextIdx]['+'];
    //         ans = min(ans, temp);

    //         temp = num;
    //         temp *= prefix[lastIdx]['+'];
    //         temp += suffix[nextIdx]['*'];
    //         ans = min(ans, temp);

    //         temp = num;
    //         temp *= prefix[lastIdx]['*'];
    //         temp += suffix[nextIdx]['+'];
    //         ans = min(ans, temp);

    //         // cout << lastIdx << " " << nextIdx << '\n';

    //         // cout all prefix suffix above
    //         // cout << prefix[lastIdx]['+'] << " " << prefix[lastIdx]['*'] << " " << suffix[nextIdx]['+'] << " " << suffix[nextIdx]['*'] << '\n';
    //     }
    //     else if(lastIdx  >= 0){
    //         ll temp = num;
    //         temp += prefix[lastIdx]['+'];
    //         ans = min(ans, temp);

    //         temp = num;
    //         temp *= prefix[lastIdx]['*'];
    //         ans = min(ans, temp);

    //         temp = num;
    //         temp += prefix[lastIdx]['*'];
    //         ans = min(ans, temp);

    //         temp = num;
    //         temp *= prefix[lastIdx]['+'];
    //         ans = min(ans, temp);


    //         // cout << lastIdx << '\n';

    //         // cout << prefix[lastIdx]['+'] << " " << prefix[lastIdx]['*'] << '\n';
    //     }
    //     else if(nextIdx < n){
    //         ll temp = num;
    //         temp *= suffix[nextIdx]['*'];
    //         ans = min(ans, temp);

    //         temp = num;
    //         temp += suffix[nextIdx]['+'];
    //         ans = min(ans, temp);

    //         temp = num;
    //         temp *= suffix[nextIdx]['+'];
    //         ans = min(ans, temp);

    //         temp = num;
    //         temp += suffix[nextIdx]['*'];
    //         ans = min(ans, temp);
    //     }
    //     // else{
    //     //     ans = min(ans, num);
    //     // }
    // }
    // cout << ans << '\n';

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