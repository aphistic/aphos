project(APHOSBOOT ASM)
cmake_minimum_required(VERSION 2.8)

set(SRCS
	loader.s)

add_library(aphOS.boot STATIC ${SRCS})
set_target_properties(aphOS.boot
	PROPERTIES
	PREFIX ""
	COMPILE_FLAGS "--32"
	LINK_FLAGS "-m32"
	)
