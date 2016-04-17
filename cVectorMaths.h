
class MVector
{
public:
	MVector();
	~MVector();

	typedef struct {
		union {
			struct {
				float x, y;
			};
			float v[2];
		};
	} vec2f;

	void crossProduct(vec2f);
};
