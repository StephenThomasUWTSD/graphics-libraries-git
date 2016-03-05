#include "stdafx.h"
#pragma once
class cMyMatrix
{
public:
	cMyMatrix(){}
	~cMyMatrix(){}
	//identity matrix
	void identity();

	//translation matrix
	void translation();

	//uniform scaling
	void uScale(float value);

	//none uniform scaling
	void nuScaleX(float value);
	void nuScaleY(float value);
	void nuScaleZ(float value);

	//rotation matrix
	void rotationX(float value);
	void rotationY(float value);
	void rotationZ(float value);

	//normalize values
	void normalize();

	//Multiply two matrices
	void multiplyMatrix();

	//multiply matrix by vector
	void matrixByVector();

	//stepThroughMatrix
	void stepThroughMatrix(float value);

	//degrees to rads
	float degToRad(float degrees);

	//radians to degrees
	float radToDeg(float radians);
private:
	//matrix times vector 2x4 matrix
	float mv[8];
	//vector
	float v[4];
	//4x4 matrix
	float m[16];
	//second 4x4 matrix
	float m2[16];
	//float m3[16];
};

