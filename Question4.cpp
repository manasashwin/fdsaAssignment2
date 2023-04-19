#include <iostream>
#include <stack>

using namespace std;

int main() {
    cout<< "Enter number of Test cases :";
    int t;
    cin >> t;

    while (t--) {
        cout<<"Enter number of answer sheets :";
        int n;
        cin >> n;

        stack<int> answer_sheets;
        int total_punishment = 0;

        for (int i = 0; i < n; i++) {
            int score;
            cin >> score;

            if (score > 33) {
                answer_sheets.push(score);
            } else if (!answer_sheets.empty()) {
                total_punishment += answer_sheets.top();
                answer_sheets.pop();
            }

        }

        cout <<"The total punishment is - "<< total_punishment << endl;
    }

    return 0;
}