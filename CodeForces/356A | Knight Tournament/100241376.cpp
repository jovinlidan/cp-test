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
ll ceil_(ll a, ll b)
{
    return (a+b-1)/b;
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

//bool checkPal(string s)
//{
//    int l = 0, r = s.length()-1;
//    while(l < r)
//    {
//        if(s[l] != s[r])return 0;
//        l++;
//        r--;
//    }
//    return 1;
//}
//int kadArr[105] = {}, n, m, grid[105][105] = {}, mx= -1e9 ;
//int kadane()
//{
//    int mxKad = kadArr[0], mxTotal= kadArr[0];
//
//    for(int i = 1; i < m; i++)
//    {
//        if(kadArr[i] + mxKad > kadArr[i])
//        {
//            mxKad = kadArr[i] + mxKad;
//        }
//        else mxKad = kadArr[i];
//        mxTotal = max(mxTotal, mxKad);
//    }
//    return mxTotal;
//}
//unordered_map<ll, int> mp;
//void solve(ll x)
//{
//    ll cnt = 0;
//    while(!(x&1))
//    {
//        x>>=1;
//        cnt++;
//    }
//    if(cnt)mp[2]+=cnt;
//    for(ll i = 3; i <= sqrt(x); i+=2)
//    {
//        cnt = 0;
//        while(x % i == 0)
//        {
//            cnt++;
//            x/=i;
//        }
//        //if(cnt)cout << i << " "<< cnt << '\n';
//        if(cnt)mp[i]+=cnt;
//    }
//    if(x > 2)mp[x]++;
//}



//void updateLP(int i, int j, int v, int L, int R, int pos)
//{
//    if(L > R)return;
//    if(lp[pos] != 0)
//    {
//        segTree[pos] += lp[pos];
//        if(L != R)
//        {
//            lp[(pos << 1) + 1] += lp[pos];
//            lp[(pos << 1) + 2] += lp[pos];
//        }
//        lp[pos] = 0;
//    }
//    if(i > R || j < L)return;
//    if(i <= L && j >= R)
//    {
//        segTree[pos] += v;
//        if(L != R)
//        {
//            lp[(pos << 1) + 1] += v;
//            lp[(pos << 1) + 2] += v;
//        }
//        return;
//    }
//    // parsial
//    updateLP(i, j, v, L, (L+R) >> 1, (pos << 1) + 1);
//    updateLP(i, j, v, ((L+R) >> 1) + 1, R, (pos << 1) + 2);
//    segTree[pos] = min(segTree[(pos << 1) + 1], segTree[(pos << 1) + 2]);
//}
//
//ll queryLP(int i, int j, int L, int R, int pos)
//{
//    if(L > R)return INT_MAX;
//    if(lp[pos] != 0)
//    {
//        segTree[pos] += lp[pos];
//        if(L != R)
//        {
//            lp[(pos << 1) + 1] += lp[pos];
//            lp[(pos << 1) + 2] += lp[pos];
//        }
//        lp[pos] = 0;
//    }
//
//    if(i > R || j < L)return INT_MAX;
//    if(i <= L && j >= R)return segTree[pos];
//
//    //parsial
//    return min(queryLP(i, j, L,((L+R) >> 1) , (pos << 1) + 1 ), queryLP(i, j, ((L+R) >> 1) + 1, R,(pos << 1) + 2 ));
//
//}
ll n , m;
const ll mxN = 8*132000;
ll segTree[mxN] = {}, ans[300005] = {};
bool updated[mxN] = {false};
void build(int p, int L, int R)
{
    if (L != R)
    {
        build((p << 1) + 1, L, ((L+R) >> 1) );
        build((p << 1) + 2, ((L+R) >> 1) + 1, R);
    }
    segTree[p] = -1;

}

void update(int p, int L, int R, int i, int j, int v) {
    //debug(L, R, i, j, v);
    if(L == R && L == v)return;
    if(updated[p])return;

    if (L > j || R < i || L > R)return;
    else if ( (L == i && R == j && !(v >= L && v <= R)) || (L == R))
    {
        if(segTree[p] == -1)
        {
            updated[p] = 1;
            segTree[p] = v;
            for(int gatau = L; gatau <= R; gatau++)ans[gatau] = v;

        }
    }
    else
    {
        update((p << 1) + 1, L, ((L+R) >> 1), i, j, v);
        update((p << 1) + 2, ((L+R) >> 1) + 1, R, i, j, v);
        updated[p] = updated[(p << 1) + 1] && updated[(p << 1) + 2];
    }
}

int query(int p, int L, int R, int i) {
    if (L > i || R < i)return -1;
    if(L > R)return -1;
    else if (L >= i && R <= i && segTree[p] != -1)
    {
        return segTree[p];
    }
    else
    {
        int left = query((p << 1)+1 , L, ((L+R) >> 1) , i);
        int right = query((p << 1) + 2, ((L+R) >> 1) + 1, R, i);
        return max(left, right);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    //cin>>tc;
    while(tc--)
    {
        int n, m, x, y, v, xxx;
        cin >> n >> m;
       // build(0, 0, n-1);
       memset(segTree, -1, sizeof segTree);
       //memset(ans, -1, sizeof ans);
        for(int i = 0; i < m; i++)
        {
            cin >> x >> y >> v;
            x--;
            y--;
            v--;
            update(0, 0,n-1, x, y, v);
//            debug( query(0, 0, n-1, 0));
//            debug( query(0, 0, n-1, 1));
//            debug( query(0, 0, n-1, 2));
//            debug( query(0, 0, n-1, 3));
            xxx = v;
        }
        for(int i = 0; i < n; i++)
        {
            if(i)cout << " ";
            if(xxx == i) cout << 0;
            else cout << ans[i]+1 ;
            //else cout << query(0, 0, n-1, i)+1;
        }
        cout <<'\n';



    }


    return 0;
}
