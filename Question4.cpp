#include <iostream>
#include <stack>

using namespace std;

//main stack that contains all answer sheet's scores
stack<int> answer_sheets;

//function to find maximum possible punishment
int maxpunishment(){
    stack<int> s2;
    int MaxScore = 0;

    // create a maxscore variable and compare top of stack to the maxscore .
    // then push value of  
    while(!answer_sheets.empty()){
        MaxScore = max(answer_sheets.top(), MaxScore); 
        s2.push(answer_sheets.top());
        answer_sheets.pop();
    }


    bool repeat = true;
    while (!s2.empty()){
        if(s2.top()==MaxScore && repeat) // function to make sure 2 highest numbers are not pushed twice
        {
            repeat = false;
            s2.pop();
            continue;
        }
        answer_sheets.push(s2.top()); //push top of s2 to answer sheets
        s2.pop();
    }
    return MaxScore;
}

int main() {
    int t;
    cout<<"enter number of cases :";
    cin >> t;

    while (t--) {
        int n;
        cout<<"enter total number of answer sheets :";
        cin >> n;

        int total_punishment = 0;
        cout<<"enter total scores of answer sheets :";

        for (int i = 0; i < n; i++) {
            int score;
            cin >> score;

            if (score > 33) {
                answer_sheets.push(score); // if passed , push score to answersheets stack
            } else if (!answer_sheets.empty()) {
                total_punishment += maxpunishment(); //if failed , call maxpunishment function
            }

        }

        cout <<"The total punishment is - "<< total_punishment << endl;
    }

    return 0;
}