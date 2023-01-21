cmake_minimum_required(VERSION 3.25.1)
project("FileManager" LANGUAGES CXX)

# Downloading and building from source googletest framework
include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG b796f7d44681514f58a683a3a71ff17c94edb0c1 # googletest-1.13.0
)
FetchContent_MakeAvailable(googletest)

# Generate list of source files
file(GLOB SOURCE
	CONFIGURE_DEPENDS
	"src/*.cpp"
	"tests/*.cpp"
)

# Add an executable using the source files list
set(TARGET FileManager)
add_executable(${TARGET})

# Disable compiler specific extensions
set_target_properties(${TARGET}
	PROPERTIES
	CXX_EXTENSIONS OFF
)
# Enable a lot of warnings for executable
target_compile_options(${TARGET}
	PRIVATE
	-Werror
	-pedantic-errors

	-Wall
	-Wextra
	-Wpedantic

	-Wcast-align
	-Wcast-qual
	-Wconversion
	-Wctor-dtor-privacy
	-Wduplicated-branches
	-Wduplicated-cond
	-Wextra-semi
	-Wfloat-equal
	-Wlogical-op
	-Wnon-virtual-dtor
	-Wold-style-cast
	-Woverloaded-virtual
	-Wredundant-decls
	-Wsign-conversion
	-Wsign-promo
)
# Add compile options for debug build type to executable
if(${CMAKE_BUILD_TYPE} STRLESS_EQUAL "Debug")
	target_compile_options(${TARGET}
		PRIVATE
		-g
	)
endif()
# Enable C++20 standart to a executable
target_compile_features(${TARGET} PUBLIC cxx_std_20)

# Add source files to a executable
target_sources(${TARGET}
	PRIVATE
	${SOURCE}
)
# Add include directory to a executable
target_include_directories(${TARGET} PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link executable against GTest
target_link_libraries(${TARGET} PRIVATE GTest::gtest_main)
