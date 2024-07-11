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

ll n , m;
const ll mxN = 4*132000;
ll segTree[mxN] = {}, lp[mxN] = {};
int arr[200005] = {};
void build(int p, int L, int R) {
    if (L == R) {
        segTree[p] = arr[L];
    }
    else {
        build((p << 1) + 1, L, ((L+R) >> 1) );
        build((p << 1) + 2, ((L+R) >> 1) + 1, R);
        segTree[p] = min(segTree[(p << 1) + 1], segTree[(p << 1) + 2]);
    }
}

void updateLP(int i, int j, int v, int L, int R, int pos)
{
    if(L > R)return;
    if(lp[pos] != 0)
    {
        segTree[pos] += lp[pos];
        if(L != R)
        {
            lp[(pos << 1) + 1] += lp[pos];
            lp[(pos << 1) + 2] += lp[pos];
        }
        lp[pos] = 0;
    }
    if(i > R || j < L)return;
    if(i <= L && j >= R)
    {
        segTree[pos] += v;
        if(L != R)
        {
            lp[(pos << 1) + 1] += v;
            lp[(pos << 1) + 2] += v;
        }
        return;
    }
    // parsial
    updateLP(i, j, v, L, (L+R) >> 1, (pos << 1) + 1);
    updateLP(i, j, v, ((L+R) >> 1) + 1, R, (pos << 1) + 2);
    segTree[pos] = min(segTree[(pos << 1) + 1], segTree[(pos << 1) + 2]);
}

ll queryLP(int i, int j, int L, int R, int pos)
{
    if(L > R)return INT_MAX;
    if(lp[pos] != 0)
    {
        segTree[pos] += lp[pos];
        if(L != R)
        {
            lp[(pos << 1) + 1] += lp[pos];
            lp[(pos << 1) + 2] += lp[pos];
        }
        lp[pos] = 0;
    }

    if(i > R || j < L)return INT_MAX;
    if(i <= L && j >= R)return segTree[pos];

    //parsial
    return min(queryLP(i, j, L,((L+R) >> 1) , (pos << 1) + 1 ), queryLP(i, j, ((L+R) >> 1) + 1, R,(pos << 1) + 2 ));

}

//void update(int p, int L, int R, int i, int v) {
//    if (L > i || R < i) {
//        return;
//    }
//    else if (L == i && R == i) {
//        segTree[p] += v;
//    }
//    else {
//        update((p << 1) + 1, L, ((L+R) >> 1), i, v);
//        update((p << 1) + 2, ((L+R) >> 1) + 1, R, i, v);
//        segTree[p] = min(segTree[(p << 1) + 1], segTree[(p << 1) + 2]);
//    }
//}
//
//int query(int p, int L, int R, int i, int j) {
//    if (L > j || R < i) {
//        return 2e9;
//    }
//    else if (L >= i && R <= j) {
//        return segTree[p];
//    }
//    else {
//        int left = query((p << 1)+1 , L, ((L+R) >> 1) , i, j);
//        int right = query((p << 1) + 2, ((L+R) >> 1) + 1, R, i, j);
//        return min(left, right);
//    }
//}
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
        int n, m;
        cin >> n;
        for(int i = 0; i < n; i++)cin >> arr[i];
        build(0, 0, n-1);
        cin >> m;
        vector<int> xx;
        int x;
        string str;
        cin.ignore();
        while(m > 0)
        {
            m--;
            x = 0;
            xx.clear();
            xx.resize(0,0);
            str = "";
            getline(cin, str);
            stringstream ss(str);
            int cnt = 0;
            while (!ss.eof())
            {
                ss >> x;
                xx.push_back(x);
               cnt++;
            }

            if(cnt == 2)
            {
                if(xx[0] > xx[1])
                {
                    cout << min(queryLP(xx[0], n-1, 0, n-1, 0), queryLP(0, xx[1], 0, n-1, 0)) << '\n';
                }
                else
                {
                    cout << queryLP(xx[0],xx[1], 0, n-1, 0) << '\n';
                }
            }
            else
            {
                if(xx[0] > xx[1])
                {
                    updateLP(xx[0], n-1, xx[2], 0, n-1, 0);
                    updateLP(0, xx[1],  xx[2], 0, n-1, 0);
                }
                else
                {
                    updateLP(xx[0], xx[1],  xx[2], 0, n-1, 0);

                }
            }
            //debug(query(0, 0, n-1, 1, 1));
        }


    }


    return 0;
}
