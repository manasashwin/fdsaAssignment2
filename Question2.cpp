#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cout<<"enter number of bags :";
        cin >> n;
        cout<<"enter number of minutes allowed :";
        cin >> k;
        vector<int> arr;
        priority_queue<int> pq;
        cout<<"enter number of balls :";

        // enter number of balls in each bag and push into priority queue
        for (int i = 0; i < n; i++)
        {
            int l;
            cin >> l;
            pq.push(l);
        }
        
        int balls = 0;
        while(k--){
            int newBalls = pq.top();
            balls += newBalls; 
            // adds the top of the priority queue i.e the largest ball containing bag into the balls var
            pq.pop();
            pq.push(floor(newBalls/2)); // pushes half of the previous value to priority queue
        
        }
        cout << "Maximum balls that you can collect " << balls << endl;
    }
}