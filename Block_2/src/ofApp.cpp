#include "ofApp.h"
#include<stdio.h>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetBackgroundColor(255, 255, 255);

	//�{�[���̏����ʒu
	ballPosition = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 5 * 4);
	//�{�[���̑���
	float vx = ofRandom(-10, 10);
	float vy = ofRandom(-10, 0);
	ballSpeed = ofVec2f(vx, vy);
	//�{�[���̐F
	ballColor = ofColor(0, 0, 0);
	//�{�[���̔��a
	ballRadius = 5;
}

//--------------------------------------------------------------
void ofApp::update(){
	//�{�[���ɑ�����^����
	ballPosition += ballSpeed;
	//����
	if (ballPosition.x <= 0) {
		ballSpeed.x *= -1;
	}
	if (ballPosition.x >= ofGetWidth()) {
		ballSpeed.x *= -1;
	}
	if (ballPosition.y <= 0) {
		ballSpeed.y *= -1;
	}

	//�o�[�Ŕ���
	if (ballPosition.x > mouseX - barWidth / 2 && mouseX - barWidth / 2 + barWidth > ballPosition.x&&ballPosition.y> ofGetHeight() / 5 * 4 + 10&&ballPosition.y<ofGetHeight() / 5 * 4 + 10+barHeight) {
		ballSpeed.y *= -1;
	}

	float mouseX = ofGetMouseX();
	float mouseY = ofGetMouseY();
}

//--------------------------------------------------------------
void ofApp::draw(){
	//�{�[��
	ofSetColor(ballColor);
	ofDrawCircle(ballPosition, ballRadius);
	//�o�[
	ofDrawRectangle(mouseX-barWidth/2, ofGetHeight() / 5 * 4+10, barWidth, barHeight);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'b') {
		
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