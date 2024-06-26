file(GLOB Society_SRC CONFIGURE_DEPENDS
  "src/*.h"
  "src/*.cpp"
  "src/Society/*.cpp"
  "src/Society/Core/*.cpp"
  "src/Society/Managers/*.cpp"
  "src/Society/Vendor/*.cpp"
)

# add the library that runs
add_library(Society ${Society_SRC})

target_precompile_headers(Society PUBLIC "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_SOURCE_DIR}/Society/src/pch/scpch.h>")

target_include_directories(Society
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/pch>
  $<INSTALL_INTERFACE:include>
)

# state that anybody linking to us needs to include the current source dir
# to find Society.h, while we don't.
target_include_directories(Society
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
  $<INSTALL_INTERFACE:include>
)

# Add OpenGL
find_package(OpenGL REQUIRED)

# link Society to societyproject_compiler_flags
target_link_libraries(Society PUBLIC sc_compiler_flags glm glad spdlog glfw OpenGL::GL)

# define the symbol stating we are using the declspec(dllexport) when
# building on windows
target_compile_definitions(Society PRIVATE "EXPORTING")

# setup the version numbering
set_property(TARGET Society PROPERTY VERSION "1.0.0")
set_property(TARGET Society PROPERTY SOVERSION "1")

# install libs
set(installable_libs Society sc_compiler_flags glm-header-only glm spdlog glfw glad)
install(TARGETS ${installable_libs}
  EXPORT SocietyTargets
  DESTINATION lib)

# install include headers
install(FILES src/Society.h DESTINATION include)
