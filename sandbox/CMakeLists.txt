# configure a header file to pass the version number only
configure_file(SCConfig.h.in SCConfig.h)

# add the executable
add_executable(SandboxApp Sandbox.cpp)


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