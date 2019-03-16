// The sample model.  You should build a file
// very similar to this for when you make your model.
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>

#include "modelerglobals.h"

// To make a SampleModel, we inherit off of ModelerView
class SampleModel : public ModelerView
{
public:
	SampleModel(int x, int y, int w, int h, char *label)
		: ModelerView(x, y, w, h, label) { }

	virtual void draw();
private:
	void drawHead();
	void drawNeck();
	void drawUpperBody();
	void drawLeftUpperArm();
	void drawRightUpperArm();
	void drawLeftLowerArm();
	void drawRightLowerArm();
	void drawLeftUpperLeg();
	void drawRightUpperLeg();
	void drawLeftLowerLeg();
	void drawRightLowerLeg();
	void drawFace();
	
};

// We need to make a creator function, mostly because of
// nasty API stuff that we'd rather stay away from.
ModelerView* createSampleModel(int x, int y, int w, int h, char *label)
{
	return new SampleModel(x, y, w, h, label);
}

// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out SampleModel
void SampleModel::draw()
{
	// This call takes care of a lot of the nasty projection 
	// matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
	ModelerView::draw();

	// draw the floor
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_RED);
	glPushMatrix();
	glTranslated(-5, -3.2, -5);
	drawBox(10, 0.01f, 10);
	glPopMatrix();

	// draw the sample model
	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_GREEN);
	glPushMatrix();
	glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
	glRotated(VAL(ROTATE), 1.0, 0.0, 0.0);
	
		drawHead();
		drawFace();
		drawNeck();
		drawUpperBody();
		drawLeftUpperArm();
		drawRightUpperArm();
		drawLeftLowerArm();
		drawRightLowerArm();
		drawLeftUpperLeg();
		drawRightUpperLeg();
		drawLeftLowerLeg();
		drawRightLowerLeg();

	glPopMatrix();
	/*setAmbientColor(.1f,.1f,.1f);
	setDiffuseColor(COLOR_GREEN);
	glPushMatrix();
	glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
	glPushMatrix();
	glTranslated(-1.5, 0, -2);
	glScaled(3, 1, 4);
	drawBox(1,1,1);
	glPopMatrix();
	// draw cannon
	glPushMatrix();
	glRotated(VAL(ROTATE), 0.0, 1.0, 0.0);
	glRotated(-90, 1.0, 0.0, 0.0);
	drawCylinder(VAL(HEIGHT), 0.1, 0.1);
	glTranslated(0.0, 0.0, VAL(HEIGHT));
	drawCylinder(1, 1.0, 0.9);
	glTranslated(0.0, 0.0, 0.5);
	glRotated(90, 1.0, 0.0, 0.0);
	drawCylinder(4, 0.1, 0.2);
	glPopMatrix();
	glPopMatrix();//1.1(UPEER TORSO)+0.8(HEAD(*/
}
void SampleModel::drawHead() {
	setDiffuseColor(COLOR_GREEN);
	glPushMatrix();
	glRotated(VAL(HEADXROT), 1.0, 0.0, 0.0);
	glRotated(VAL(HEADYROT), 0.0, 1.0, 0.0);
	glTranslated(0.0, HEAD_RADIUS + 1.6 + VAL(HEIGHT), 0.0);
	drawSphere(0.9);
	glPopMatrix();

}

void SampleModel::drawFace() {
	//EYES
	setDiffuseColor(COLOR_BLACK);
	glPushMatrix();
	glRotated(VAL(HEADXROT), 1.0, 0.0, 0.0);
	glRotated(VAL(HEADYROT), 0.0, 1.0, 0.0);
	glTranslated(0.5, HEAD_RADIUS +1.8 +VAL(HEIGHT), 0.7);
	drawSphere(0.1);
	glRotated(VAL(HEADXROT), 1.0, 0.0, 0.0);
	glRotated(VAL(HEADYROT), 0.0, 1.0, 0.0);
	glTranslated(-1,0, 0);
	drawSphere(0.1);
	glPopMatrix();
	//MOUTH
	setDiffuseColor(COLOR_RED);
	glPushMatrix();
	glRotated(VAL(HEADXROT), 1.0, 0.0, 0.0);
	glRotated(VAL(HEADYROT), 0.0, 1.0, 0.0);
	glTranslated(-0.25, 1.8 + VAL(HEIGHT), 0.7);
	glRotated(20, 1.0, 0.0, 0.0);
	glTranslated(0, 0, -0.4);
	drawBox(0.5,0.5,0.5);
	glPopMatrix();

}

void SampleModel::drawNeck() {
	setDiffuseColor(COLOR_GREEN);
	glPushMatrix();
	glRotated(VAL(HEADYROT), 0.0, 1.0, 0.0);
	glTranslated(0.0, 2.1, 0.0);
	glScaled(0.4, VAL(HEIGHT)*4, 0.4);
	glTranslated(-0.5, -0.9, -0.5);
	drawBox(1, 1, 1);

	glPopMatrix();

}
void SampleModel::drawUpperBody() {
	setDiffuseColor(COLOR_BLUE);
	glPushMatrix();
	glTranslated(-0.5 - 0.1, 0, -0.5 );
	glScaled(1.25, 1.7, 1.0);
	drawBox(1, 1, 1);

	glPopMatrix();

}

void SampleModel::drawLeftUpperArm() {
	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glTranslated(-LEFT_UPPER_ARM1 / 2 + 0.8, 0.4, -LEFT_UPPER_ARM3 / 2);
	glScaled(0.3, 1.2, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();

}
void SampleModel::drawRightUpperArm() {
	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glTranslated(-RIGHT_UPPER_ARM1 / 2 - 0.8, 0.4, -RIGHT_UPPER_ARM3 / 2);
	glScaled(0.3, 1.2, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();

}

void SampleModel::drawLeftLowerArm() {
	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glTranslated(-LEFT_UPPER_ARM1 / 2 + 0.8, 0.4 -1.3, -LEFT_UPPER_ARM3 / 2);
	glScaled(0.3, 1.2, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();

}

void SampleModel::drawRightLowerArm() {
	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glTranslated(-RIGHT_UPPER_ARM1 / 2 - 0.8, 0.4 -1.3, -RIGHT_UPPER_ARM3 / 2);
	glScaled(0.3, 1.2, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();

}
void SampleModel::drawLeftUpperLeg() {
	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glRotated(VAL(LLEGROT), 1.0, 0.0, 0.0);
	glTranslated(-LEFT_UPPER_LEG1 / 2 - 0.35, -1, -LEFT_UPPER_ARM3 / 2);
	glScaled(0.45, 1.8, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();

}
void SampleModel::drawRightUpperLeg() {
	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glRotated(VAL(RLEGROT), 1.0, 0.0, 0.0);
	glTranslated(-RIGHT_UPPER_LEG1 / 2 + 0.2, -1, -RIGHT_UPPER_LEG3 / 2);
	glScaled(0.45, 1.8, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();

}
void SampleModel::drawLeftLowerLeg() {
	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glRotated(VAL(LLEGROT), 1.0, 0.0, 0.0);
	glTranslated(-LEFT_UPPER_LEG1 / 2 - 0.35 , -1.5-1.6, -LEFT_UPPER_LEG3 / 2);
	glScaled(0.45, 2.0 , 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();

}
void SampleModel::drawRightLowerLeg() {
	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glRotated(VAL(RLEGROT), 1.0, 0.0, 0.0);
	glTranslated(-RIGHT_UPPER_LEG1 / 2 + 0.2, -1.5-1.6, -RIGHT_UPPER_LEG3 / 2);
	glScaled(0.45, 2.0, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();

}
int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
	ModelerControl controls[NUMCONTROLS];
	controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
	controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
	controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);
	controls[HEIGHT] = ModelerControl("Height", 0.4, 0.8, 0.1f, 0.4);
	controls[ROTATE] = ModelerControl("Rotate", -135, 135, 1, 0);
	controls[HEADXROT] = ModelerControl("Head X Rotation", -27, 27, 1, 0);
	controls[HEADYROT] = ModelerControl("Head Y Rotation", -25, 25, 1, 0);
	controls[RLEGROT] = ModelerControl("Leg Rotation", -65, 16, 1, 0);
	controls[LLEGROT] = ModelerControl("Leg Rotation", -65, 16, 1, 0);

	ModelerApplication::Instance()->Init(&createSampleModel, controls, NUMCONTROLS);
	return ModelerApplication::Instance()->Run();
}