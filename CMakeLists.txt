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
)

# Generate list of tests files
if (BUILD_TESTING OR NOT DEFINED BUILD_TESTING)
	file(GLOB TEST_FILES
		CONFIGURE_DEPENDS
		"tests/*.cpp"
	)
	list(APPEND SOURCE ${TEST_FILES})
endif()

# Add an executable using the source files list
set(LIBRARY_NAME FileManager)
add_executable(${LIBRARY_NAME})

# Disable compiler specific extensions
set_target_properties(${LIBRARY_NAME}
	PROPERTIES
	CXX_EXTENSIONS OFF
)
# Enable a lot of warnings for executable
target_compile_options(${LIBRARY_NAME}
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
	target_compile_options(${LIBRARY_NAME}
		PRIVATE
		-g
	)
endif()
# Enable C++20 standart to a executable
target_compile_features(${LIBRARY_NAME} PUBLIC cxx_std_20)

# Add source files to a executable
target_sources(${LIBRARY_NAME}
	PRIVATE
	${SOURCE}
)
# Add include directory to a executable
target_include_directories(${LIBRARY_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Link executable against GTest
target_link_libraries(${LIBRARY_NAME} PRIVATE GTest::gtest_main)

# Add tests with CTest
include(GoogleTest)
gtest_discover_tests(${LIBRARY_NAME})
