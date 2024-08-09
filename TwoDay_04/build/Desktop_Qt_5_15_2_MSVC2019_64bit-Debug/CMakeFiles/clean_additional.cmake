# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TwoDay_04_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TwoDay_04_autogen.dir\\ParseCache.txt"
  "TwoDay_04_autogen"
  )
endif()
