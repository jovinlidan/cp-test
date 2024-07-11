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

void pOutput(int a, int b, int c){
    a++;
    b++;
    c++;
    vector<int> v = {a, b, c};

    int mx = a;
    if(b < mx && (b > c || c > mx))mx = b;
    else if(c < mx && (c > b || b > mx))mx = c;

    if(mx == a)cout << 1;
    else cout << mx+1;
    cout << " " << a << " ";

    mx = b;
    if(a < mx && (a > c || c > mx))mx = a;
    else if(c < mx && (c > a || a > mx))mx = c;

    if(mx == b)cout << 1;
    else cout << mx+1;
    cout << " " << b << " ";

    mx = c;
    if(b < mx && (b > a || a > mx))mx = b;
    else if(a < mx && (a > b || b > mx))mx = a;

    if(mx == c)cout << 1;
    else cout << mx+1;
    cout << " " << c << '\n';

    
    
    
}

void solve(){
    int n, x;
    vector<ll> a, b,c, pa, pb, pc;
    ll sum = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        sum += x;
        pa.push_back(sum);
        a.push_back(x);
    }
    ll tot = ceil(sum/ 3.0);
    sum = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        sum += x;
        pb.push_back(sum);
        b.push_back(x);
    }
    sum = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        sum += x;
        pc.push_back(sum);
        c.push_back(x);
    }
    int aa = -1, bb = -1, cc = -1;
    for(int i = 0; i < n; i++){
        if(pa[i] >= tot){
            aa = i;
            for(int j = i+1; j < n; j++){
                if(pb[j] - pb[i] >= tot){
                    bb = j;
                    for(int k = j+1; k < n; k++){
                        if(pc[k] - pc[j] >= tot){
                            cc = k;
                            break;
                        }
                    }
                    break;
                }
            }

            if(aa != -1 && bb != -1 && cc != -1){
                pOutput(aa, bb, cc);
                return;
            }
            bb = -1, cc = -1;
            for(int k = i+1; k < n; k++){
                if(pc[k] - pc[i] >= tot){
                    cc = k;
                    for(int j = k+1; j < n; j++){
                        if(pb[j] - pb[k] >= tot){
                            bb = j;
                            break;
                        }
                    }
                    break;
                }
            }
            if(aa != -1 && bb != -1 && cc != -1){
                pOutput(aa, bb, cc);
                return;
            }
            break;
        }
    }
    aa = -1, bb = -1, cc = -1;
    for(int i = 0; i < n; i++){
                    // cout << pb[i] << ' ' << i << '\n';
        if(pb[i] >= tot){
            bb = i;
            for(int j = i+1; j < n; j++){
                if(pa[j] - pa[i] >= tot){
                    aa = j;
                    for(int k = j+1; k < n; k++){
                        if(pc[k] - pc[j] >= tot){
                            cc = k;
                            break;
                        }
                    }
                    break;
                }
            }
            if(aa != -1 && bb != -1 && cc != -1){
                pOutput(aa, bb, cc);
                return;
            }
            aa = -1, cc = -1;

            for(int k = i+1; k < n; k++){
                if(pc[k] - pc[i] >= tot){
                    cc = k;
                    for(int j = k+1; j < n; j++){
                        if(pa[j] - pa[k] >= tot){
                            aa = j;
                            break;
                        }
                    }
                    break;
                }
            }
            if(aa != -1 && bb != -1 && cc != -1){
                pOutput(aa, bb, cc);
                return;
            }
            break;
        }
    }

    aa = -1, bb = -1, cc = -1;
    for(int i = 0; i < n; i++){
        if(pc[i] >= tot){
            cc = i;
            for(int j = i+1; j < n; j++){
                if(pb[j] - pb[i] >= tot){
                    bb = j;
                    for(int k = j+1; k < n; k++){
                        if(pa[k] - pa[j] >= tot){
                            aa = k;
                            break;
                        }
                    }
                    break;
                }
            }
            if(aa != -1 && bb != -1 && cc != -1){
                pOutput(aa, bb, cc);
                return;
            }
            bb = -1, aa = -1;

            for(int k = i+1; k < n; k++){
                if(pa[k] - pa[i] >= tot){
                    aa = k;
                    for(int j = k+1; j < n; j++){
                        if(pb[j] - pb[k] >= tot){
                            bb = j;
                            break;
                        }
                    }
                    break;
                }
            }
            if(aa != -1 && bb != -1 && cc != -1){
                pOutput(aa, bb, cc);
                return;
            }
            break;
        }
    }
    cout << -1 << '\n';


    

    
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