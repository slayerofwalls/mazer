#ifndef ROOMCPP
#define ROOMCPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "room.h"

using namespace std; 

room::room() {
	contents = ' ';
	visited = false;
	intersection = false;
	rejected = false;
	accepted = false;
	filled = false;
	int x = 0;
	int y = 0	
}
bool room::getVisited(){
	return visited;
}

void room::setVisited(bool v){
	visited = v;
}

bool room::getIntersection(){
	return intersection;
}

void room::setIntersection(bool i){
	intersection = i;
}

bool room::setRejected(bool r){
	rejected = r;
}

bool room::getRejected(){
	return rejected;
}

char room::getContents(){
	return contents;
}

void room::setContents(char c){
	contents = c;
}

bool room::isWall(){
	if (contents == 'X') {
		return true;
	}
	else {
		return false;
	}
}

bool room::isOpen(){
	if (contents == ' ') {
		return true;
	}
	else {
		return false;
	}
}

bool room::isCheese(){
	if (contents == 'C') {
		return true;
	}
	else {
		return false;
	}
}

bool room::isMouse(){
	if (contents == 'M') {
		return true;
	}
	else {
		return false;
	}
}

bool room::getAccepted(){
	return accepted;
}

void room::setAccepted(bool a){
	accepted = a;
}

void room::setFilled(bool f){
	filled = f;
}

bool room::getFilled(){
	return filled;
}

void room::setCoords(int x, int y){
	xCoord = x;
	yCoord = y;
}

int room::getY(){
	return yCoord;
}

int room::getX(){
	return xCoord;
}

};
#endif
