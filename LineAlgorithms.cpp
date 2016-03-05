#include "stdafx.h"

cRenderClass* renderer;
cRenderClass* graphics;
void line(int x1, int y1, int x2, int y2)
{
	
	graphics->drawPixel(x1, y1);
	graphics->setColour(1.0f, 1.0f, 1.0f);

	//renderer = new cRenderClass;
	graphics = new cRenderClass(640, 480);
	
	graphics->drawPixel(5, 5);
	for (int x = 0; x<640; x++)graphics->drawPixel(x, 15);

	//line(10, 20,15,25);
}