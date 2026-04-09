#pragma once
#include "Dialogue.h"
#include "FilesManagement.h"
class DialogueController
{
private:
	vector<string>dialogues;
	Dialogue* currentdialogue;
	FilesManagement* filesmanagement;
public:
	DialogueController();
	~DialogueController();
	void StarDialogue(char* route);
	string getDialogue(int index);
	Dialogue* getCurrentDialogue();
};

