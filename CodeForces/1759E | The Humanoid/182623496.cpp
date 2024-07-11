#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll arr[200005] = {};
ll n, h;
ll tc, green, blue;

ll solve2(ll i, ll h, ll green, ll blue)
{
    // cout << arr[i] << " , i = " << i << " , h = " << h << '\n';
    if (i == n)
        return 0;
    if (arr[i] < h)
    {
        return solve2(i + 1, h + (arr[i] / 2), green, blue) + 1;
    }
    ll mx1 = 0;
    ll mx2 = 0;
    if (green > 0)
    {
        mx1 = solve2(i, h * 2, green - 1, blue);
    }
    if (blue > 0)
    {
        mx2 = solve2(i, h * 3, green, blue - 1);
    }
    return max(mx1, mx2);
}

int main()
{
    cin >> tc;
    while (tc--)
    {
        cin >> n >> h;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + n);
        cout << solve2(0, h, 2, 1) << '\n';
        // for (int i = 0; i < n; i++)
        // {
        //     // cout << h << green << " " << blue << " - \n";
        //     if (h > arr[i])
        //     {
        //         h += (arr[i] / 2);
        //         ans++;
        //     }
        //     else
        //     {
        //         if (green >= 1 && h * 2 > arr[i])
        //         {
        //             green--;
        //             h *= 2;
        //             ans++;
        //             h += (arr[i] / 2);
        //         }
        //         if (blue >= 1 && h * 3 > arr[i] && h < arr[i])
        //         {
        //             blue--;
        //             h *= 3;
        //             ans++;
        //             h += (arr[i] / 2);
        //         }
        //         if (green >= 2 && h * 4 > arr[i] && h < arr[i])
        //         {
        //             green -= 2;
        //             h *= 4;
        //             ans++;
        //             h += (arr[i] / 2);
        //         }
        //         if (green >= 1 && blue >= 1 && h * 6 > arr[i] && h < arr[i])
        //         {
        //             green--;
        //             blue--;
        //             ans++;
        //             h += (arr[i] / 2);
        //         }
        //         if (green >= 2 && blue >= 1 && h * 12 > arr[i] && h < arr[i])
        //         {
        //             green -= 2;
        //             blue--;
        //             ans++;
        //             h += (arr[i] / 2);
        //         }
        //     }
        // }
        // cout << ans << '\n';
    }
}
