#include "SkFloatVector.h"
#include "SkFloatPoint.h"
#include <cmath>
#include <intrin.h>

namespace skylina {
namespace app {

SkFloatVector::SkFloatVector(float x, float y, float z)
	:x(x), y(y), z(z)
{}

SkFloatVector::SkFloatVector(const SkFloatPoint& pnt)
	:x(pnt.x),y(pnt.y),z(pnt.z)
{}

float SkFloatVector::length() const
{
	_CRT_ALIGN(16)float dTemp[4]{ this->x,this->y,this->z,0.f };
	__m128 _re = _mm_mul_ps(_mm_load_ps(dTemp), _mm_load_ps(dTemp));
	_CRT_ALIGN(16) float reTemp[4];
	_mm_store_ps(&reTemp[0], _re);
	return std::sqrtf(reTemp[0] + reTemp[1] + reTemp[2]);
}

void SkFloatVector::normalize()
{
	_CRT_ALIGN(16)float dTemp[4]{ this->x,this->y,this->z,0.f };
	float len = this->length();
	_CRT_ALIGN(16)float lenTemp[4]{ len,len,len,0.f };
	__m128 _re = _mm_div_ps(_mm_load_ps(dTemp), _mm_load_ps(lenTemp));
	_CRT_ALIGN(16) float reTemp[4];
	_mm_store_ps(&reTemp[0], _re);
	this->x = reTemp[0];
	this->y = reTemp[1];
	this->z = reTemp[2];
}

SkFloatVector SkFloatVector::normal() const
{
	_CRT_ALIGN(16)float dTemp[4]{ this->x,this->y,this->z,0.f };
	float len = this->length();
	_CRT_ALIGN(16)float lenTemp[4]{ len,len,len,0.f };
	__m128 _re = _mm_div_ps(_mm_load_ps(dTemp), _mm_load_ps(lenTemp));
	_CRT_ALIGN(16) float reTemp[4];
	_mm_store_ps(&reTemp[0], _re);
	return SkFloatVector(reTemp[0], reTemp[1], reTemp[2]);
}

SkFloatVector SkFloatVector::operator+(const SkFloatVector& other) const
{
	_CRT_ALIGN(16)float dTemp[4]{ this->x,this->y,this->z,0.f };
	_CRT_ALIGN(16)float oTemp[4]{ other.x,other.y,other.z,0.f };
	__m128 _re = _mm_add_ps(_mm_load_ps(dTemp), _mm_load_ps(oTemp));
	_CRT_ALIGN(16) float reTemp[4];
	_mm_store_ps(&reTemp[0], _re);
	return SkFloatVector(reTemp[0], reTemp[1], reTemp[2]);
}

SkFloatVector SkFloatVector::operator-(const SkFloatVector& other) const
{
	_CRT_ALIGN(16)float dTemp[4]{ this->x,this->y,this->z,0.f };
	_CRT_ALIGN(16)float oTemp[4]{ other.x,other.y,other.z,0.f };
	__m128 _re = _mm_sub_ps(_mm_load_ps(dTemp), _mm_load_ps(oTemp));
	_CRT_ALIGN(16) float reTemp[4];
	_mm_store_ps(&reTemp[0], _re);
	return SkFloatVector(reTemp[0], reTemp[1], reTemp[2]);
}

SkFloatVector& SkFloatVector::operator+=(const SkFloatVector& other)
{
	_CRT_ALIGN(16)float dTemp[4]{ this->x,this->y,this->z,0.f };
	_CRT_ALIGN(16)float oTemp[4]{ other.x,other.y,other.z,0.f };
	__m128 _re = _mm_add_ps(_mm_load_ps(dTemp), _mm_load_ps(oTemp));
	_CRT_ALIGN(16) float reTemp[4];
	_mm_store_ps(&reTemp[0], _re);
	this->x = reTemp[0];
	this->y = reTemp[1];
	this->z = reTemp[2];
	return *this;
}

SkFloatVector& SkFloatVector::operator-=(const SkFloatVector& other)
{
	_CRT_ALIGN(16)float dTemp[4]{ this->x,this->y,this->z,0.f };
	_CRT_ALIGN(16)float oTemp[4]{ other.x,other.y,other.z,0.f };
	__m128 _re = _mm_sub_ps(_mm_load_ps(dTemp), _mm_load_ps(oTemp));
	_CRT_ALIGN(16) float reTemp[4];
	_mm_store_ps(&reTemp[0], _re);
	this->x = reTemp[0];
	this->y = reTemp[1];
	this->z = reTemp[2];
	return *this;
}

float SkFloatVector::operator*(const SkFloatVector& other) const
{
	_CRT_ALIGN(16)float dTemp[4]{ this->x,this->y,this->z,0.f };
	_CRT_ALIGN(16)float oTemp[4]{ other.x,other.y,other.z,0.f };
	__m128 _re = _mm_mul_ps(_mm_load_ps(dTemp), _mm_load_ps(oTemp));
	_CRT_ALIGN(16) float reTemp[4];
	_mm_store_ps(&reTemp[0], _re);
	return reTemp[0] + reTemp[1] + reTemp[2];
}

SkFloatVector SkFloatVector::operator*(float scaler) const
{
	_CRT_ALIGN(16)float dTemp[4]{ this->x,this->y,this->z,0.f };
	_CRT_ALIGN(16)float oTemp[4]{ scaler,scaler,scaler,0.f };
	__m128 _re = _mm_mul_ps(_mm_load_ps(dTemp), _mm_load_ps(oTemp));
	_CRT_ALIGN(16) float reTemp[4];
	_mm_store_ps(&reTemp[0], _re);
	return SkFloatVector(reTemp[0], reTemp[1], reTemp[2]);
}

SkFloatVector& SkFloatVector::operator*=(float scaler)
{
	_CRT_ALIGN(16)float dTemp[4]{ this->x,this->y,this->z,0.f };
	_CRT_ALIGN(16)float oTemp[4]{ scaler,scaler,scaler,0.f };
	__m128 _re = _mm_mul_ps(_mm_load_ps(dTemp), _mm_load_ps(oTemp));
	_CRT_ALIGN(16) float reTemp[4];
	_mm_store_ps(&reTemp[0], _re);
	this->x = reTemp[0];
	this->y = reTemp[1];
	this->z = reTemp[2];
	return *this;
}

SkFloatVector SkFloatVector::operator^(const SkFloatVector& other) const
{
	_CRT_ALIGN(16)float dTemp[4]{ this->x,this->y,this->z,0.f };
	_CRT_ALIGN(16)float oTemp[4]{ other.x,other.y,other.z,0.f };
	__m128 _a = _mm_load_ps(dTemp);
	__m128 _b = _mm_load_ps(oTemp);
	__m128 _a1 = _mm_mul_ps(_mm_shuffle_ps(_a, _a, _MM_SHUFFLE(2, 1, 3, 0)),
		_mm_shuffle_ps(_b, _b, _MM_SHUFFLE(1, 3, 2, 0)));
	__m128 _b1 = _mm_mul_ps(_mm_shuffle_ps(_a, _a, _MM_SHUFFLE(1, 3, 2, 0)),
		_mm_shuffle_ps(_b, _b, _MM_SHUFFLE(2, 1, 3, 0)));
	__m128 _re = _mm_sub_ps(_a1, _b1);
	_CRT_ALIGN(16) float reTemp[4];
	_mm_store_ps(&reTemp[0], _re);
	return SkFloatVector(reTemp[0], reTemp[1], reTemp[2]);
}

SkFloatVector& SkFloatVector::operator^=(const SkFloatVector& other)
{
	_CRT_ALIGN(16)float dTemp[4]{ this->x,this->y,this->z,0.f };
	_CRT_ALIGN(16)float oTemp[4]{ other.x,other.y,other.z,0.f };
	__m128 _a = _mm_load_ps(dTemp);
	__m128 _b = _mm_load_ps(oTemp);
	__m128 _a1 = _mm_mul_ps(_mm_shuffle_ps(_a, _a, _MM_SHUFFLE(2, 1, 3, 0)),
		_mm_shuffle_ps(_b, _b, _MM_SHUFFLE(1, 3, 2, 0)));
	__m128 _b1 = _mm_mul_ps(_mm_shuffle_ps(_a, _a, _MM_SHUFFLE(1, 3, 2, 0)),
		_mm_shuffle_ps(_b, _b, _MM_SHUFFLE(2, 1, 3, 0)));
	__m128 _re = _mm_sub_ps(_a1, _b1);
	_CRT_ALIGN(16) float reTemp[4];
	_mm_store_ps(&reTemp[0], _re);
	this->x = reTemp[0];
	this->y = reTemp[1];
	this->z = reTemp[2];
	return *this;
}

}//namespace app
}//namespace skylina