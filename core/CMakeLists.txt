

set(SOURCE 
		SkFloatPoint.cpp
		SkFloatVector.cpp
		SkSurfaceMesh.cpp)


set(TARGET ${CORE_TARGET})
add_library(${TARGET} SHARED ${SOURCE})
set_property(TARGET ${TARGET} PROPERTY WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
