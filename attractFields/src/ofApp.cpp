#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cell = 5;
    ofBackground(255,255,255);
    ofEnableSmoothing;
    n_attractors = 50;
    for (int i=0; i < n_attractors; i++) {
            ofVec3f randomP;
            randomP.set( ofRandom( ofGetWidth() ) ,ofRandom( ofGetHeight() ), 0);
            gravityPcollection.assign(i,randomP);
            gravity.assign(i, ofRandom(100));
        }
    
    //points
    for (int i=0; i< ofGetWidth(); i+cell) {
        for (int j=0; j < ofGetHeight(); j+cell) {
            ofVec3f point;
            point.set(i,j);
            particleCollection.push_back(point);
        }
    }
}
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    orientorCollection.resize(particleCollection.size());
    distCollection.resize(particleCollection.size());

    for (int j=0; j < particleCollection.size(); j++) {
        ofVec3f p = (ofVec3f)particleCollection[j];
        ofVec3f target;
        for (int z=0; z < n_attractors; z++) {
            ofVec3f vi;
            vi = gravityPcollection[j] - p;
            //make it something that is from 0 to 1
            vi.normalize();
            float disti = p.distance(gravityPcollection[j]);
            vi.scale(gravity[j]/disti);
            target = target + vi;
        }
        target.normalize();
        target = target*5;
        
        orientorCollection[j] = target;
//        distCollection[j] = minDist;

    }
    
    oreientorSortedCollection.resize(particleCollection.size());
    
    for (int j=0; j<particleCollection.size(); j++) {
        ofVec3f temp;
        temp.set(orientorCollection[j]);
        oreientorSortedCollection[j] = (temp.normalize()*3);
        
    }
        //drawing the points
        for (int t=0; t< particleCollection.size(); t++) {
            ofVec3f points;
            points.set(particleCollection[t]);
            ofNoFill();
            ofFill();
            ofSetColor(250, 128, 114, 255);
            ofDrawEllipse(points.x, points.y, 1, 1);
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
