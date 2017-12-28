#include "ofApp.h"
#define PARTICLE_MAX_NUM 300


//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	Background.load("A_background.png");
	mode = 0;
    
    //  setup ofxOpenNI
    kinect.setup();
    kinect.setRegister(true);
    kinect.setMirror(true);
    kinect.addImageGenerator();     //  required for RGB image
    kinect.addDepthGenerator();     //  required for depth image
    kinect.addHandsGenerator();      //  required for hand tracking
    kinect.addAllHandFocusGestures();
    kinect.setMaxNumHands(4);       //  max num of skeleton to track
    //  start kinect
    kinect.start();
    
    handPos[0]=ofVec2f(0,0);
    handPos[1]=ofVec2f(0,ofGetHeight());
    handPos[2]=ofVec2f(ofGetWidth(),0);
    handPos[3]=ofVec2f(ofGetWidth(),ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();
    numHands=kinect.getNumTrackedHands();
    if (kinect.getNumTrackedHands() > 0) {
        
        for(int i=0;i<numHands;i++){
            
            ofxOpenNIHand & hand = kinect.getTrackedHand(i);
            ofPoint & p= hand.getPosition();
            
            handPos[i]=p;
        }
    }

    
    for(int i=0;i<numHands;i++){

   handPos[i].x=handPos[i].x/640*ofGetWidth();
   handPos[i].y=handPos[i].y/480*ofGetHeight();
    
	for (int i = 0; i < Particles.size(); i++) {
		Particles[i].update(mode);
	}

	MousePos[0] = MousePos[1];
	//MousePos[1] = ofVec2f(ofGetMouseX(), ofGetMouseY());
    MousePos[1]=ofVec2f(handPos[i].x,handPos[i].y);
    
	//êiçsï˚å¸âEå¸Ç´
	if (MousePos[0].x < MousePos[1].x) {
		limit.w = 0;
		limit.x = 2;
	}
	else {
		limit.w = -2;
		limit.x = 0;
	}
	//êiçsï˚å¸â∫å¸Ç´
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
        if(mode==1){
            limit.w=center.x;
            limit.x=center.y;
        }
		myParticle.setup(handPos[i], limit,mode);
      
		Particles.push_back(myParticle);
		timeCount = 0;
	}
	
	if (Particles.size() > PARTICLE_MAX_NUM) {
		Particles.erase(Particles.begin());
	}
    }
	/*
	if (ofGetFrameRate() < 40 && Particles.size()>0) {
		Particles.erase(Particles.begin());
	}
	*/
    if(mode==0){
    for(int i=0;i<numHands;i++){
        for(int j=i+1;j<numHands;j++){
    if(abs(handPos[i].x-handPos[j].x)<200&&abs(handPos[i].y-handPos[j].y)<200){
        mode = 1;
        Particles.clear();
        center=ofVec2f((handPos[i].x+handPos[j].x)/2,(handPos[i].y+handPos[j].y)/2);
       /* for (int i = 0; i < Particles.size(); i++) {
            Particles[i].setMode(mode,center);
        }*/
    }
    }
    }
    }
  
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	//Background.draw(0, 0, ofGetWidth(), ofGetHeight());
	ofDrawBitmapString(ofToString(ofGetFrameRate()) + "fps", 20, 20);

    
    kinect.drawDepth(0, 0, ofGetWidth(), ofGetHeight());   //  depth image (in color)
    
    
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	//ofCircle(ofGetWidth() / 2, ofGetHeight() / 2, 5);
	for (int i = 0; i < Particles.size(); i++) {
		Particles[i].draw(mode);
	}
   
    for(int i=0;i<numHands;i++){
        ofDrawCircle(handPos[i].x , handPos[i].y, 10);
    }
    
    //kinect.drawDepth(0, 0, ofGetWidth(), ofGetHeight());   //  depth image (in color)

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	/*if (key == 'a') {
		mode = 1;
		for (int i = 0; i < Particles.size(); i++) {
			Particles[i].setMode(mode);
		}
	}*/
	if (key == 'c') {
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
