//#pragma once
#include "../core/SkFloatPoint.h"
#include <cmath>

namespace skylina {
namespace app {

float skfPntDistTest(SkFloatPoint& a, SkFloatPoint& b)
{
	return a.distanceTo(b);
}

TEST_CASE("Distance is calculated", "[distTest]") {
	REQUIRE(std::abs(skfPntDistTest(SkFloatPoint(1.f, 0.0, 0.0), SkFloatPoint(0.f, 0.f, 0.f))-1.f)< 10e-7);
}

}//namespace app
}//namesp