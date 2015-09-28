add_subdirectory(cxx)

add_executable(steve-translate
	translate-stmt.cpp
	translate-decl.cpp
	translate-expr.cpp
	translate-type.cpp
	translate-pipeline.cpp
	test-translate.cpp
)
target_link_libraries(steve-translate steve)
target_link_libraries(steve-translate lingo)
target_link_libraries(steve-translate metal-cxx)
