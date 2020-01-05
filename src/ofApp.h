#pragma once

#include "ofMain.h"
#include "lettersToMesh.h"
#include "lettersToMeshOneFrame.h"
#include "nearPoints_letters.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofEasyCam cam;
	int font_size;
	ofTrueTypeFont font;

	lettersToMesh msje;
	lettersToMeshOneFrame msje2;
	nearPoints_letters sign;

	ofURLFileLoader springRest;
	string urlRequest = { "http://localhost::8080/players" };

	ofHttpResponse playerData;

};