#include "FilesManagement.h"
FilesManagement::FilesManagement(){}
void FilesManagement::LoadGame(Character* character, std::vector<Enemy*>& enemyvector, Background* backgrround
	, std::vector<Resource*>& criticresourcevector, std::vector<Resource*>& helpfulresourcevector, std::vector<Ally*>& alliesvector, int& level) {
	std::ifstream file("Texts\\saved1.txt");
	if (!file.is_open())return;
	int jx, jy, jhealth, jpoints;
	file >> jx >> jy >> jhealth >> jpoints;
	character->setX(jx);
	character->setY(jy);
	character->setHealth(jhealth);
	character->setPoints(jpoints);
	int enemiesvectorsize;
	file >> enemiesvectorsize;
	enemyvector.clear();
	for (int i = 0; i < enemiesvectorsize; i++) {
		int ex, ey, edx, edy,ehealth, espeed, edamage;
		float escale;
		int rows, columns;
		int etypeInt;
		char image[100];
		file >> ex >> ey >> escale >> edx >> edy >> ehealth >> espeed >> edamage >> rows>>columns>>etypeInt >> image;
		TypeWorld eTypeWorld = (TypeWorld)etypeInt;
		Enemy* temp = new Enemy(ex, ey, escale,ehealth,espeed, edamage, eTypeWorld);
		temp->LoadImage(image, rows, columns);
		temp->setDX(edx);
		temp->setDY(edy);
		enemyvector.push_back(temp);
	}
	int alliesvectorsize;
	file >> alliesvectorsize;
	for (int i = 0; i < alliesvectorsize; i++) {
		int ex, ey, edx, edy;
		float escale;
		int rows, columns;
		int etypeInt;
		char image[100];
		file >> ex >> ey >> escale >> edx >> edy >> rows >> columns >> etypeInt >> image;
		TypeWorld eTypeWorld = (TypeWorld)etypeInt;
		Ally* temp = new Ally(ex, ey, escale, eTypeWorld);
		temp->LoadImage(image, rows, columns);
		temp->setDX(edx);
		temp->setDY(edy);
		alliesvector.push_back(temp);
	}
	int criticvectorsize;
	file >> criticvectorsize;
	for (int i = 0; i < criticvectorsize; i++) {
		int ex, ey;
		int rows, columns;
		int etypeInt;
		char image[100];
		file >> ex >> ey >> rows >> columns >> etypeInt >> image;
		TypeWorld eTypeWorld = (TypeWorld)etypeInt;
		Resource* temp = new Resource(ex, ey, eTypeWorld);
		temp->LoadImage(image, rows, columns);
		criticresourcevector.push_back(temp);
	}
	int helpfulvectorsize;
	file >> helpfulvectorsize;
	for (int i = 0; i < helpfulvectorsize; i++) {
		int ex, ey;
		int rows, columns;
		int etypeInt;
		char image[100];
		file >> ex >> ey >>rows>>columns>>etypeInt >> image;
		TypeWorld eTypeWorld = (TypeWorld)etypeInt;
		Resource* temp = new Resource(ex, ey,eTypeWorld);
		temp->LoadImage(image, rows, columns);
		helpfulresourcevector.push_back(temp);
	}
	char imagebackground[100];
	file >> imagebackground;
	backgrround->LoadImage(imagebackground, backgrround->getwidth(), backgrround->getheight());
	int currentelevel;
	file >> currentelevel;
	level = currentelevel;
	
	file.close();
}
void FilesManagement::SaveGame(Character* character, std::vector<Enemy*>& enemyvector, Background* backgrround
	, std::vector<Resource*> criticresourcevector, std::vector<Resource*> helpfulresourcevector, std::vector<Ally*> alliesvector, int level) {
	std::ofstream file("Texts\\saved1.txt");
	if (!file.is_open())return;
	file << character->getX() << " "
		<< character->getY() << " "
		<< character->getHealth() << " "
		<< character->getPoints() << "\n";
	file << enemyvector.size() << "\n"; 
	for (int i = 0; i < enemyvector.size(); i++) {
		file << enemyvector[i]->getX() << " "
			<< enemyvector[i]->getY() << " "
			<< enemyvector[i]->getScale() << " "
			<< enemyvector[i]->getDX() << " "
			<< enemyvector[i]->getDY() << " "
			<< enemyvector[i]->getHealth() << " "
			<< enemyvector[i]->getSpeed() << " "
			<< enemyvector[i]->getDamage() << " "
			<<enemyvector[i]->getRows()<<" " 
			<<enemyvector[i]->getColumns()<<" "
			<< (int)enemyvector[i]->getTypeWorld() << " "
			<< enemyvector[i]->getImage() << "\n";
	}
	file << alliesvector.size() << "\n";
	for (int i = 0; i < alliesvector.size(); i++) {
		file << alliesvector[i]->getX() << " "
			<< alliesvector[i]->getY() << " "
			<< alliesvector[i]->getScale() << " "
			<< enemyvector[i]->getDX() << " "
			<< enemyvector[i]->getDY() << " "
			<< alliesvector[i]->getRows() << " "
			<< alliesvector[i]->getColumns() << " "
			<< (int)alliesvector[i]->getTypeWorld() << " "
			<< alliesvector[i]->getImage() << "\n";
	}
	file << criticresourcevector.size() << "\n";
	for (int i = 0; i < criticresourcevector.size(); i++) {
		file << criticresourcevector[i]->getX() << " "
			<< criticresourcevector[i]->getY() << " "
			<< criticresourcevector[i]->getRows() << " "
			<< criticresourcevector[i]->getColumns() << " "
			<< (int)criticresourcevector[i]->getTypeWorld() << " "
			<< criticresourcevector[i]->getImage() << "\n";
	}
	file << helpfulresourcevector.size() << "\n";
	for (int i = 0; i < helpfulresourcevector.size(); i++) {
		file << helpfulresourcevector[i]->getX() << " "
			<< helpfulresourcevector[i]->getY() << " "
			<< helpfulresourcevector[i]->getRows() << " "
			<< helpfulresourcevector[i]->getColumns() << " "
			<< (int)helpfulresourcevector[i]->getTypeWorld() << " "
			<< helpfulresourcevector[i]->getImage() << "\n";
	}
	file << backgrround->getImage()<<"\n";
	file << level;
	file.close();
}
std::vector<std::string> FilesManagement::ReadLines(std::string filesname) {
	std::vector<std::string> lines;
	std::ifstream file(filesname);

	if (file.is_open()) {
		std::string line;
		while (getline(file, line)) {
			lines.push_back(line);
		}
		file.close();
	}

	return lines;
}
std::vector<int> FilesManagement::ReadInt(std::string filesname) {
	std::vector<int> data;
	std::ifstream file(filesname);

	if (file.is_open()) {
		std::string line;
		if (getline(file, line)) {
			//std::stringstream ss(line);
			std::string valor;

			while (getline(file, valor)) {
				data.push_back(stoi(valor));
			}
		}
		file.close();
	}

	return data;
}
static int ParseCorrectLine(const std::string& line) {
	// Espera: "Correct: 2"
	size_t pos = line.find("Correct:");
	if (pos == std::string::npos) return 0;

	std::string num = line.substr(pos + 8);
	while (!num.empty() && num[0] == ' ') num.erase(num.begin());

	int v = std::stoi(num);
	if (v < 0) v = 0;
	if (v > 3) v = 3;
	return v;
}
void FilesManagement::ReadQuiz(const std::string& filename,
	std::vector<std::string>& outTexts,
	std::vector<int>& outCorrect) {
	outTexts.clear();
	outCorrect.clear();

	std::ifstream file(filename);
	if (!file.is_open()) return;

	std::string qline;
	while (std::getline(file, qline)) {
		if (qline.empty()) continue;

		std::string A, B, C, D, correctLine;

		if (!std::getline(file, A)) break;
		if (!std::getline(file, B)) break;
		if (!std::getline(file, C)) break;
		if (!std::getline(file, D)) break;
		if (!std::getline(file, correctLine)) break;

		int correct = ParseCorrectLine(correctLine);

		std::ostringstream oss;
		oss << qline << "\n" << A << "\n" << B << "\n" << C << "\n" << D;

		outTexts.push_back(oss.str());
		outCorrect.push_back(correct);
	}
}