#include "nearPoints_letters.h"	

//--------------------------------------------------------------
void nearPoints_letters::setup() {

	ofBackground(255,0);
	ofSetLineWidth(2);

	this->mesh.setMode(OF_PRIMITIVE_LINES);

	ofFbo fbo;
	fbo.allocate(ofGetWidth()*1.5, ofGetHeight()*1.5);
	fbo.begin();
	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.6);
	ofClear(0);
	ofSetColor(0);

	ofTrueTypeFont font2;
	font2.loadFont("arial.ttf", 400, true, true, true);

	font2.drawString("JK", font2.stringWidth("JK") * -0.5, font2.stringHeight("JK") * -0.05);
	font2.drawString("YI", font2.stringWidth("YI") * -0.5, font2.stringHeight("YI") * 1.05);

	fbo.end();

	auto span = 15;

	ofPixels pixels;
	fbo.readToPixels(pixels);
	for (int x = 0; x < fbo.getWidth(); x += span) {

		for (int y = 0; y < fbo.getHeight(); y += span) {

			ofColor color = pixels.getColor(x, y);
			if (color != ofColor(0, 0)) {

				this->mesh.addVertex(glm::vec3(x, y, 0));
			}
		}
	}

	ofSetColor(39);
}

//--------------------------------------------------------------
void nearPoints_letters::update() {

	ofSeedRandom(39);

	this->draw_mesh = this->mesh;

	for (auto& vertex : this->draw_mesh.getVertices()) {

		vertex.x += ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, -5, 5);
		vertex.y += ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005), 0, 1, -5, 5);
	}

	for (int i = 0; i < this->draw_mesh.getVertices().size(); i++) {

		auto location = this->draw_mesh.getVertex(i);
		vector<int> near_index_list;
		for (int k = 0; k < this->draw_mesh.getVertices().size(); k++) {

			if (i == k) { continue; }

			auto other = this->draw_mesh.getVertex(k);
			auto distance = glm::distance(location, other);
			if (distance < 16.5) {

				this->draw_mesh.addIndex(i);
				this->draw_mesh.addIndex(k);
			}
		}
	}
}

//--------------------------------------------------------------
void nearPoints_letters::draw() {

	this->draw_mesh.draw();

	for (int i = 0; i < this->draw_mesh.getVertices().size(); i++) {

		ofDrawCircle(this->draw_mesh.getVertex(i), 4);
	}
}

