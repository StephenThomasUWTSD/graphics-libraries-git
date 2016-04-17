#include <vector>

class cRenderClass
{
public:
	
	cRenderClass(const int, const int);
	~cRenderClass();

	void create(int argc, _TCHAR* argv[]);
	void loop();

	void clear();
	void render();
	void setColour(float, float, float);
	void setPointSize(int);
	void drawPixel(int, int);
	void line(int,int,int,int);
	void bresenhamsLine(int, int, int, int);
	void DDALine(float, float, float, float);
	void midPoint(int Radius, int xC, int yC);
	void draw(int, int, int, int);
	//float SetM(float M);
	//void l3vec(Vector &v1);
	void pointCloud(int);
	

	
	float Dx;
	float Dy;
	float M;
	int runOnce;
	struct Point 
	{
		GLfloat x, y;
	};

	std::vector<cRenderClass::Point> points;
	int cRenderClass::orientation(Point p, Point q, Point r);
	void jarvisMarchHull(std::vector<Point> points, int numPoints);
	void jarvisMarchHull2(std::vector<Point> points);
private:
	sRGB	m_colour;
	int		 m_sw, m_sh;
	int		 m_point_size;
	float	*m_buffer;
};

//nvm