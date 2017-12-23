#include "Particle.h"

void Particle::setup(ofVec2f _pos,ofVec4f _limit,int _mode)
{
	if (_mode == 0) {
		pos = _pos;
		float vx = ofRandom(_limit.w, _limit.x);
		float vy = ofRandom(_limit.y, _limit.z);
		pos.set(pos);
		vel.set(vx, vy);
		img.load("A_particle.png");
		snow.load("A_snow.png");

		angle = 0;
	}
	else if (_mode == 1) {
		pos = _pos;
		center.x = ofGetWidth() / 2;
		center.y = ofGetHeight() / 2;
		radious.x = 200;
		//radious.y = radious.x / 2;
		gap = pos - center;
		degree = getDegree(gap.x, gap.y);

		count = 0;
		
		distance = sqrt(gap.x*gap.x + gap.y*gap.y);
		angle = 0;
		img.load("A_particle.png");
		snow.load("A_snow.png");
	}
}



void Particle::update(int _mode) {
	if (_mode == 0) {
		pos = pos + vel;
		angle += 3;
	}
	else if (_mode == 1) {
		count += 2;
		if (count == 360)count = 0;
		radian = count*PI / 180;

		pos.x = distance*cos(radian);
		pos.y = distance / 2 * sin(radian);

		if (distance < radious.x)distance++;

		if (distance > radious.x)distance--;

		angle++;
	}
}

void Particle::draw(int _mode) {
	if (_mode == 0) {
		float posx = pos.x - 16;
		float posy = pos.y - 16;

		img.draw(posx - 16 + 10 * sin(100 * ofGetElapsedTimef()), posy - 16 + 10 * cos(100 * ofGetElapsedTimef()));


		ofPushMatrix();
		ofTranslate(posx, posy);
		ofRotate(angle);
		snow.draw(-snow.getWidth() / 2, -snow.getHeight() / 2);
		ofPopMatrix();
	}
	else if (_mode == 1) {
		ofPushMatrix();
		ofTranslate(center);
		ofRotate(degree);

		


		float posx = pos.x - 16;
		float posy = pos.y - 16;


		img.draw(posx - 16 + 10 * sin(50* ofGetElapsedTimef()), posy - 16 + 10 * cos(50* ofGetElapsedTimef()));


		ofPushMatrix();
		ofTranslate(posx, posy);
		ofRotate(angle);
		snow.draw(-snow.getWidth() / 2, -snow.getHeight() / 2);
		ofPopMatrix();

		ofPopMatrix();
	}
}

float Particle::getDegree(float x, float y) {
	float radian = atan2(y, x);
	float degree = radian * 180 / PI;

	return degree;
}

void Particle::setMode(int _mode) {
	ofVec4f Null = { 0,0,0,0 };
	setup(pos,Null , _mode);
}