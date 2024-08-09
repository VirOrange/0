# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\THREE_01_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\THREE_01_autogen.dir\\ParseCache.txt"
  "THREE_01_autogen"
  )
endif()
