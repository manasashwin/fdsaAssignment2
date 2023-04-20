/*
    The user is asked to enter the total number of 
    answer sheets (students) and their scores. For each answer sheet, the program 
    checks whether the score is greater than 33 (the passing score). If it is, the 
    score is added to a stack called answer_sheets. If it's not, the program calls 
    a function called maxpunishment() to calculate the maximum possible punishment for that student.

    The maxpunishment() function works by creating a second stack called s2 and emptying 
    the answer_sheets stack into it. It then finds the maximum score in the s2 stack and 
    removes it from the stack (to avoid counting it twice). Finally, it empties the s2 stack
    back into the answer_sheets stack, except for the maximum score. The function returns the 
    maximum score found. After all the answer sheets have been processed, the program prints out 
    the total punishment, which is the sum of the maximum possible punishments 
    for all the failed students.


    Team Members:
    Name: Amlan Deep Mohapatra, ID number 2021AAPS1330H 
    Name: Manas Ashwin, ID number 2021B4AA1908H
    Name: Jaskirat Singh Kalra, ID number 2021A3PSH
*/
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