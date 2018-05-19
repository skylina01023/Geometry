

set(SOURCE 
		SkFloatPoint.cpp
		SkFloatVector.cpp)


set(TARGET ${PROJECT_NAME}_core)
add_library(${TARGET} SHARED ${SOURCE})