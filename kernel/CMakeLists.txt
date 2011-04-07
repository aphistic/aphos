project(APHOSKERNEL C)
cmake_minimum_required(VERSION 2.8)

set(SRCS
	kernel.c
	)

set_source_files_properties(
	kernel.c
	PROPERTIES
	COMPILE_FLAGS "-Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -m32"
	LINK_FLAGS "-m32"
	)
# add -Werror back in!

add_library(aphOS.kernel STATIC ${SRCS})
set_target_properties(aphOS.kernel
	PROPERTIES
	PREFIX ""
	)
