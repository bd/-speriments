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
    float ex = Rand::randFloat( app::getWindowWidth() );
    float ey = Rand::randFloat( app::getWindowHeight() );
    Vec2f end = Vec2f(ex, ey);
    return Crack(start, end);
    
   
}
