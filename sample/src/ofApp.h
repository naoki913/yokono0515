#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "ofxOpenNI.h"

class ofApp : public ofBaseApp{
private:
    ofxOpenNI kinect;
    
    


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

       
    int numHands;
		vector<Particle> Particles;
		ofImage Background;
		ofVec2f MousePos[2];
		ofVec2f pos;
    ofVec2f center;
    ofVec2f handPos[4];
		ofVec4f limit;
		int mode;
		int timeCount = 0;
   
};
