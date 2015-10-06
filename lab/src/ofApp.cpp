#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){




}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	image.draw(0,0);
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
void ofApp::dragEvent(ofDragInfo di){ 
	
	if(di.files.size() >0)
	{
		string path = di.files[0];
		string pathExt = path.substr (path.length()-4,path.length());
		cout << path << endl;
		cout << pathExt << endl;


		if(pathExt == ".jpg" || pathExt == ".png" || pathExt == ".jpeg" || pathExt ==".gif")
		{
			cout << "Image" << endl;
			image.loadImage(path);
			loadImage(image);
			
		}

		else
		{
			cout << "Le fichier n'est pas une image! " << endl;

		}

	}
}

		
void ofApp::loadImage(ofImage i)
{
	unsigned char *data = image.getPixels();
	// premier affichage 
	// calcul du nombre de px 
	int components = image.bpp / 8;
	
	for (int y=0; y<image.height; y++) 
	{
		for (int x=0; x<image.width; x++) 
		{

			//Read pixel (x,y) color components
			int index = components * (x + image.width * y);
			int red = data[ index ];
			int green = data[ index + 1 ];
			int blue = data[ index + 2 ];


			
			//Set red 
			data[ index ] = red ;
			//Set green 
			data[ index + 1 ] = green;
			//Set blue 
			data[ index + 2 ] = blue;

		}
	}
	if(image.height > ofGetWindowHeight() || image.width > ofGetWindowWidth())
	{
		int hRatio = image.height / ofGetWindowHeight();
		int wRatio =image.width / ofGetWindowWidth();
		cout << "ratio hauteur : " << hRatio  << endl;
		cout << "ratio largeur : " << wRatio << endl;

		image.resize(image.height/(hRatio+1),image.width/(wRatio+1));

	}
	image.update();

	

	
}
