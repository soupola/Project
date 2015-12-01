#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	img1.loadImage("lab.jpg");
	img2.loadImage("lab.jpg");
	img1 = resize(img1);
	img1 = binerisation(img1);
	img2 = img1;
	img2 = dilatation(img2);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	img1.draw(0,0);
	img2.draw(img1.width,0);
}

ofImage ofApp::resize(ofImage i)
{
	ofImage save = i;
	if(i.height > ofGetWindowHeight() || i.width > ofGetWindowWidth())
	{
		int hRatio = save.height / ofGetWindowHeight();
		int wRatio =save.width / ofGetWindowWidth();
		cout << "ratio hauteur : " << hRatio  << endl;
		cout << "ratio largeur : " << wRatio << endl;

		i.resize(save.height/(hRatio+1),save.width/(wRatio+1));
	}
	i.update();
	return i;
}

ofImage ofApp::binerisation(ofImage i)
{
	i.setImageType(OF_IMAGE_GRAYSCALE);
	for (int y=0; y<i.height; y++) 
	{
		for (int x=0; x<i.width; x++) 
		{
			if(i.getColor(x,y).getBrightness()>127)
			{
				i.setColor(x,y,255);
			}
			else
			{
				i.setColor(x,y,0);
			}
		}
	}
	i.update();
	return i;
}

ofImage ofApp::dilatation(ofImage i){
	ofImage imagereturn;
	for (int y=0; y<i.height; y++) 
	{
		for (int x=0; x<i.width; x++) 
		{
			if(x !=0 && y!=0 && x!= i.width-1 && y!= i.height-1)
			{
				if(i.getColor(x,y).getBrightness() < 127)
				{
					imagereturn.setColor(x,y,0);
					imagereturn.setColor(x-1,y,0);
					imagereturn.setColor(x+1,y,0);
					imagereturn.setColor(x,y-1,0);
					imagereturn.setColor(x,y+1,0);
				}
			}
		}
	}
	imagereturn.update();
	return imagereturn;
}

void ofApp::process(){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
