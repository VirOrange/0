# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\TwoDay_07Table_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\TwoDay_07Table_autogen.dir\\ParseCache.txt"
  "TwoDay_07Table_autogen"
  )
endif()
