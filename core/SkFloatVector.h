#pragma once
#include "skMicro.h"

namespace skylina {
namespace app {

class SkFloatPoint;

_CRT_ALIGN(16) class SkFloatVector
{
public:
	SK_DECLARE_ALIGNED_ALLOCATOR(16)
public:
	SkFloatVector() = default;
	SkFloatVector(float x, float y, float z);
	SkFloatVector(const SkFloatPoint& pnt);
	float length() const;
	void normalize();
	SkFloatVector normal() const;
	SkFloatVector operator + (const SkFloatVector& other) const;
	SkFloatVector operator - (const SkFloatVector& other) const;
	SkFloatVector& operator+=(const SkFloatVector& other);
	SkFloatVector& operator-=(const SkFloatVector& other);
	float operator*(const SkFloatVector& other) const;
	SkFloatVector operator*(float) const;
	SkFloatVector& operator*=(float);
	SkFloatVector operator^(const SkFloatVector& other) const;
	SkFloatVector& operator^=(const SkFloatVector& other);
	bool operator==(const SkFloatVector& other) const {
		return (x == other.x) && (y == other.y) && (z == other.z);
	}
	bool operator!=(const SkFloatVector& other) const {
		return (x != other.x) || (y != other.y) || (z != other.z);
	}

public:
	float x{ 0.0 };
	float y{ 0.0 };
	float z{ 0.0 };
};

}//namespace app
}//namespace skylina