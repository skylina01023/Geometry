#pragma once
#include "skMicro.h"
#include "SkFloatVector.h"
#include <boost/align/aligned_allocator.hpp>
#include <vector>

namespace skylina {
namespace app {

using SkFloatVectorArray = std::vector<SkFloatVector, boost::alignment::aligned_allocator<SkFloatPoint, 16>>;

}//namespace app
}//namespace skylina