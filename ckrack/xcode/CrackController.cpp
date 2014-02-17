#include "Crack.h"
#include "CrackController.h"
#include "cinder/Rand.h"

using std::list;
using namespace ci;


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

void CrackController::continueCrack(){
    Crack latest = mCracks.back();
    mCracks.push_back(Crack::continueCrack(latest));
}

void CrackController::addCrack(Vec2f loc){
    if (isEmpty())
        mCracks.push_back(Crack::Crack(loc, Rand::randVec2f()));
    else
        CrackController::continueCrack();
                          
}

void CrackController::addCrack(){
    if (isEmpty())
        addRandomCrack();
    else {
        CrackController::continueCrack();
    }
}

bool CrackController::isEmpty(){
    return mCracks.empty();
}
    
