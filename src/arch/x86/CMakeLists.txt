file(GLOB ASM_SRC
	"boot/*.s"
	)

set_source_files_properties(
	${ASM_SRC}
	PROPERTIES
	COMPILE_FLAGS "-m32"
	)

add_executable(aphos ${ASM_SRC})
set_target_properties(aphos
	PROPERTIES
	LINK_FLAGS "-Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -m32 -T ${CMAKE_CURRENT_SOURCE_DIR}/boot/linker.ld"
	)
target_link_libraries(aphos kernel)