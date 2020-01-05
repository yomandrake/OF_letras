#pragma once

#include "ofMain.h"

class lettersToMeshOneFrame {

public:
	void setup();
	void update();
	void draw();

	int font_size;
	ofTrueTypeFont font;

	

	vector<char> charactors = {
		'C','H', 'A', 'O', 'S' ,'L', 'O', 'V', 'E' };


	int iter;
	bool drawNewFrame = true;
};
