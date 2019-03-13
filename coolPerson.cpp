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
	void drawLeftArm();
	void drawRightArm();
	void drawLeftUpperLeg();
	void drawRightUpperLeg();
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
	glTranslated(-5, -3, -5);
	drawBox(10, 0.01f, 10);
	glPopMatrix();

	// draw the sample model
	drawHead();
	drawNeck();
	drawUpperBody();
	drawLeftArm();
	drawRightArm();
	drawLeftUpperLeg();
	drawRightUpperLeg();
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
	glTranslated(0.0, HEAD_RADIUS + 2.0 , 0.0);
	drawSphere(0.9);
	glPopMatrix();

}

void SampleModel::drawNeck() {
	setDiffuseColor(COLOR_GREEN);
	glPushMatrix();
	glTranslated(0.0, 2.0 +0.1, 0.0);
	glScaled(0.4, 0.4, 0.4);
	glTranslated(-0.5, -0.9, -0.5);
	drawBox(1, 1, 1);

	glPopMatrix();

}
void SampleModel::drawUpperBody() {
	setDiffuseColor(COLOR_BLUE);
	glPushMatrix();
	glTranslated(-0.5-0.1, 0, -0.5);
	glScaled(1.3, 1.7, 1.0);
	drawBox(1,1,1);

	glPopMatrix();

}

void SampleModel::drawLeftArm() {
	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glTranslated(-LEFT_UPPER_ARM1/2+0.8 , 0, -LEFT_UPPER_ARM3 / 2);
	glScaled(0.3, 1.5, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();

}
void SampleModel::drawRightArm() {
	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glTranslated(-RIGHT_UPPER_ARM1 / 2 - 0.8, 0, -RIGHT_UPPER_ARM3 / 2);
	glScaled(0.3, 1.5, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();

}
void SampleModel::drawLeftUpperLeg() {
	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glTranslated(-LEFT_UPPER_LEG1 / 2 -0.35, -1, -LEFT_UPPER_ARM3 / 2);
	glScaled(0.5, 1.8, 0.5);
	drawBox(1, 1, 1);
	glPopMatrix();

}
void SampleModel::drawRightUpperLeg() {
	setDiffuseColor(COLOR_WHITE);
	glPushMatrix();
	glTranslated(-RIGHT_UPPER_LEG1 / 2 +0.35, -1, -RIGHT_UPPER_ARM3 / 2);
	glScaled(0.5, 1.8, 0.5);
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
	controls[HEIGHT] = ModelerControl("Height", 1, 2.5, 0.1f, 1);
	controls[ROTATE] = ModelerControl("Rotate", -135, 135, 1, 0);

	ModelerApplication::Instance()->Init(&createSampleModel, controls, NUMCONTROLS);
	return ModelerApplication::Instance()->Run();
}
