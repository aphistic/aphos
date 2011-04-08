project(APHOS C ASM)
cmake_minimum_required(VERSION 2.8)

file(GLOB C_SRC
	"boot/*.c"
	"klib/*.c"
	"term/*.c"
	"*.c"
	)

file(GLOB ASM_SRC
	"boot/*.s"
	)

include_directories(
	../include
	)

set_source_files_properties(
	${ASM_SRC}
	PROPERTIES
	COMPILE_FLAGS "--32"
	)
set_source_files_properties(
	${C_SRC}
	PROPERTIES
	COMPILE_FLAGS "-Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -m32"
	)

add_executable(aphOS.bin ${ASM_SRC} ${C_SRC})
set_target_properties(aphOS.bin
	PROPERTIES
	LINK_FLAGS "-Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -m32 -T ${APHOS_SRC_DIR}/link/linker.ld"
	)