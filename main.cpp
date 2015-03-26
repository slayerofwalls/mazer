#include <iostream>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <string>
#include "room.h"
#include <stack>

using namespace std;

int const MAXSIZE = 100;
int getMazeSize(string fileName);
void loadMaze(room maze[MAXSIZE][MAXSIZE], string fileName,int curSize, int *mX, int *mY);
room loadRoom(char fileCharacter);
void printMaze(room maze[MAXSIZE][MAXSIZE], int curSize);
void clearMaze(room maze[MAXSIZE][MAXSIZE], int curSize);
int mouseX=0, mouseY=0;

int main() {
	string fileName;
	string tempString;
	stack<room> mazeRoute;
	int currentSize = 0;

	room maze[MAXSIZE][MAXSIZE] = {room()};

	cout << "Hello, please put the name of the file which contains the maze you are trying to solve." << endl;
	cin >> fileName;
	currentSize = getMazeSize( fileName );
	cout << "Current size stored as: " << currentSize << endl;

	loadMaze(maze, fileName, currentSize, &mouseX, &mouseY);
	system("clear");
	printMaze(maze, currentSize);
	cout << "The mouse is at grid coordinates: x = " << mouseX << ", y = " << mouseY << endl;
	system("read");
	return 0;
}

int getMazeSize(string fileName) {
	int getSize;
	bool fileGot = false;
	string tempString;
	string tempFileName = fileName;


	while (!fileGot) { 
		ifstream file(tempFileName.c_str());
		if (file.is_open()) {
			getline(file, tempString);
			getSize = atoi(tempString.c_str());
			cout << "Size pulled from file = " << getSize << endl;
			file.close();
			fileGot = true;
		}
		else {
			cout << "Invalid input for your file's name, please retype: "
				<< endl;
			cin >> tempFileName;
			cout << endl;
		}
	}
	return getSize;
}

void loadMaze(room maze[][MAXSIZE], string fileName, int curSize, int *mX, int *mY) {
	string tempFileName = fileName;
	string tempString;
	char tempChar;
	int counter = 0;
	bool read = false;
	room tempRoom;
	bool filler= true;

	string *stringArray;
	stringArray = new string[curSize];

	while (!read) {
		ifstream file(tempFileName.c_str());
		if (file.is_open()) {
			getline(file, tempString);//should skip the int at beginning;
			while (getline(file, tempString)) {
				stringArray[counter] = tempString;
				counter++;
				if (counter==curSize) {
					file.close();
					read = true;
				}
			}
		}
		else {
			cout << "Invalid input for your file's name, please retype: "
				<< endl;
			cin >> tempFileName;
			cout << endl;
		}
	}	

	for (int i=0;i<curSize; i++) {
		cout << stringArray[i] << endl;
	}

	cout << "This is the maze that was stored" << endl;
	system("read");

	//begin reading string array components to characters and sending chars to corresponding room;
	for (int a=0; a < curSize; a++) {
		for (int b=0; b<curSize; b++) {
			tempChar = stringArray[a].at(b);
			tempRoom.setContents(tempChar);
			if (tempRoom.isMouse()){
				mouseX = b;
				mouseY = a;
			}
			tempRoom.setFilled(filler);
			maze[a][b]=tempRoom;
		}
	}
}

void printMaze(room maze[][MAXSIZE], int curSize) {
	char charDisplay;

	for(int y=0; y<curSize; y++) {
		for (int x=0;x<curSize;x++) {
			charDisplay = maze[y][x].getContents();
			cout << charDisplay;
		}
		cout<<endl;
	}
}


