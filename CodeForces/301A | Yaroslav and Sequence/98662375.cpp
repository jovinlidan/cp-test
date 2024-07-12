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

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //debug(kadane());

    int tc = 1;
    //cin>>tc;
    while(tc--)
    {
        int n, mn = 0;
        cin >> n;
        int arr[2*n+5] = {};
        for(int i = 0; i < 2*n-1; i++)
        {
            cin >> arr[i];
            if(arr[i] < 0)mn++;
            arr[i] = abs(arr[i]);
        }
        ll sum = 0;
        sort(arr, arr+ (2*n)-1);
//        ll temp = 0;
//        for(int i = 0; i < 2*n-1; i++)
//        {
//            cout << arr[i] << " ";
//            temp += arr[i];
//        }
//        debug(temp, mn);
        if(n&1)
        {
            for(int i = 0; i < 2*n-1; i++)
            {
                sum +=arr[i];
            }
        }
        else
        {
            for(int i = 1; i < 2*n-1; i++)
            {
                sum +=arr[i];
            }
            if(mn == 0 || mn == n || mn % 2 == 0)
            {
                sum += arr[0];
            }
            else sum -= arr[0];
        }
        cout << sum << '\n';
//        int cnt = n;
//        if(n >= 3 || n==1)
//        {
//            for(int i = 0; i < 2*n-1; i++)
//            {
//
//                sum+=abs(arr[i]);
//            }
//            cout << sum << '\n';
//            return 0;
//        }
//        if(mn == 3)
//        {
//            cnt = 2;
//            for(int i = 0; i < 2*n-1; i++)
//            {
//                if(arr[i] < 0 && cnt > 0)
//                {
//                    cnt--;
//                    arr[i] *= -1;
//                }
//                sum+=arr[i];
//            }
//
//        }
//        else if(mn == 2)
//        {
//            for(int i = 0; i < 2*n-1; i++)
//            {
//
//                sum+=abs(arr[i]);
//            }
//        }
//        else if(mn == 1)
//        {
//            cnt = 2;
//            for(int i = 0; i < 2*n-1; i++)
//            {
//                arr[i] = abs(arr[i]);
//            }
//            sort(arr, arr+n);
//            for(int i = 0; i < 2*n-1; i++)
//            {
//                if(i == 0)sum-=arr[i];
//                else sum+=arr[i];
//            }
//        }
//        else
//        {
//            for(int i = 0; i < 2*n-1; i++)
//            {
//
//                sum+=abs(arr[i]);
//            }
//        }
//        cout << sum << '\n';


    }


    return 0;
}
