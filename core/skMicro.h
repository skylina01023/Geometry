#pragma once

#include <malloc.h>
#include <intrin.h>

namespace skylina {
namespace app {

#define SK_DECLARE_ALIGNED_ALLOCATOR(_align) \
void* operator new(size_t size){ \
	return _aligned_malloc(size,_align);\
}\
void operator delete(void* ptr) {\
	_aligned_free(ptr);\
}\

}//namespace app
}//namespace skylina
