#include "Question.h"
Question::Question(string textquestion, int correctasnweer) {
	this->textquestion = textquestion;
	this->correctanswer = correctasnweer;
	this->index = 0;
	this->currenttextqustion = "";
	this->InProgress = false;
}
Question::~Question(){}
string Question::getTextQuestion() {return textquestion;}
int Question::getCorrectAnswer() { return correctanswer; }
bool Question::CorrecAnswer(int answer){
	if (answer == correctanswer)return true;
	return false;
}
bool Question::Update() {
	if (!InProgress)return false;
	for (int i = 0; i < 3; i++) {
		if (index < textquestion.length()) {
			currenttextqustion += textquestion[index];
			index++;
		}
		else {
			InProgress = false;
			return false;
		}
	}

	return true;
}
bool Question::getInProgress() { return InProgress; }
void Question::setInProgress(bool InProgress) { this->InProgress = InProgress; }
string Question::getCurrentText() { return currenttextqustion; }