#include "ofApp.h"
#define PARTICLE_MAX_NUM 100


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	Background.load("A_background.png");
	mode = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
	pos.x = ofGetMouseX();
	pos.y = ofGetMouseY();

	for (int i = 0; i < Particles.size(); i++) {
		Particles[i].update(mode);
	}

	MousePos[0] = MousePos[1];
	MousePos[1] = ofVec2f(ofGetMouseX(), ofGetMouseY());

	//進行方向右向き
	if (MousePos[0].x < MousePos[1].x) {
		limit.w = 0;
		limit.x = 2;
	}
	else {
		limit.w = -2;
		limit.x = 0;
	}
	//進行方向下向き
	if (MousePos[0].y < MousePos[1].y) {
		limit.y = 0;
		limit.z = 2;
	}
	else {
		limit.y = -2;
		limit.z = 0;
	}

	timeCount++;
	if (timeCount > 60*0.1) {
		Particle myParticle;
		myParticle.setup(pos, limit,mode);
		Particles.push_back(myParticle);
		timeCount = 0;
	}
	
	if (Particles.size() > PARTICLE_MAX_NUM) {
		Particles.erase(Particles.begin());
	}
	
	/*
	if (ofGetFrameRate() < 40 && Particles.size()>0) {
		Particles.erase(Particles.begin());
	}
	*/
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	

	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	Background.draw(0, 0, ofGetWidth(), ofGetHeight());
	ofDrawBitmapString(ofToString(ofGetFrameRate()) + "fps", 20, 20);

	ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofCircle(ofGetWidth() / 2, ofGetHeight() / 2, 5);
	for (int i = 0; i < Particles.size(); i++) {
		Particles[i].draw(mode);
	}

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'a') {
		mode = 1;
		for (int i = 0; i < Particles.size(); i++) {
			Particles[i].setMode(mode);
		}
	}
	else if (key == 'c') {
		Particles.clear();
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
