#include "QuestionController.h"
QuestionController::QuestionController() {
}
QuestionController::~QuestionController() {
	for (auto a : questionvector)delete a;
	questionvector.clear();
}
void QuestionController::AddQuestion(Question* temp) {
	questionvector.push_back(temp);
}
Question* QuestionController::getCurrentQuestion(int index) {
	return questionvector[index];
}
void QuestionController::StartQuiz(string filesname) {
	for (auto a : questionvector) {
		delete a;
	}
	questionvector.clear();
	FilesManagement* fm= new FilesManagement();
	std::vector<std::string> texts;
	std::vector<int> answers;

	fm->ReadQuiz(filesname, texts, answers);

	for (int i = 0; i < (int)texts.size(); i++) {
		AddQuestion(new Question(texts[i], answers[i]));
	}
	delete fm;
}