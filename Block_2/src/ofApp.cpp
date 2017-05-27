#include "ofApp.h"
#include<stdio.h>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetBackgroundColor(255, 255, 255);
	gameClear.load("images/gameclear.png");
	

	//ボールの初期位置
	ballPosition = ofVec2f(500,600);
	//ボールの速さ
	int x = ofRandom(0, 2);
	int y = ofRandom(0, 5);
	float vx = speedx[x];
	float vy = speedy[y];
	ballSpeed = ofVec2f(vx, vy);
	//ボールの色
	ballColor = ofColor(r3, g2, b1);
	//ボールの半径
	ballRadius = 7;
}

//--------------------------------------------------------------
void ofApp::update(){
	//ボールに速さを与える
	ballPosition += ballSpeed;
	//反射
	if (ballPosition.x < 20) {
		ballPosition.x = 20;
		ballSpeed.x *= -1;
	}
	if (ballPosition.x > 1000) {
		ballPosition.x = 1000;
		ballSpeed.x *= -1;
	}
	if (ballPosition.y < 0) {
		ballPosition.y = 0;
		ballSpeed.y *= -1;
	}

	//バーで反射
	if (ballPosition.x > mouseX - barWidth / 2 && mouseX - barWidth / 2 + barWidth > ballPosition.x&&ballPosition.y> barPositionY &&ballPosition.y<barPositionY+barHeight) {
		ballPosition.y = barPositionY;
		ballSpeed.y *= -1;
	}

	float mouseX = ofGetMouseX();
	float mouseY = ofGetMouseY();
	
	
	
	//ブロック反射
	//1
	if (ballPosition.x<numx1 + width1&&ballPosition.x>numx1) {
		if (ballPosition.y == numy1 ) {
			ballPosition.y = 100;
			ballSpeed.y *= -1;
			numx1 = 0;
			numy1 = 0;
			width1 = 0;
			height1 = 0;
		}
		if ( ballPosition.y == numy1 + height1) {
			ballPosition.y = 130;
			ballSpeed.y *= -1;
			numx1 = 0;
			numy1 = 0;
			width1 = 0;
			height1 = 0;
		}
	}
	if (ballPosition.y<numy1 + height1&&ballPosition.y>numy1) {
		if (ballPosition.x == numx1) {
			ballPosition.x = 100;
			ballSpeed.x *= -1;
			numx1 = 0;
			numy1 = 0;
			width1 = 0;
			height1 = 0;
		}
		if ( ballPosition.x == numx1 + width1) {
			ballPosition.x = 250;
			ballSpeed.x *= -1;
			numx1 = 0;
			numy1 = 0;
			width1 = 0;
			height1 = 0;
		}
	}
	//2
	if (ballPosition.x<numx2 + width2&&ballPosition.x>numx2) {
		if (ballPosition.y == numy2) {
			ballPosition.y = 300;
			ballSpeed.y *= -1;
			numx2 = 0;
			numy2 = 0;
			width2 = 0;
			height2 = 0;
		}
		if (ballPosition.y == numy2 + height2) {
			ballPosition.y = 330;
			ballSpeed.y *= -1;
			numx2 = 0;
			numy2 = 0;
			width2 = 0;
			height2 = 0;
		}
	}
	if (ballPosition.y<numy2 + height2&&ballPosition.y>numy2) {
		if (ballPosition.x == numx2) {
			ballPosition.x = 100;
			ballSpeed.x *= -1;
			numx2 = 0;
			numy2 = 0;
			width2 = 0;
			height2 = 0;
		}
		if (ballPosition.x == numx2 + width2) {
			ballPosition.x = 250;
			ballSpeed.x *= -1;
			numx2 = 0;
			numy2 = 0;
			width2 = 0;
			height2 = 0;
		}
	}
	//3
	if (ballPosition.x<numx3 + width3&&ballPosition.x>numx3) {
		if (ballPosition.y == numy3) {
			ballPosition.y = 200;
			ballSpeed.y *= -1;
			numx3 = 0;
			numy3 = 0;
			width3 = 0;
			height3 = 0;
		}
		if (ballPosition.y == numy3 + height3) {
			ballPosition.y = 230;
			ballSpeed.y *= -1;
			numx3 = 0;
			numy3 = 0;
			width3 = 0;
			height3 = 0;
		}
	}
	if (ballPosition.y<numy3 + height3&&ballPosition.y>numy3) {
		if (ballPosition.x == numx3) {
			ballPosition.x = 250;
			ballSpeed.x *= -1;
			numx3 = 0;
			numy3 = 0;
			width3 = 0;
			height3 = 0;
		}
		if (ballPosition.x == numx3 + width3) {
			ballPosition.x = 400;
			ballSpeed.x *= -1;
			numx3 = 0;
			numy3 = 0;
			width3 = 0;
			height3 = 0;
		}
	}
	//4
	if (ballPosition.x<numx4 + width4&&ballPosition.x>numx4) {
		if (ballPosition.y == numy4) {
			ballPosition.y = 100;
			ballSpeed.y *= -1;
			numx4 = 0;
			numy4 = 0;
			width4 = 0;
			height4 = 0;
		}
		if (ballPosition.y == numy4 + height4) {
			ballPosition.y = 130;
			ballSpeed.y *= -1;
			numx4 = 0;
			numy4 = 0;
			width4 = 0;
			height4 = 0;
		}
	}
	if (ballPosition.y<numy4 + height4&&ballPosition.y>numy4) {
		if (ballPosition.x == numx4) {
			ballPosition.x = 400;
			ballSpeed.x *= -1;
			numx4 = 0;
			numy4 = 0;
			width4 = 0;
			height4 = 0;
		}
		if (ballPosition.x == numx4 + width4) {
			ballPosition.x = 550;
			ballSpeed.x *= -1;
			numx4 = 0;
			numy4 = 0;
			width4 = 0;
			height4 = 0;
		}
	}
	//5
	if (ballPosition.x<numx5 + width5&&ballPosition.x>numx5) {
		if (ballPosition.y == numy5) {
			ballPosition.y = 300;
			ballSpeed.y *= -1;
			numx5 = 0;
			numy5 = 0;
			width5 = 0;
			height5 = 0;
		}
		if (ballPosition.y == numy5 + height5) {
			ballPosition.y = 330;
			ballSpeed.y *= -1;
			numx5 = 0;
			numy5 = 0;
			width5 = 0;
			height5 = 0;
		}
	}
	if (ballPosition.y<numy5 + height5&&ballPosition.y>numy5) {
		if (ballPosition.x == numx5) {
			ballPosition.x = 400;
			ballSpeed.x *= -1;
			numx5 = 0;
			numy5 = 0;
			width5 = 0;
			height5 = 0;
		}
		if (ballPosition.x == numx5 + width5) {
			ballPosition.x = 550;
			ballSpeed.x *= -1;
			numx5 = 0;
			numy5 = 0;
			width5 = 0;
			height5 = 0;
		}
	}
	//6
	if (ballPosition.x<numx6 + width6&&ballPosition.x>numx6) {
		if (ballPosition.y == numy6) {
			ballPosition.y = 200;
			ballSpeed.y *= -1;
			numx6 = 0;
			numy6 = 0;
			width6 = 0;
			height6 = 0;
		}
		if (ballPosition.y == numy6 + height6) {
			ballPosition.y = 230;
			ballSpeed.y *= -1;
			numx6 = 0;
			numy6 = 0;
			width6 = 0;
			height6 = 0;
		}
	}
	if (ballPosition.y<numy6 + height6&&ballPosition.y>numy6) {
		if (ballPosition.x == numx6) {
			ballPosition.x = 550;
			ballSpeed.x *= -1;
			numx6 = 0;
			numy6 = 0;
			width6 = 0;
			height6 = 0;
		}
		if (ballPosition.x == numx6 + width1) {
			ballPosition.x = 700;
			ballSpeed.x *= -1;
			numx6 = 0;
			numy6 = 0;
			width6 = 0;
			height6 = 0;
		}
	}
	//7
	if (ballPosition.x<numx7 + width7&&ballPosition.x>numx7) {
		if (ballPosition.y == numy7) {
			ballPosition.y = 100;
			ballSpeed.y *= -1;
			numx7 = 0;
			numy7 = 0;
			width7 = 0;
			height7 = 0;
		}
		if (ballPosition.y == numy7 + height7) {
			ballPosition.y = 130;
			ballSpeed.y *= -1;
			numx7 = 0;
			numy7 = 0;
			width7 = 0;
			height7 = 0;
		}
	}
	if (ballPosition.y<numy7 + height7&&ballPosition.y>numy7) {
		if (ballPosition.x == numx7) {
			ballPosition.x = 700;
			ballSpeed.x *= -1;
			numx7 = 0;
			numy7 = 0;
			width7 = 0;
			height7 = 0;
		}
		if (ballPosition.x == numx7 + width7) {
			ballPosition.x = 850;
			ballSpeed.x *= -1;
			numx7 = 0;
			numy7 = 0;
			width7 = 0;
			height7 = 0;
		}
	}
	//8
	if (ballPosition.x<numx8 + width8&&ballPosition.x>numx8) {
		if (ballPosition.y == numy8) {
			ballPosition.y = 300;
			ballSpeed.y *= -1;
			numx8 = 0;
			numy8 = 0;
			width8 = 0;
			height8 = 0;
		}
		if (ballPosition.y == numy8 + height8) {
			ballPosition.y = 330;
			ballSpeed.y *= -1;
			numx8 = 0;
			numy8 = 0;
			width8 = 0;
			height8 = 0;
		}
	}
	if (ballPosition.y<numy8 + height8&&ballPosition.y>numy8) {
		if (ballPosition.x == numx8) {
			ballPosition.x = 700;
			ballSpeed.x *= -1;
			numx8 = 0;
			numy8 = 0;
			width8 = 0;
			height8 = 0;
		}
		if (ballPosition.x == numx8 + width8) {
			ballPosition.x = 850;
			ballSpeed.x *= -1;
			numx8 = 0;
			numy8 = 0;
			width8 = 0;
			height8 = 0;
		}
	}
	
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	//ボール
	ofSetColor(ballColor);
	ofDrawCircle(ballPosition, ballRadius);

	//バー
	ofSetColor(r1, g2, b3);
	ofDrawRectangle(mouseX - barWidth / 2, barPositionY, barWidth, barHeight);
	//ブロック
	ofSetColor(r1, g1, b1);
	ofDrawRectangle(numx1, numy1, width1, height1);
	ofSetColor(r1, g1, b1);
	ofDrawRectangle(numx2, numy2, width2, height2);
	ofSetColor(r1, g2, b2);
	ofDrawRectangle(numx3, numy3, width3, height3);
	ofSetColor(r1, g1, b2);
	ofDrawRectangle(numx4, numy4, width4, height4);
	ofSetColor(r1, g1, b2);
	ofDrawRectangle(numx5, numy5, width5, height5);
	ofSetColor(r2, g2, b2);
	ofDrawRectangle(numx6, numy6, width6, height6);
	ofSetColor(r2, g1, b1);
	ofDrawRectangle(numx7, numy7, width7, height7);
	ofSetColor(r2, g1, b1);
	ofDrawRectangle(numx8, numy8, width8, height8);
	//壁
	ofSetColor(r2, g2, b2);
	ofDrawRectangle(kabex1, kabey1, kabeWidth1, kabeHeight1);
	ofDrawRectangle(kabex2, kabey2, kabeWidth2, kabeHeight2);

	if (numx1 == 0 && numx2 == 0 && numx3 == 0 && numx4 == 0 && numx5 == 0 && numx6 == 0 && numx7 == 0 && numx8 == 0) {
		ballRadius = 0;
		ofSetColor(255, 255, 255);
		float wave = sin(ofGetElapsedTimef());
		gameClear.draw(180 + (wave * 100), 80);
	}
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
