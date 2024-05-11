# configure a header file to pass the version number only
configure_file(SCConfig.h.in SCConfig.h)

file(GLOB Sandbox_SRC CONFIGURE_DEPENDS
  "src/*.h"
  "src/*.cpp"
)

# add the executable
add_executable(SandboxApp ${Sandbox_SRC})

set_target_properties(SandboxApp PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

target_link_libraries(SandboxApp PUBLIC Society sc_compiler_flags)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(SandboxApp PUBLIC
  "${CMAKE_CURRENT_BINARY_DIR}"
)

# add the install targets
install(TARGETS SandboxApp DESTINATION bin)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/SCConfig.h"
  DESTINATION include
)

install(
  DIRECTORY "${CMAKE_SOURCE_DIR}/resources/"
  DESTINATION bin
)

add_custom_command(TARGET SandboxApp PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory
  ${CMAKE_CURRENT_SOURCE_DIR}/resources $<TARGET_FILE_DIR:SandboxApp>/resources)
