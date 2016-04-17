// cRenderClass.cpp
// 
//////////////////////////////////////////////////////////////////////////////////////////
// includes 
//////////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <vector>

//////////////////////////////////////////////////////////////////////////////////////////
// Declarations 
//////////////////////////////////////////////////////////////////////////////////////////
cRenderClass graphics( SCREEN_WIDTH, SCREEN_HEIGHT );
Vector vec3f;
//cRenderClass graphics = new cRenderClass(SCREEN_WIDTH, SCREEN_HEIGHT);
//////////////////////////////////////////////////////////////////////////////////////////
// cRenderClass() - constructor 
//////////////////////////////////////////////////////////////////////////////////////////
cRenderClass::cRenderClass(const int w, const int h)
{
	//cRenderClass::points;
	m_sw = w;
	m_sh = h;
	
	int total_count = w*h*3;

	m_buffer = new float[total_count];

	for( int i=0; i<total_count; i++ )
	{
		m_buffer[i] = 0;
	}

	m_point_size = 1;

	runOnce = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
// cRenderClass() - destructor 
//////////////////////////////////////////////////////////////////////////////////////////
cRenderClass::~cRenderClass()
{
}

//////////////////////////////////////////////////////////////////////////////////////////
// loop() - enters game loop
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::loop()
{
	glutMainLoop();
}

//////////////////////////////////////////////////////////////////////////////////////////
// initialize glut stuff
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::create(int argc, _TCHAR* argv[])
{
	// initialise the glut library
	glutInit(&argc, argv);

	// set up the initial display mode
	// need both double buffering and z-buffering
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// set the initial window position
	glutInitWindowPosition(100, 100);

	// set the initial window size
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	// create and name the window
	glutCreateWindow("Wow!");

	// reshape callback for current window
	glutReshapeFunc(winReshapeFunc);

	// set display callback for current window
	glutDisplayFunc(renderScene);	

	// set up the global idle callback
	glutIdleFunc(update);
}

//////////////////////////////////////////////////////////////////////////////////////////
// clear() - clears out the render buffer 
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::clear()
{
	memset( m_buffer, 0, sizeof(float)*m_sw*m_sh*3 );
}

//////////////////////////////////////////////////////////////////////////////////////////
// setPointSize() - set the pixel size 
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::setPointSize(int size)
{
	m_point_size = size;
}

//////////////////////////////////////////////////////////////////////////////////////////
// drawPixel() -  
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::drawPixel(int x, int y)
{
	int start, end;

	start = -(m_point_size/2);
	end	= (int)((m_point_size/2.0f) + 0.5);

	for( int i=start; i<end; i++ )
	{
		for( int j=start; j<end; j++ )
		{
			if( (x+j < 0) || (x+j >= m_sw) )
				continue;

			if( (y+i < 0) || (y+i >= m_sh) )
				continue;

			m_buffer[(((y+i)*m_sw+(x+j))*3) + 0] = m_colour.r;
			m_buffer[(((y+i)*m_sw+(x+j))*3) + 1] = m_colour.g;
			m_buffer[(((y+i)*m_sw+(x+j))*3) + 2] = m_colour.b;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////
// render() - renders this buffer to screen 
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::render()
{
	// clear the back buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDrawPixels(m_sw, m_sh, GL_RGB, GL_FLOAT, m_buffer);

	// swap the buffers of the current window
	glutSwapBuffers();

	// clear out the buffer
	clear();
}

//////////////////////////////////////////////////////////////////////////////////////////
// setColour() - sets the current colour 
//////////////////////////////////////////////////////////////////////////////////////////
void cRenderClass::setColour(float r, float g, float b)
{
	m_colour.r = r;
	m_colour.g = g;
	m_colour.b = b;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
// winReshapeFunc() - gets called initially and whenever the window get resized
// resizing has been locked
//////////////////////////////////////////////////////////////////////////////////////////
void winReshapeFunc(GLint w, GLint h)
{
	// specify current matrix
	glMatrixMode(GL_PROJECTION);

	// load an identity matrix
	glLoadIdentity();	

	// create a projection matrix... i.e. 2D projection onto xy plane
	glOrtho( -SCREEN_WIDTH, SCREEN_WIDTH, -SCREEN_HEIGHT, SCREEN_HEIGHT, -100, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// set up the viewport
	glViewport
	(
		0,				// lower left x position
		0,				// lower left y position 
		(GLsizei) SCREEN_WIDTH,	// viewport width
		(GLsizei) SCREEN_HEIGHT	// viewport height
	);
}
////////////////////////////
///////////////////////////////LINE ALGORITHMS//////////////
///////////////////////////////////////////////////////
void cRenderClass::line(int x1, int y1, int x2, int y2)
{
	
	for (int x = x1; x < x2; x++)
	{
		graphics.drawPixel(x, 15);
	}
}

void cRenderClass::bresenhamsLine(int x1, int y1, int x2, int y2) // takes 4 we have 2
{

	int stepx;
	if (x1 < x2) 
	{ 
		stepx = 1; 
	}
	else
	{ 
		stepx = -1; 
	}

	//int sy = y1 < y2 ? 1 : -1;
	int stepy;
	if (y1 < y2) 
	{ 
		stepy = 1; 
	}
	else 
	{ 
		stepy = -1; 
	}
	
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);

	int pos;
	if (dx > dy) 
	{ 
		pos = dx / 2; 
	}
	else 
	{ 
		pos = -dy / 2; 
	}

	while (true) 
	{
		graphics.drawPixel(x1, y1);
		if (x1 == x2 && y1 == y2) break;
		if (pos > -dx) 
		{ 
			pos -= dy; x1 += stepx; 
		}
		if (pos < dy) 
		{ 
			pos += dx; y1 += stepy; 
		}
	}
}


void cRenderClass::DDALine(float x1, float y1, float x2, float y2)
{
	
	if (x1 > x2)
	{
		graphics.DDALine(x2, y2, x1, y1);
		return;
	}
	
	
	float x = x1;
	float y = y1;

	float slope = (y2 - y1) / (x2 - x1);

	if (slope <= 1)
	{
		for (x = x1; x < x2; x++)
		{
			y += slope;
			graphics.drawPixel(x, y); 
		}
	}else
	{
		for (y = y1; y < y2; y++)
		{
			x += 1 / slope;
			graphics.drawPixel(x, y);
		}
		
	}

}


void cRenderClass::midPoint(int Radius, int xC, int yC)
{
	int x = Radius;
	int y = 0;
	int decisionOver2 = 1 - x;   // Decision criterion divided by 2 evaluated at x=r, y=0

	while (y <= x)
	{
		graphics.drawPixel(x + xC, y + yC); // Octant 1
		graphics.drawPixel(y + xC, x + yC); // Octant 2
		graphics.drawPixel(-x + xC, y + yC); // Octant 4
		graphics.drawPixel(-y + xC, x + yC); // Octant 3
		graphics.drawPixel(-x + xC, -y + yC); // Octant 5
		graphics.drawPixel(-y + xC, -x + yC); // Octant 6
		graphics.drawPixel(x + xC, -y + yC); // Octant 7
		graphics.drawPixel(y + xC, -x + yC); // Octant 8
		y++;
		if (decisionOver2 <= 0)
		{
			decisionOver2 += 2 * y + 1;   // Change in decision criterion for y -> y+1
		}
		else
		{
			x--;
			decisionOver2 += 2 * (y - x) + 1;   // Change for y -> y+1, x -> x-1
		}
	}
}


void cRenderClass::pointCloud(int numPoints)
{
	//make function run once
	if (graphics.runOnce == 0) {
		// Fill points vector with random coords
		srand(static_cast <unsigned> (time(0)));
		for (int i = 0; i < numPoints; i++)
		{
			graphics.points.push_back({
				static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / SCREEN_WIDTH)),
				static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / SCREEN_WIDTH))
			});
		}
		graphics.runOnce = 1;
	}

	//scatter random  points 
	for (int i = 0; i < numPoints; i++)
	{
		graphics.drawPixel(points[i].x, points[i].y);
	}
}



//std::vector<cRenderClass::Point> *points;
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colineara
// 1 --> Clockwise
// 2 --> Counterclockwise
int cRenderClass::orientation(Point p, Point q, Point r)
{
	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;  // colinear
	return (val > 0) ? 1 : 2; // clock or counterclock wise
}

void cRenderClass::jarvisMarchHull2(std::vector<Point> points)
{
	// not to my knowledge but it's worth a look
	int numPoints = points.size();
	std::vector<int> next;
	// There must be at least 3 points
	if (numPoints < 3)
	{
		return;
	}
	// Initialize Result
	for (int i = 0; i < numPoints; i++)
	{
		next.at(i) = -1;
	}

	// Find the leftmost point
	int l = 0;
	for (int i = 1; i < numPoints; i++)
	{
		if (points[i].x < points[l].x)
		{
			l = i;
		}
	}

	// Start from leftmost point, keep moving counterclockwise
	// until reach the start point again
	int p = l, q;
	do
	{
		// Search for a point 'q' such that orientation(p, i, q) is
		// counterclockwise for all points 'i'
		q = (p + 1) % numPoints;
		for (int i = 0; i < numPoints; i++)
		{
			if (orientation(points[p], points[i], points[q]) == 2)
			{
				q = i;
			}
		}

		next.at(p) = q; // Add q to result as a next point of p
		p = q; // Set p as q for next iteration
	} while (p != l);

	// Print Result
	for (int i = 0; i < numPoints-1; i++)
	{
		if (next[i] != -1)
		{
		
			graphics.bresenhamsLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
		}
	}
}

void cRenderClass::jarvisMarchHull(std::vector<Point> points, int numPoints)
{
	std::vector<Point> hull;

	// Find the leftmost point
	int l = 0;
	for (int i = 2; i < numPoints; i++)
	{
		if (points[i].x < points[l].x)
		{
			l = i;
		}
	}
	// Start from leftmost point, keep moving counterclockwise
	// until reach the start point again.  This loop runs O(h)
	// times where h is number of points in result or output.
	int p = l, q = 0;
	do
	{
		// Add current point to result
		hull.push_back(points[p]);

		// Search for a point 'q' such that orientation(p, x,
		// q) is counterclockwise for all points 'x'. The idea
		// is to keep track of last visited most counterclock-
		// wise point in q. If any point 'i' is more counterclock-
		// wise than q, then update q.
		if (p != q)
		{
			q = p + 1;
		}
		
		for (int i = 2; i < numPoints; i++)
		{
			// If i is more counterclockwise than current q, then
			// update q
			if (orientation(points[p], points[i], points[q]) == 2)
			{
				q = i;
			}
			
		}
		

		// Now q is the most counterclockwise with respect to p
		// Set p as q for next iteration, so that q is added to
		// result 'hull'
		p = q;

	} while (p != l);  // While we don't come to first point

	// Print Result
	
	for (int i = 0; i < hull.size()-1; i++)
	{
		graphics.bresenhamsLine(hull[i].x, hull[i].y, hull[i+1].x, hull[i+1].y);
	}
	 
	
	graphics.bresenhamsLine(hull[0].x, hull[0].y, hull[hull.size()-1].x, hull[hull.size()-1].y);
	
	/*template <cRenderClass::Point, std::vector<Alloc = allocator<*points> > class vector;
	cRenderClass::Point std::vector<>::allocator; numPoints *points
	std::vector<float>::iterator pos;
	*points = std::min_element<cRenderClass::Point*>( *points,*points+numPoints );// std::end(points)
		std::vector<cRenderClass::Point> grahamshull;
		*/
}
