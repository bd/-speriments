#pragma once
#include "cinder/Vector.h"

#include <vector>

class Crack{
public:
    Crack();
    Crack(ci::Vec2f, ci::Vec2f);
  
    void update();
    void draw();
  
    static Crack randomCrack();
    static Crack continueCrack(Crack);
    static bool out_of_bounds(ci::Vec2f);
    
    ci::Vec2f mStart;
    ci::Vec2f mEnd;
};