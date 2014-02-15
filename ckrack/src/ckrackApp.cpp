#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "CrackController.h"

using namespace ci;
using namespace ci::app;
using namespace std;

/*#####CONSTANTS#####
  settings related to the app itself, event dispatch, interactivity, etc.
*/
class ckrackApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    CrackController controller;
};

void ckrackApp::setup()
{

    
    controller = CrackController();
}

void ckrackApp::mouseDown( MouseEvent event )
{
//    simply add a crack to the list
    controller.addRandomCrack();
}

void ckrackApp::update()
{
    controller.update();
}

void ckrackApp::draw()
{
    // clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    controller.draw();
    
}

CINDER_APP_NATIVE( ckrackApp, RendererGl )
