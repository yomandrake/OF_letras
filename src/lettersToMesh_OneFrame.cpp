
#include "lettersToMeshOneFrame.h"

void lettersToMeshOneFrame::setup() {

	this->font_size = 50;
	this->font.loadFont("arial.ttf", this->font_size, true, true, true);

}

//--------------------------------------------------------------
void lettersToMeshOneFrame::update(){



}

//--------------------------------------------------------------
void lettersToMeshOneFrame::draw(){

	if (this->drawNewFrame) {
		//this->drawNewFrame = false;
		iter = iter + 1;


		int span = 80;


		int i = 0;

		for (int x = -160; x <= 160; x += span) {

			for (int y = -160; y <= 160; y += span) {

				auto location = glm::vec3(x, y, 0);

				//int charactor_index = ofRandom(charactors.size());
				++iter;
				int charactor_index = iter % charactors.size();

				auto path = this->font.getCharacterAsPoints(charactors[charactor_index], true, false);

				auto outline = path.getOutline();

				ofPushMatrix();
				ofTranslate(location);

				ofFill();
				ofSetColor(39);
				ofBeginShape();

				for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

					if (outline_index != 0) { ofNextContour(true); }

					auto vertices = outline[outline_index].getVertices();
					for (int vertices_index = 0; vertices_index < vertices.size(); vertices_index++) {

						auto location = glm::vec2(this->font_size - vertices[vertices_index].x, vertices[vertices_index].y + this->font.stringHeight(string{ charactors[charactor_index] }) * 0.5);
						ofVertex(location);
					}
				}

				ofEndShape(true);

				ofNoFill();
				ofSetColor(239);
				ofBeginShape();

				for (int outline_index = 0; outline_index < outline.size(); outline_index++) {

					if (outline_index != 0) { ofNextContour(true); }

					auto vertices = outline[outline_index].getVertices();
					for (int vertices_index = 0; vertices_index < vertices.size(); vertices_index++) {

						auto location = glm::vec2(this->font_size - vertices[vertices_index].x, vertices[vertices_index].y + this->font.stringHeight(string{ charactors[charactor_index] }) * 0.5);
						ofVertex(location);
					}
				}

				ofEndShape(true);

				ofPopMatrix();
			}
		}




	}
	


}

