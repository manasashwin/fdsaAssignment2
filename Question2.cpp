#include <iostream>
#include <math.h>
using namespace std;

bool greaterh(int i1, int i2)
{
    return (i1 > i2);
}
int main()
{
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n;
        cin >> k;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int l;
            cin >> l;
            arr.push_back(l);
        }
        sort(arr.begin(), arr.end(), greaterh);
        int i = 0;
        int balls = 0;
        while(k-- && i<n){
            balls += floor(log2(arr[i])+1);
            i++;
        }
        cout << balls << endl;
    }
}