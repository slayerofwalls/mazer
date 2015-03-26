#ifndef ROOMH
#define ROOMH

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std; 

class room {
	public:
		bool getVisited();
		void setVisited(bool v);
		bool getIntersection();
		void setIntersection(bool i);
		bool setRejected(bool r);
		bool getRejected();
		char getContents();
		void setContents(char c);
		bool isWall();
		bool isOpen();
		bool isCheese();
		bool isMouse();
		bool getAccepted();
		void setAccepted(bool a) ;
		void setFilled(bool f);
		bool getFilled();
		void setCoords(int x, int y);
		int getY();
		int getX();

	private:
		char contents;
		bool visited;
		bool intersection;
		bool rejected;
		bool accepted;
		bool filled;
		int xCoord;
		int yCoord;
};
#endif
