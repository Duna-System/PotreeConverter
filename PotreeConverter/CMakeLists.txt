project(PotreeConverter)

set(RAPIDJSON_INCLUDE_DIR lib/rapidjson/include)
set(ARGUMENTS_INCLUDE_DIR lib/arguments)
# Assume laszip is installed in system.
set(LASZIP_LIBRARY laszip)

file(GLOB_RECURSE files src/*.cpp include/*.h include/*.hpp )
file(GLOB_RECURSE lib_rapidjson_files ${RAPIDJSON_INCLUDE_DIR}/* )
file(GLOB_RECURSE lib_argument_files ${ARGUMENTS_INCLUDE_DIR}/* )

include_directories(include ${LASZIP_INCLUDE_DIRS})
include_directories(include ${RAPIDJSON_INCLUDE_DIR})
include_directories(include ${ARGUMENTS_INCLUDE_DIR})

set(lib_srcs_
	src/BINPointReader.cpp
	src/LASPointReader.cpp
	src/LASPointWriter.cpp
	src/PTXPointReader.cpp
)

SOURCE_GROUP("lib\\rapidjson" FILES ${lib_rapidjson_files})
SOURCE_GROUP("lib\\arguments" FILES ${lib_argument_files})

add_library(PotreeConverterLib ${lib_srcs_})

# No need to add install directive. We use it internally.
target_include_directories(PotreeConverterLib INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  )
