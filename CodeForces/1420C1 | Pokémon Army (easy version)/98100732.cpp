#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define mxN 300005
#define INF -1e9
typedef pair<int, int> pii;
 
typedef long long int ll;
const int mod = 1e9+7;
 
ll modpow(ll x, ll y, ll m)
{
    ll res = 1;
    while(y > 0)
    {
        if(y & 1)
            res = (res * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
 
    return res;
}
 
bool cmp(pii l, pii r)
{
    if(l.first == r.first)
    {
        return l.second > r.second;
    }
    return l.first < r.first;
}
 
//void sieve()
//{
//    vector<bool> prime(mxN, true);
//    int n = mxN;
//    prime[0] = prime[1] = false;
//    for (int i = 2; i <= n; i++) {
//        if (prime[i] && (long long)i * i <= n) {
//            for (int j = i * i; j <= n; j += i)
//                prime[j] = false;
//        }
//    }
//    primeList.push_back(2);
//    for(int j = 3 ; j <= mxN ; j+=2)
//    {
//        if (prime[j])
//        {
//            isPrime[j] = 1;
//        }
//    }
//}

int n, q;
int arr[mxN] = {};
ll dp[mxN][2] = {};
ll solve(int idx, bool mins)
{
	if(idx >= n)return 0;
	if(dp[idx][mins] != -1)return dp[idx][mins];
	ll val = -1e18;
	if(mins)val = max(val, solve(idx+1, !mins) + arr[idx]);
	else val = max(val, solve(idx+1, !mins) - arr[idx]);
	val = max(val, solve(idx+1, mins));
	return dp[idx][mins] = val;
	
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int tc;
    cin>>tc;
    while(tc--)
    {
			memset(dp, -1, sizeof dp);
			cin >> n >> q;
			for(int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			cout << solve(0, 1) << '\n';
    }
 
 
    return 0;
}
 