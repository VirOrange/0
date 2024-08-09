# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TwoDay_05Control_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TwoDay_05Control_autogen.dir\\ParseCache.txt"
  "TwoDay_05Control_autogen"
  )
endif()
