

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
	float SetM(float M);

	float Dx;
	float Dy;

	float M;
private:
	
	int		 m_sw, m_sh;
	int		 m_point_size;
	float	*m_buffer;
	sRGB	 m_colour;
};

