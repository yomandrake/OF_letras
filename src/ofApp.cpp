#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(2);
	ofSetWindowTitle("openframeworks");
	ofEnableDepthTest();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	ofBackground(255,0);
	ofSetColor(39);
	ofSetLineWidth(5);
	ofEnableDepthTest();

	this->font_size = 50;
	this->font.loadFont("arial.ttf", this->font_size, true, true, true);

	//msje.setup();
	msje2.setup();
	//sign.setup();
	//ofSetBackgroundAuto(false);

	
	///TO TEST WITH SPRING REST  CONTROLLER IN LOCAL HOST
	playerData = ofLoadURL(urlRequest);
	ofLogNotice() << playerData.status;
	ofLogNotice() << playerData.data;


	//springRest.get(urlRequest);///Work in progress using ofURLFileLoader

}

//--------------------------------------------------------------
void ofApp::update(){
	//msje.update();
	msje2.update();
	//sign.update();


}

//--------------------------------------------------------------
void ofApp::draw(){

	cam.begin();
	//msje.draw();
	msje2.draw();
	//sign.draw();
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//Guardar imagen con tecla 's'
	if (key == 's') {

		//ofSaveFrame();
		ofSaveScreen("Firma_JKSI_"+ofGetTimestampString()+".png");
	}
	if (key == 'f') {

		ofToggleFullscreen();
		
	}

	if (key == 'z') {

		msje2.drawNewFrame = true;

	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
