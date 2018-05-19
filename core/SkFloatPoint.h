#pragma once
#include "skMicro.h"

namespace skylina {
namespace app {

class SkFloatVector;

_CRT_ALIGN(16) class SkFloatPoint
{
public:
	SK_DECLARE_ALIGNED_ALLOCATOR(16)
public:
	SkFloatPoint() = default;
	SkFloatPoint(float x, float y, float z);
	SkFloatPoint(const SkFloatVector& vec);
	float distanceTo(const SkFloatPoint& other) const;
	SkFloatPoint operator + (const SkFloatPoint& other) const;
	SkFloatPoint operator - (const SkFloatPoint& other) const;
	SkFloatPoint& operator+=(const SkFloatPoint& other);
	SkFloatPoint& operator-=(const SkFloatPoint& other);
	bool operator==(const SkFloatPoint& other) const {
		return (x == other.x) && (y == other.y) && (z == other.z) && (w == other.w);
	}
	bool operator!=(const SkFloatPoint& other) const {
		return (x != other.x) || (y != other.y) || (z != other.z) || (w != other.w);
	}

public:
	float x{ 0.0 };
	float y{ 0.0 };
	float z{ 0.0 };
private:
	float w{ 1.0 };
};
}//namespace app
}//namespace skylina