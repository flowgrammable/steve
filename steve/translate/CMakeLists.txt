add_subdirectory(cxx)

add_executable(steve-translate
	translate-stmt.cpp
	translate-decl.cpp
	translate-expr.cpp
	translate-pipeline.cpp
	translator.cpp
)

