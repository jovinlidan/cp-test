#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    a %= b;
    return gcd(b, a);
}

ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc, k;
    string s, ans = "";
    cin >> tc;

    while (tc--)
    {
        cin >> s >> k;
        ans = "";
        if (k == 0)
            cout << s << '\n';
        else
        {
            string ans = "9";
            int start = 0;
            for (int i = 0; i <= k; i++)
            {
                if (s[i] == '0')
                    continue;
                if (ans[0] > s[i])
                {
                    start = i;
                    ans[0] = s[i];
                }
            }
            k -= start;
            for (int i = start + 1; i < s.length(); i++)
            {
                while (k > 0 && ans.length() > 1 && s[i] < ans.back())
                {
                    ans.pop_back();
                    k--;
                }
                ans.push_back(s[i]);
            }
            while (k--)
            {
                ans.pop_back();
            }
            cout << ans << '\n';
        }
    }
    return 0;
}