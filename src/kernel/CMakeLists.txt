file(GLOB C_SRC
	"boot/*.c"
	"klib/*.c"
	"term/*.c"
	"*.c"
	)

include_directories(
	.
	)

set_source_files_properties(
	${C_SRC}
	PROPERTIES
	COMPILE_FLAGS "-Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -m32"
	)

add_library(kernel ${C_SRC})