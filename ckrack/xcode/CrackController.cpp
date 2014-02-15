#include "Crack.h"
#include "CrackController.h"

using std::list;

CrackController::CrackController() {
}



CrackController::CrackController(int resolution){

}

void CrackController::update(){
    for( list<Crack>::iterator c = mCracks.begin(); c != mCracks.end(); ++c ){
		c->update( );
	}

}
void CrackController::draw(){
    for( list<Crack>::iterator c = mCracks.begin(); c != mCracks.end(); ++c ){
		c->draw( );
	}
}

void CrackController::addRandomCrack(){
    mCracks.push_back(Crack::randomCrack());
}

    
