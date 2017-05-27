#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofVec2f ballPosition;
		ofVec2f ballSpeed;

		ofColor ballColor;

		float ballRadius;
		float barWidth = 1000;
		float barHeight = 20;
		float barPositionY = 700;

		//カラフル
		float r1 = ofRandom(0, 255) , g1 = ofRandom(0, 255) , b1 = ofRandom(0, 255);
		float r2 = ofRandom(0, 255) , g2 = ofRandom(0, 255) , b2 = ofRandom(0, 255);
		float r3 = ofRandom(0, 255) , g3 = ofRandom(0, 255) , b3 = ofRandom(0, 255);
		
		//ブロック１
		float numx1 = 100;
		float numy1 = 100;
		float height1 = 30;
		float width1 = 150;
		//ブロック２
		float numx2 = 100;
		float numy2 = 300;
		float height2 = 30;
		float width2 = 150;
		//ブロック3
		float numx3 = 250;
		float numy3 = 200;
		float height3 = 30;
		float width3 = 150;
		//ブロック4
		float numx4 = 400;
		float numy4 = 100;
		float height4 = 30;
		float width4 = 150;
		//ブロック5
		float numx5 = 400;
		float numy5 = 300;
		float height5 = 30;
		float width5 = 150;
		//ブロック6
		float numx6 = 550;
		float numy6 = 200;
		float height6 = 30;
		float width6 = 150;
		//ブロック7
		float numx7 = 700;
		float numy7 = 100;
		float height7 = 30;
		float width7 = 150;
		//ブロック8
		float numx8 = 700;
		float numy8 = 300;
		float height8 = 30;
		float width8 = 150;
		
		//ボールの速さ、配列
		int speedy[3] = { -2,-5,-10 };
		int speedx[6] = { -10, -5,-2,2,5,10 };

		//壁１
		float kabex1 = 0;
		float kabey1 = 0;
		float kabeWidth1 = 20;
		float kabeHeight1 = 800;
		//壁２
		float kabex2 = 1000;
		float kabey2 = 0;
		float kabeWidth2 = 30;
		float kabeHeight2 = 800;

		ofImage gameClear;
};
