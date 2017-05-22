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
		float barWidth = 100;
		float barHeight = 20;

		//ブロック１
		float numx1 = 100;
		float numy1 = 100;
		float height1 = 25;
		float width1 = 150;
		//ブロック２
		float numx2 = 100;
		float numy2 = 300;
		float height2 = 25;
		float width2 = 150;
		//ブロック3
		float numx3 = 250;
		float numy3 = 200;
		float height3 = 25;
		float width3 = 150;
		//ブロック4
		float numx4 = 400;
		float numy4 = 100;
		float height4 = 25;
		float width4 = 150;
		//ブロック5
		float numx5 = 400;
		float numy5 = 300;
		float height5 = 25;
		float width5 = 150;
		//ブロック6
		float numx6 = 550;
		float numy6 = 200;
		float height6 = 25;
		float width6 = 150;
		//ブロック7
		float numx7 = 700;
		float numy7 = 100;
		float height7 = 25;
		float width7 = 150;
		//ブロック8
		float numx8 = 700;
		float numy8 = 300;
		float height8 = 25;
		float width8 = 150;
		
};
