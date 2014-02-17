//  A break, a fracture
//  Crack.cpp
//  ckrack
//
//  Created by Benjamin Dean on 2/14/14.
//
//

#include "Crack.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"

#define MAX_LEN 20

using namespace ci;

Crack::Crack(Vec2f start, Vec2f end){

    mStart = start;
    mEnd = end;
}

Crack::Crack(){

}

void Crack::update(){

}

void Crack::draw(){
    Vec3f p1( mStart, 0.0f );
    Vec3f p2( mEnd, 0.0f );
    gl::color(255.0, 255.0, 255.0);
    gl::drawVector(p1, p2);
}

Crack Crack::randomCrack(){
    float sx = Rand::randFloat( app::getWindowWidth() );
    float sy = Rand::randFloat( app::getWindowHeight() );
    Vec2f start = Vec2f(sx, sy);
    float ex = Rand::randFloat(sx + Rand::randFloat(MAX_LEN));
    float ey = Rand::randFloat(sy + Rand::randFloat(MAX_LEN));
    Vec2f end = Vec2f(ex, ey);
    return Crack(start, end);
    
   
}

Crack Crack::continueCrack(Crack crack){
//    float ex = Rand::randFloat(app::getWindowWidth());
//    float ey = Rand::randFloat(app::getWindowHeight());
    
    float ex = Rand::randFloat(MAX_LEN);
    float ey = Rand::randFloat(MAX_LEN);
    if (Rand::randBool())
        ex *= -1;
    if (Rand::randBool())
        ey *= -1;
    
    Vec2f end = Vec2f(ex, ey);
    return Crack(crack.mEnd, crack.mEnd + end);
}
