cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(numRec VERSION 0.6.0)

# Include dir
include_directories(/usr/local/include)

# Src
AUX_SOURCE_DIRECTORY(src SRC_FILES)

# Headers
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include/numRec_bits")

# Source files
set(SOURCE_FILES
	${PROJECT_INCLUDE_DIR}/nr.hpp
	${PROJECT_INCLUDE_DIR}/gaussj.hpp
	${PROJECT_INCLUDE_DIR}/ludcmp.hpp
	${PROJECT_INCLUDE_DIR}/banded.hpp
	${PROJECT_INCLUDE_DIR}/tridag.hpp
	${PROJECT_INCLUDE_DIR}/svd.hpp
	${PROJECT_INCLUDE_DIR}/vander.hpp
	${PROJECT_INCLUDE_DIR}/toeplz.hpp
	${PROJECT_INCLUDE_DIR}/cholesky.hpp
	${PROJECT_INCLUDE_DIR}/qrdcmp.hpp

	${PROJECT_SOURCE_DIR}/nr.cpp
	${PROJECT_SOURCE_DIR}/gaussj.cpp
	${PROJECT_SOURCE_DIR}/ludcmp.cpp
	${PROJECT_SOURCE_DIR}/banded.cpp
	${PROJECT_SOURCE_DIR}/tridag.cpp
	${PROJECT_SOURCE_DIR}/svd.cpp
	${PROJECT_SOURCE_DIR}/vander.cpp
	${PROJECT_SOURCE_DIR}/toeplz.cpp
	${PROJECT_SOURCE_DIR}/cholesky.cpp
	${PROJECT_SOURCE_DIR}/qrdcmp.cpp
)

# Set up such that XCode organizes the files correctly
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

# Add library
add_library(numRec SHARED ${SOURCE_FILES})

# Include directories
target_include_directories(numRec PRIVATE include/numRec_bits)

# Install
install(TARGETS numRec DESTINATION lib)

# Install the headers
install(FILES include/numRec DESTINATION include)

# Create base directory
install(DIRECTORY include/numRec_bits DESTINATION include)
