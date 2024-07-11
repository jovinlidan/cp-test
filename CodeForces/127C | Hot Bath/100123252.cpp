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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t1,t2,x1,x2,t0;
    cin>>t1>>t2>>x1>>x2>>t0;
    int y1,y2;
    double mx=2e9;
    while (x1 >= 0 && x2 >= 0)
    {
        double t = calc(t1,t2,x1,x2);
        if (t < t0)
        {
            x1--;
            continue;
        }
        if (t < mx)
        {
            mx = t;
            y1 = x1;
            y2 = x2;
        }
        x2--;
    }
    cout<<y1<<" "<<y2<<endl;




    /*int a,b;
    int bantua1 = t1;
    int bantub1 = t2;
    int bantua2 = t0;
    int bantub2 = t0;
    a = abs(bantua1 - bantua2);
    b = abs(bantub1 - bantub2);
    int bantu = __gcd(a,b);
    a/=bantu;
    b/=bantu;
    /*while (x1)
    {
        if (x1 % b == 0)
        {
            break;
        }
        x1--;
    }
    if (a == 0)
    {
        cout<<x1/b<<" "<<0<<endl;
    }
    else if (b == 0)
    {
        cout<<0<<" "<<x1/a<<endl;
    }
    else
    {
        cout<<x1/a<<" "<<x1/b<<endl;
    }*/

}


