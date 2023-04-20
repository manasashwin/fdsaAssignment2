#include <iostream>
#include <stack>

using namespace std;

stack<int> answer_sheets;
int maxInStackAndPop(){
    stack<int> s2;
    int maxN = 0;
    while(!answer_sheets.empty()){
        maxN = max(answer_sheets.top(), maxN);
        s2.push(answer_sheets.top());
        answer_sheets.pop();
    }
    bool removed = true;
    while (!s2.empty()){
        if(s2.top()==maxN && removed)
        {
            removed = false;
            s2.pop();
            continue;
        }
        answer_sheets.push(s2.top());
        s2.pop();
    }
    return maxN;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int total_punishment = 0;

        for (int i = 0; i < n; i++) {
            int score;
            cin >> score;

            if (score > 33) {
                answer_sheets.push(score);
            } else if (!answer_sheets.empty()) {
                total_punishment += maxInStackAndPop();
            }

        }

        cout <<"The total punishment is - "<< total_punishment << endl;
    }

    return 0;
}