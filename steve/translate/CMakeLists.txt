add_subdirectory(cxx)

add_library(steve-translate STATIC
	translate-stmt.cpp
	translate-decl.cpp
	translate-expr.cpp
	translate-type.cpp
	translate-pipeline.cpp
)

target_link_libraries(steve-translate steve)
target_link_libraries(steve-translate lingo)
target_link_libraries(steve-translate metal-cxx)

add_subdirectory(translate-test)