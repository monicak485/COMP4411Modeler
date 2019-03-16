#ifndef _MODELER_GLOBALS_H
#define _MODELER_GLOBALS_H

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

// This is a list of the controls for the SampleModel
// We'll use these constants to access the values 
// of the controls from the user interface.
enum SampleModelControls
{ 
	XPOS, YPOS, ZPOS, HEIGHT, ROTATE, HEADXROT, HEADYROT, RLEGROT, LLEGROT, NUMCONTROLS
};

// Colors
#define COLOR_RED		1.0f, 0.0f, 0.0f
#define COLOR_GREEN		0.0f, 1.0f, 0.0f
#define COLOR_BLUE		0.0f, 0.0f, 1.0f
#define COLOR_WHITE		1.0f, 1.0f, 1.0f
#define COLOR_BLACK		0.0f, 0.0f, 0.0f


// Model Size
#define HEAD_RADIUS 0.9
#define UPPER_BODY_SIZE1 5
#define UPPER_BODY_SIZE2 3
#define UPPER_BODY_SIZE3 2
#define LEFT_UPPER_ARM1 0.3
#define LEFT_UPPER_ARM2 1.5
#define LEFT_UPPER_ARM3 0.5
#define RIGHT_UPPER_ARM1 0.3
#define RIGHT_UPPER_ARM2 1.5
#define RIGHT_UPPER_ARM3 0.5
#define LEFT_UPPER_LEG1 0.3
#define LEFT_UPPER_LEG2 1.5
#define LEFT_UPPER_LEG3 0.5
#define RIGHT_UPPER_LEG1 0.3
#define RIGHT_UPPER_LEG2 1.5
#define RIGHT_UPPER_LEG3 0.5

// We'll be getting the instance of the application a lot; 
// might as well have it as a macro.
#define VAL(x) (ModelerApplication::Instance()->GetControlValue(x))

#endif