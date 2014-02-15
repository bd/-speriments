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
    
    ci::Vec2f mStart;
    ci::Vec2f mEnd;
};