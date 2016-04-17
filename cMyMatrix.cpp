
#include "stdafx.h" //throws up horrendous amounts of errors

#define _USE_MATH_DEFINES
#include <math.h>
cMyMatrix::cMyMatrix()
{
	identity();
}
//#define pi 3.14....
//cMyMatrix MyMatrix;
//identity matrix
void cMyMatrix::identity()
{
	m[0] = 1.0f;
	m[1] = 0.0f;
	m[2] = 0.0f;
	m[3] = 0.0f;
	m[4] = 0.0f;
	m[5] = 1.0f;
	m[6] = 0.0f;
	m[7] = 0.0f;
	m[8] = 0.0f;
	m[9] = 0.0f;
	m[10] = 1.0f;
	m[11] = 0.0f;
	m[12] = 0.0f;
	m[13] = 0.0f;
	m[14] = 0.0f;
	m[15] = 1.0f;
	
}

//uniform scaling
void cMyMatrix::uScale(float value)
{
	(m[0]  * value);
	(m[5]  * value);
	(m[10] * value);

	(m[15] = 1);

}

//translation matrix
void cMyMatrix::translation()
{
	//create a translation matrix
	float t[4];
	t[0] = (1 * v[0]) + (m[3] * m[15]);
	t[1] = (1 * v[1]) + (m[7] * m[15]);
	t[2] = (1 * v[2]) + (m[11] * m[15]);
	t[3] = 1;

}

//none uniform scaling
void cMyMatrix::nuScaleX(float value)
{
	m[0] = m[0] * value;
}

void cMyMatrix::nuScaleY(float value)
{
	m[5] = m[5] * value;
}

void cMyMatrix::nuScaleZ(float value)
{
	m[10] = m[10] * value;
}


//NOT HOW THE FUNCTION WILL BE I KNOW THIS IS TERRIBLE JUST RUNNING THROUGH STUFF IN MY HEAD
void cMyMatrix::nonUScale(float x, float y, float z)
{
	if (x > 0.0)
	{

		m[0] = m[0] * x;
	}
	if (y>0.0)
	{
		m[5] = m[5] * y;
	}
	if (z>0.0)
	{
	m[10] = m[10] * z;
	}
}

//can make rotation one function
//rotation matrix
void cMyMatrix::rotationX(float value)
{

}

void cMyMatrix::rotationY(float value)
{

}

void cMyMatrix::rotationZ(float value)
{

}

//normalize a matrix
void cMyMatrix::normalize()
{
	m[0] / m[15];
	m[1] / m[15];
	m[2] / m[15];
	m[3] / m[15];
	m[4] / m[15];
	m[5] / m[15];
	m[6] / m[15];
	m[7] / m[15];
	m[8] / m[15];
	m[9] / m[15];
	m[10] / m[15];
	m[11] / m[15];
	m[12] / m[15];
	m[13] / m[15];
	m[14] / m[15];
	m[15] = 1;
}
//step through matrix i havent used
void cMyMatrix::stepThroughMatrix(float value)
{

	for (int i = 0; i<16; i++)
	{

	}
}

//only needs one matrix
//matrix multiplication
void cMyMatrix::multiplyMatrix()
{
	float m3[16];//define locally
	m3[0] = (m[0] * m2[0]) + (m[1] * m2[4]) + (m[2] * m2[8]) + (m[3] * m2[12]);        m3[1] = (m[0] * m2[1]) + (m[1] * m2[5]) + (m[2] * m2[9]) + (m[3] * m2[13]);        m3[2] = (m[0] * m2[2]) + (m[1] * m2[6]) + (m[2] * m2[10]) + (m[3] * m2[14]);        m3[3] = (m[0] * m2[3]) + (m[1] * m2[7]) + (m[2] * m2[11]) + (m[3] * m2[15]);
	m3[4] = (m[4] * m2[0]) + (m[5] * m2[4]) + (m[6] * m2[8]) + (m[7] * m2[12]);        m3[5] = (m[4] * m2[1]) + (m[5] * m2[5]) + (m[6] * m2[9]) + (m[7] * m2[13]);        m3[6] = (m[4] * m2[2]) + (m[5] * m2[6]) + (m[6] * m2[10]) + (m[7] * m2[14]);        m3[7] = (m[4] * m2[3]) + (m[5] * m2[7]) + (m[6] * m2[11]) + (m[7] * m2[15]);
	m3[8] = (m[8] * m2[0]) + (m[9] * m2[4]) + (m[10] * m2[8]) + (m[11] * m2[12]);      m3[9] = (m[8] * m2[1]) + (m[9] * m2[5]) + (m[10] * m2[9]) + (m[11] * m2[13]);      m3[10] = (m[8] * m2[2]) + (m[9] * m2[6]) + (m[10] * m2[10]) + (m[11] * m2[14]);     m3[11] = (m[8] * m2[3]) + (m[9] * m2[7]) + (m[10] * m2[11]) + (m[11] * m2[15]);
	m3[12] = (m[12] * m2[0]) + (m[13] * m2[4]) + (m[14] * m2[8]) + (m[15] * m2[12]);    m3[13] = (m[12] * m2[1]) + (m[13] * m2[5]) + (m[14] * m2[9]) + (m[15] * m2[13]);   m3[14] = (m[12] * m2[2]) + (m[13] * m2[6]) + (m[14] * m2[10]) + (m[15] * m2[14]);   m3[15] = (m[12] * m2[3]) + (m[13] * m2[7]) + (m[14] * m2[11]) + (m[15] * m2[15]);
	//return m3;//return here

}

//multiply matrix by a vector
void cMyMatrix::matrixByVector()
{
	float sum[2];
	
	sum[0] = mv[0] * v[0] + mv[1] * v[1] + mv[2] * v[2] + mv[3] * v[3];
	sum[1] = mv[4] * v[0] + mv[5] * v[1] + mv[6] * v[2] + mv[7] * v[3];
	
}

//degrees to radians
float cMyMatrix::degToRad(float degrees)
{
	return degrees / 180.0f * M_PI;
}

//radians to degrees
float cMyMatrix::radToDeg(float radians)
{
	return radians * 180.0f / M_PI;
}
//destructor
cMyMatrix::~cMyMatrix()
{
	
}
//http://www.tutorialspoint.com/cplusplus/cpp_passing_arrays_to_functions.htm
//http://stackoverflow.com/questions/3473438/return-array-in-a-function
