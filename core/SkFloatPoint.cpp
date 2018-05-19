#include "SkFloatPoint.h"
#include "SkFloatVector.h"
#include <cmath>
#include <intrin.h>

namespace skylina {
namespace app {

SkFloatPoint::SkFloatPoint(float x, float y, float z)
	: x(x), y(y), z(z)
{}

SkFloatPoint::SkFloatPoint(const SkFloatVector& vec)
	:x(vec.x),y(vec.y),z(vec.z)
{}

float SkFloatPoint::distanceTo(const SkFloatPoint& other) const
{
	__m128 _re = _mm_sub_ps(_mm_load_ps(&this->x), _mm_load_ps(&other.x));
	_re = _mm_mul_ps(_re, _re);
	_CRT_ALIGN(16) float reTemp[4];
	_mm_store_ps(&reTemp[0], _re);
	return std::sqrtf(reTemp[0] + reTemp[1] + reTemp[2]);
}

SkFloatPoint SkFloatPoint::operator+(const SkFloatPoint& other) const
{
	__m128 _re = _mm_add_ps(_mm_load_ps(&this->x), _mm_load_ps(&other.x));
	_CRT_ALIGN(16) float reTemp[4];
	_mm_store_ps(&reTemp[0], _re);
	return SkFloatPoint(reTemp[0], reTemp[1], reTemp[2]);
}

SkFloatPoint SkFloatPoint::operator-(const SkFloatPoint& other) const
{
	__m128 _re = _mm_sub_ps(_mm_load_ps(&this->x), _mm_load_ps(&other.x));
	_CRT_ALIGN(16) float reTemp[4];
	_mm_store_ps(&reTemp[0], _re);
	return SkFloatPoint(reTemp[0], reTemp[1], reTemp[2]);
}

SkFloatPoint& SkFloatPoint::operator+=(const SkFloatPoint& other)
{
	__m128 _re = _mm_add_ps(_mm_load_ps(&this->x), _mm_load_ps(&other.x));
	_mm_store_ps(&this->x, _re);
	this->w = 1.0;
	return *this;
}

SkFloatPoint& SkFloatPoint::operator-=(const SkFloatPoint& other)
{
	__m128 _re = _mm_sub_ps(_mm_load_ps(&this->x), _mm_load_ps(&other.x));
	_mm_store_ps(&this->x, _re);
	this->w = 1.0;
	return *this;
}

}//namespace app
}//namespace skylina