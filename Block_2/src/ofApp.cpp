#include "ofApp.h"
#include<stdio.h>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetBackgroundColor(255, 255, 255);
	

	//ボールの初期位置
	ballPosition = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 5 * 4);
	//ボールの速さ
	float vx = ofRandom(-10, 10);
	float vy = ofRandom(-10, -8);
	ballSpeed = ofVec2f(vx, vy);
	//ボールの色
	ballColor = ofColor(0, 0, 0);
	//ボールの半径
	ballRadius = 5;
}

//--------------------------------------------------------------
void ofApp::update(){
	//ボールに速さを与える
	ballPosition += ballSpeed;
	//反射
	if (ballPosition.x <= 0) {
		ballSpeed.x *= -1;
	}
	if (ballPosition.x >= ofGetWidth()) {
		ballSpeed.x *= -1;
	}
	if (ballPosition.y <= 0) {
		ballSpeed.y *= -1;
	}

	//バーで反射
	if (ballPosition.x > mouseX - barWidth / 2 && mouseX - barWidth / 2 + barWidth > ballPosition.x&&ballPosition.y> ofGetHeight() / 5 * 4 + 10&&ballPosition.y<ofGetHeight() / 5 * 4 + 10+barHeight) {
		ballSpeed.y *= -1;
	}

	float mouseX = ofGetMouseX();
	float mouseY = ofGetMouseY();
	
	
	
	/*if (ballPosition.x<num1+num1&&ballPosition.x>num1&&ballPosition.y<num1+num1&&ballPosition.y>num1) {
		ballSpeed.y *= -1;
		num1 = 0;
	}  */  

	//1
	if (ballPosition.x<numx1 + width1&&ballPosition.x>numx1&&ballPosition.y<numy1 + height1&&ballPosition.y>numy1) {
		ballSpeed.y *= -1;
		numx1 = 0;
		numy1 = 0;
		width1 = 0;
		height1 = 0;
	}
	//2
	if (ballPosition.x<numx2 + width2&&ballPosition.x>numx2&&ballPosition.y<numy2 + height2&&ballPosition.y>numy2) {
		ballSpeed.y *= -1;
		numx2 = 0;
		numy2 = 0;
		width2 = 0;
		height2 = 0;
	}
	//3
	if (ballPosition.x<numx3 + width3&&ballPosition.x>numx3&&ballPosition.y<numy3 + height3&&ballPosition.y>numy3) {
		ballSpeed.y *= -1;
		numx3 = 0;
		numy3 = 0;
		width3 = 0;
		height3 = 0;
	}
	//4
	if (ballPosition.x<numx4 + width4&&ballPosition.x>numx4&&ballPosition.y<numy4 + height4&&ballPosition.y>numy4) {
		ballSpeed.y *= -1;
		numx4 = 0;
		numy4 = 0;
		width4 = 0;
		height4 = 0;
	}
	//5
	if (ballPosition.x<numx5 + width5&&ballPosition.x>numx5&&ballPosition.y<numy5 + height5&&ballPosition.y>numy5) {
		ballSpeed.y *= -1;
		numx5 = 0;
		numy5 = 0;
		width5 = 0;
		height5 = 0;
	}
	//6
	if (ballPosition.x<numx6 + width6&&ballPosition.x>numx6&&ballPosition.y<numy6 + height6&&ballPosition.y>numy6) {
		ballSpeed.y *= -1;
		numx6 = 0;
		numy6 = 0;
		width6 = 0;
		height6 = 0;
	}
	//7
	if (ballPosition.x<numx7 + width7&&ballPosition.x>numx7&&ballPosition.y<numy7 + height7&&ballPosition.y>numy7) {
		ballSpeed.y *= -1;
		numx7 = 0;
		numy7 = 0;
		width7 = 0;
		height7 = 0;
	}
	//8
	if (ballPosition.x<numx8 + width8&&ballPosition.x>numx8&&ballPosition.y<numy8 + height8&&ballPosition.y>numy8) {
		ballSpeed.y *= -1;
		numx8 = 0;
		numy8 = 0;
		width8 = 0;
		height8 = 0;
	}
	
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	//ボール
	ofSetColor(ballColor);
	ofDrawCircle(ballPosition, ballRadius);

	//バー
	ofDrawRectangle(mouseX - barWidth / 2, ofGetHeight() / 5 * 4 + 10, barWidth, barHeight);
	//ブロック
	//ofDrawRectangle(num1, num1, num1, num1);
	ofDrawRectangle(numx1, numy1, width1, height1);
	ofDrawRectangle(numx2, numy2, width2, height2);
	ofDrawRectangle(numx3, numy3, width3, height3);
	ofDrawRectangle(numx4, numy4, width4, height4);
	ofDrawRectangle(numx5, numy5, width5, height5);
	ofDrawRectangle(numx6, numy6, width6, height6);
	ofDrawRectangle(numx7, numy7, width7, height7);
	ofDrawRectangle(numx8, numy8, width8, height8);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
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
