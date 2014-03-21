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
	COMPILE_FLAGS "-g -gdwarf-2 -Wall -Wextra -ffreestanding -std=gnu99"
	)

add_library(kernel STATIC ${C_SRC})