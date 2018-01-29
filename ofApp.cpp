#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
	
	ofEnableLighting();
	this->light.enable();
}

//--------------------------------------------------------------
void ofApp::update() { }

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	this->light.setPosition(this->cam.getPosition() * 2.f);

	float assembly_size = ofGetWidth() > ofGetHeight() ? ofGetWidth() : ofGetHeight();
	int box_size = 300 * ofNoise(ofGetFrameNum() * 0.005);
	ofSetColor(255, 0, 0);
	for (int x = -assembly_size / 2; x <= assembly_size / 2; x += box_size) {

		for (int y = -assembly_size / 2; y <= assembly_size / 2; y += box_size) {

			for (int z = -assembly_size / 2; z <= assembly_size / 2; z += box_size) {

				float noise_value = ofNoise(x * 0.005, y * 0.005, z * 0.005, ofGetFrameNum() * 0.0005);
				if (noise_value < 0.5) {

					ofSetColor(255, 0, 0);
					ofFill();
					ofDrawBox(ofPoint(x, y, z), box_size, box_size, box_size);
				}
				else {

				}
				
			}
		}
	}

	this->cam.end();
}

//========================================================================
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}