cmake_minimum_required(VERSION 3.15)

# set the project name and version
project(SC VERSION 1.0)

set(CMAKE_DEBUG_POSTFIX d)

add_library(sc_compiler_flags INTERFACE)
target_compile_features(sc_compiler_flags INTERFACE cxx_std_11)

# add compiler warning flags just when building this project via
# the BUILD_INTERFACE genex
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(sc_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

# control where the static and shared libraries are built so that on windows
# we don't need to tinker with the path to run the executable
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

if(APPLE)
  set(CMAKE_INSTALL_RPATH "@executable_path/../lib")
elseif(UNIX)
  set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
endif()

# Subdirectories Variables
set(CMAKE_DIR "${CMAKE_CURRENT_LIST_DIR}/cmake")
set(SOCIETY_DIR "${CMAKE_CURRENT_LIST_DIR}/society")
set(SANDBOX_DIR "${CMAKE_CURRENT_LIST_DIR}/sandbox")

# Add Subdirectories
add_subdirectory(${CMAKE_DIR})
add_subdirectory(${SOCIETY_DIR})
add_subdirectory(${SANDBOX_DIR})

# setup installer
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_VERSION_MAJOR "${SC_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${SC_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "TGZ")
include(CPack)

# install the configuration targets
install(EXPORT SocietyTargets
  FILE SocietyTargets.cmake
  DESTINATION lib/cmake/Society
)

include(CMakePackageConfigHelpers)
# generate the config file that is includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/SocietyConfig.cmake"
  INSTALL_DESTINATION "lib/cmake/example"
  NO_SET_AND_CHECK_MACRO
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
  )
# generate the version file for the config file
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/SocietyConfigVersion.cmake"
  VERSION "${SC_VERSION_MAJOR}.${SC_VERSION_MINOR}"
  COMPATIBILITY AnyNewerVersion
)

# install the configuration file
install(FILES
  ${CMAKE_CURRENT_BINARY_DIR}/SocietyConfig.cmake
  DESTINATION lib/cmake/Society
  )

# generate the export targets for the build tree
# needs to be after the install(TARGETS ) command
export(EXPORT SocietyTargets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/SocietyTargets.cmake"
)

