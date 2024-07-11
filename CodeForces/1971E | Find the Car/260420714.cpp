#include <bits/stdc++.h>

using namespace std;

bool isEdge(int i, int j, int x, int y)
{
    if (i == 0 || j == 0 || i == x - 1 || j == y - 1)
        return true;
    return false;
}

int tc;
long long n, k, q, x;
vector<long long> points;
vector<long long> times;
vector<double> currentSpeed; 

int binarySearch(int length, int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (points[mid] == x)return mid;
        else if(points[mid] < x && mid == length)return mid;
        else if(points[mid] > x && mid == length)return mid;

        if (points[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return 0;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   cin >> tc;
   while(tc--){
        points.clear();
        times.clear();
        currentSpeed.clear();

        cin >> n >> k >> q;
        for ( int i = 0 ; i < k; i++){
            cin >> x;
            points.push_back(x);
        }
        for ( int i = 0 ; i < k; i++){
            cin >> x;
            times.push_back(x);
        }
        for(int i = 0; i < q; i++){
            if( i != 0 )cout << " ";
            cin >> x;
            int index = lower_bound(points.begin(), points.end(), x) - points.begin();
            if(index == 0){
                cout << int((x * times[index] * 1.0)/ points[index]);
            }
            else{
                cout << times[index-1] + int(((x - points[index-1]) * (times[index] - times[index-1]) * 1.0 ) / (points[index] - points[index-1]));
            }

        }
        cout << '\n';



   }

    return 0;
}