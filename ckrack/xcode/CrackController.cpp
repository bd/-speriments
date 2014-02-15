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

void CrackController::addCrack(){
    if (isEmpty())
        addRandomCrack();
    else {
        Crack latest = mCracks.back();
//        mCracks.push_back(latest);
        mCracks.push_back(Crack::continueCrack(latest));
    }
}

bool CrackController::isEmpty(){
    return mCracks.empty();
}
    
