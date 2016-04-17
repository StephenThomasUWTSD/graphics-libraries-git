#include "stdafx.h"
using namespace std;

//constructor seems to build now oki lets try the convex hull out
Vector::Vector(float myx, float myy, float myz)
{ 
	x= myx;
	y= myy;
	z= myz;
}

void Vector::Scale(float s)
{
	x= s*x;
	y= s*y;
	z= s*z;
}

void Vector::Normalize(void)
{
	float length = sqrt(x*x+y*y+z*z);
	x= x/length;
	y= y/length;
	z= z/length;
}

void Vector::Add(Vector & v1, Vector & v2)
{
	v1.x= v2.x + v1.x;
	v1.y= v2.y + v1.y;
	v1.z = v2.z + v1.z;
}
void Vector::Add(Vector & v1)
{
	x= x + v1.x;
	y= y + v1.y;
	z = z + v1.z;
}
void Vector::Print(){
	cout<<"("<<x<<","<<y<<","<<z<<")";

}

void Vector::Set(float myx, float myy, float myz){
   x=myx;
   y=myy;
   z=myz;
}
Vector operator -(const Vector & v2, const Vector & v1)
{
	return Vector(v2.x - v1.x, v2.y - v1.y, v2.z - v1.z);
}
Vector operator +(const Vector & v2, const Vector & v1)
{
	return Vector(v2.x + v1.x, v2.y + v1.y, v2.z + v1.z);
}
//
Vector& Vector::operator =(const Vector& rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	return *this;
}

float Vector::Dot(Vector &v1)
	{
		 return (x * v1.x)+ (y * v1.y) + (z * v1.z);
	}

float Vector::Cross2f(const Vector & v1, const Vector & v2)
{
	return (v1.y*v2.z - v1.z*v2.y), (v1.z*v2.x - v1.x*v2.z), (v1.x*v2.y - v1.y*v2.x);
}

Vector operator *(const Vector & a, const Vector & b)
{
	return Vector((a.y*b.z - a.z*b.y), (a.z*b.x - a.x*b.z), (a.x*b.y - a.y*b.x));
}



Ray::Ray():dir(0,0,0),Origin(0,0,0)
{
}


void Ray::SetOrigin(const Vector & p)
{
	Origin.x= p.x;
	Origin.y= p.y;
	Origin.z= p.z;
}
void Ray::SetDirection(const Vector & d)
{	
	dir.x= d.x;
	dir.y= d.y;
	dir.z= d.z;
}
float Ray::LinePointDistanceSqd(const Vector & p)
{
  Vector w = p-Origin; //p-origin
  float vsq = dir.Dot(dir); //direction squared
  float wsq = w.Dot(w); //w squared
  float proj = w.Dot(dir); //w.v
  return wsq-proj*proj/vsq; //the line point closest distance
}

 