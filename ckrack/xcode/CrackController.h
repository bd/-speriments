#pragma once
#include "cinder/Vector.h"
#include "cinder/Color.h"
#include "Crack.h"

#include <list>

class CrackController {
public:
    CrackController();
    CrackController(int resolution);
    void update();
    void draw();
    void addRandomCrack();
    std::list<Crack> mCracks;
    
    int mXRes; int mYRes;
    
};