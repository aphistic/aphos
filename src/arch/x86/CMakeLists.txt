file(GLOB ASM_SRC
	"boot/*.s"
	)

#set_source_files_properties(
#	${ASM_SRC}
#	PROPERTIES
#	COMPILE_FLAGS "-m32"
#	)

set(CMAKE_ASM-ATT_COMPILER i586-elf-as)
enable_language(ASM-ATT)

set_source_files_properties(
	${ASM_SRC}
	PROPERTIES
	COMPILE_FLAGS "-g -gdwarf-2"
	)

add_library(boot STATIC ${ASM_SRC})

set(CMAKE_EXE_LINKER_FLAGS "-T ${CMAKE_CURRENT_SOURCE_DIR}/boot/linker.ld -nostdlib -ffreestanding")
add_executable(aphos "../stub.c")
target_link_libraries(aphos boot kernel gcc)
add_custom_command(
	TARGET aphos
	POST_BUILD
	COMMAND objcopy ARGS --only-keep-debug ${CMAKE_BINARY_DIR}/bin/aphos ${CMAKE_BINARY_DIR}/bin/aphos.sym
	)