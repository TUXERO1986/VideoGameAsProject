#pragma once
#include <string>
enum Hierarchy{Low,Medium,High};
enum TypeDialogue {hits,killenemy,criticresource,helpfulresource,passlevel,story};
using namespace std;
class Dialogue
{
private:
	string alltext;
	string currentext;
	Hierarchy hierarchy;
	TypeDialogue typedialogue;
	int index;
	int counter;
	bool InProgress;
public:
	Dialogue();
	~Dialogue();
	void Start(string text, TypeDialogue typedialogue, Hierarchy hierarchy);
	bool Update();
	void Stop();
	string getCurrenttext();
	bool getInProgress();
	Hierarchy getHierarchy();
	TypeDialogue getTypeDialogue();
};

