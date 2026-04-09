#include "DialogueController.h"
DialogueController::DialogueController() {
	this->currentdialogue = new Dialogue();
	this->filesmanagement = new FilesManagement();
}
DialogueController::~DialogueController() {
	delete currentdialogue;
	delete filesmanagement;
}
void DialogueController::StarDialogue(char* route) {
	vector<string> lines = filesmanagement->ReadLines(route);
	for (int i = 0; i < lines.size();i++) {
		string temp = lines[i];
		dialogues.emplace_back(temp);
	}
}
string DialogueController::getDialogue(int index) {
	if (index >= 0 || index < dialogues.size())
		return dialogues[index];
	else return "";
}
Dialogue* DialogueController::getCurrentDialogue() {
	return currentdialogue;
}
