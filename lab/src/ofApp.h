#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include <GLFW/glfw3.h>

class ofApp : public ofBaseApp{


	public:
		void setup();
		void update();
		void draw();
		void loadImage(ofImage i);
		void start();



		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofImage image;
		ofxButton startB;
		ofxPanel gui;
		bool drawImage;
		bool secondWindow;


		
};
