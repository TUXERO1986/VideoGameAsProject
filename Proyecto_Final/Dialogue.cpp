#include "Dialogue.h"
Dialogue::Dialogue(){
	this->alltext = "";
	this->currentext = "";
	this->index = 0;
	this->counter = 0;
	this->InProgress = false;
}
Dialogue::~Dialogue() {}
void Dialogue::Start(string text, TypeDialogue typedialogue, Hierarchy hierarchy) {
	this->typedialogue = typedialogue;
	this->hierarchy = hierarchy;
	this->alltext = text;
	this->currentext = "";
	this->index = 0;
	this->counter = 0;
	this->InProgress = true;
}
bool Dialogue::Update() {
	if (!InProgress)return false;
	for (int i = 0; i < 3; i++) {
		if (index < alltext.length()) {
			currentext += alltext[index];
			index++;
		}
		else {
			InProgress = false;
			return false;
		}
	}

	return true;
}
void Dialogue::Stop() {
	InProgress = false;
}
string Dialogue::getCurrenttext() {
	return currentext;
}
bool Dialogue::getInProgress() {
	return InProgress;
}
Hierarchy Dialogue::getHierarchy() {
	return hierarchy;
}
TypeDialogue Dialogue::getTypeDialogue() {
	return typedialogue;
}