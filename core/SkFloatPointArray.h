#pragma once
#include "skMicro.h"
#include "SkFloatPoint.h"
#include <boost/align/aligned_allocator.hpp>
#include <vector>

namespace skylina {
namespace app {

using SkFloatPointArray = std::vector<SkFloatPoint, boost::alignment::aligned_allocator<SkFloatPoint, 16>>;

}//namespace app
}//namespace skylina