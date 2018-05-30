set(LIB ${CORE_TARGET})

set(SOURCE 
		testMain.cpp)

set(TARGET ${TEST_TARGET})
add_executable(${TARGET} ${SOURCE})
target_link_libraries(${TARGET} ${LIB})

add_custom_command(TARGET ${TARGET} POST_BUILD
	COMMAND SET PATH=$<TARGET_FILE_DIR:${CORE_TARGET}> 
	COMMAND ${TARGET})