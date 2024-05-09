include(FetchContent)

# set(FETCHCONTENT_BASE_DIR ${PROJECT_SOURCE_DIR}/libs CACHE PATH "Missing description." FORCE)
FetchContent_Declare(assimp
    GIT_REPOSITORY https://github.com/assimp/assimp.git
    GIT_TAG master)

FetchContent_GetProperties(assimp)

if(NOT assimp_POPULATED)
    FetchContent_Populate(assimp)
    set(ASSIMP_BUILD_ASSIMP_TOOLS OFF CACHE BOOL "" FORCE)
    set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "" FORCE)

    set(ASSIMP_INSTALL_PDB OFF CACHE BOOL "" FORCE)
    set(ASSIMP_BUILD_ASSIMP_VIEW OFF CACHE BOOL "" FORCE)
    set(ASSIMP_INSTALL OFF CACHE BOOL "" FORCE)

    set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

    set(ASSIMP_INJECT_DEBUG_POSTFIX OFF CACHE BOOL "" FORCE)

    # set(ASSIMP_BUILD_FRAMEWORK ON CACHE BOOL "" FORCE)
    # set(ASSIMP_INSTALL OFF CACHE BOOL "" FORCE)
    add_subdirectory(${assimp_SOURCE_DIR} ${assimp_BINARY_DIR})
endif()

FetchContent_MakeAvailable(assimp)

# target_include_directories(3d_renderer PRIVATE libs/assimp-src/include)
# target_link_libraries(3d_renderer assimp)

# cmake_minimum_required(VERSION 3.18)

# include(FetchContent)

# set(ASSIMP_GIT_TAG "v5.2.2" CACHE STRING "Assimp github release tag.")

# FetchContent_Declare(
# assimp-github
# GIT_REPOSITORY https://github.com/assimp/assimp.git
# GIT_TAG ${ASSIMP_GIT_TAG}
# )

# set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
# set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
# set(ASSIMP_INJECT_DEBUG_POSTFIX OFF CACHE BOOL "" FORCE)
# set(ASSIMP_INSTALL OFF CACHE BOOL "" FORCE)

# set(DCMAKE_CXX_FLAGS OFF CACHE BOOL "" FORCE)
# set(DBUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
# set(ASSIMP_INSTALL OFF CACHE BOOL "" FORCE)

# -DCMAKE_CXX_FLAGS:STRING=${assimp_cmake_cxx_flags}
# -=OFF
# -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
# -DASSIMP_BUILD_ASSIMP_TOOLS=OFF
# -DASSIMP_BUILD_TESTS=OFF
# -DASSIMP_INSTALL_PDB=OFF
# -DASSIMP_BUILD_ZLIB=ON
# -DASSIMP_NO_EXPORT=OFF
# -DHUNTER_ENABLED=OFF

# FetchContent_MakeAvailable(assimp-github)