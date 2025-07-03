# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ServerManager_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ServerManager_autogen.dir\\ParseCache.txt"
  "ServerManager_autogen"
  )
endif()
