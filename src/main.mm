#include "ofMain.h"
#include "testApp.h"

int main(){
    
    ofAppiPhoneWindow *window = new ofAppiPhoneWindow();
    window->enableDepthBuffer();
    window->enableRetina();
    window->enableAntiAliasing(4);
    
    ofSetupOpenGL(window, 1024, 768, OF_FULLSCREEN);
    ofRunApp(new testApp);
	
//    ofSetupOpenGL(1024,768, OF_FULLSCREEN);			// <-------- setup the GL context

//	ofRunApp(new testApp);
}
