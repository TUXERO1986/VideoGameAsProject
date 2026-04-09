#pragma once
#include "Enemy.h"
#include "Character.h"
#include "Background.h"
#include "Resource.h"
#include "Ally.h"
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
class FilesManagement
{
public:
	FilesManagement();
	void LoadGame(Character* character, std::vector<Enemy*>& enemyvector, Background* backgrround
		, std::vector<Resource*>& criticresourcevector, std::vector<Resource*>& helpfulresourcevector, std::vector<Ally*>& alliesvector, int& level);
	void SaveGame(Character* character, std::vector<Enemy*>& enemyvector, Background* backgrround
		, std::vector<Resource*> criticresourcevector, std::vector<Resource*> helpfulresourcevector, std::vector<Ally*> alliesvector, int level);
	std::vector<std::string> ReadLines(std::string filesname);
	std::vector<int> ReadInt(std::string filesname);
	void ReadQuiz(const std::string& filename,
		std::vector<std::string>& outTexts,
		std::vector<int>& outCorrect);
};

