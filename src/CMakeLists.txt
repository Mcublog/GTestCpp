add_library(chunking)

target_sources(chunking
  PRIVATE
    chunking.c
  PUBLIC
    chunking.h
  )

target_include_directories(chunking
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

# we use this to get code coverage
# flags are only valid with the GNU compiler and on Linux
if(CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
  target_compile_options(chunking
    PUBLIC
      "--coverage"
    )
  target_link_options(chunking
    INTERFACE
      "--coverage"
    )
endif()
