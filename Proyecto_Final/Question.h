#pragma once
#include<vector>
#include <string>
using namespace std;
class Question
{
private:
    string textquestion;
    string currenttextqustion;
    int correctanswer;   
    bool InProgress;
    int index;
public:
    Question(string textquestion, int correctasnweer);
    ~Question();
    bool Update();
    string getTextQuestion();
    int getCorrectAnswer();
    void setInProgress(bool InProgress);
    bool getInProgress();
    string getCurrentText();
    bool CorrecAnswer(int answer);
};

