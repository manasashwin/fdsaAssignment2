#include <iostream>
#include <math.h>
#include <queue>
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
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            int l;
            cin >> l;
            pq.push(l);
        }
        int i = 0;
        int balls = 0;
        while(k--){
            int newBalls = pq.top();
            balls += newBalls;
            pq.pop();
            pq.push(floor(newBalls/2));
            i++;
        }
        cout << balls << endl;
    }
}