# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TwoDay_06Tree_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TwoDay_06Tree_autogen.dir\\ParseCache.txt"
  "TwoDay_06Tree_autogen"
  )
endif()
