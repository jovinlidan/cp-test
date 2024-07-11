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
#define mxN 10000005
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
double sl(int x1, int y1, int x2, int y2)
{
    return sqrt(( (x2-x1) * (x2-x1)) + ((y2-y1) * (y2-y1)));
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //debug(kadane());

    int tc=1;
    //cin>>tc;
    while(tc--)
    {
        int n, xxx;
        cin >> n;
        unordered_map<int, int>mp;
        for(int i = 0; i < n; i++)
        {
            cin >> xxx;
            mp[xxx]++;
        }
        int ans = 0;
        for(int i = 1; i <= 100; i++)
        {
            for(int j = 1; j <= 100; j++)
            {
                if(i != j)
                {
                    if((mp[i]>>1) >= 1 && (mp[j] >>1) >= 1)
                    {
                        int gap = min(mp[i]>>1 , mp[j] >> 1);
                        ans += gap;
                        mp[i] -= 2*gap;
                        mp[j] -= 2*gap;
                    }
                }
            }
        }

        for(int i = 1; i <= 100; i++)
        {
            if((mp[i]>>2 ) >= 1)
            {
                ans += (mp[i]>>2);
            }
        }
        cout << ans << '\n';





    }

    return 0;
}
