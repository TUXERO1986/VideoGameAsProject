#pragma once
#include "Question.h"
#include "FilesManagement.h"
class QuestionController
{
private:
	vector<Question*> questionvector;
	bool quizinprogress;
public:
	QuestionController();
	~QuestionController();
	void AddQuestion(Question* temp);
	Question* getCurrentQuestion(int index);
	void StartQuiz(string filesname);

};

