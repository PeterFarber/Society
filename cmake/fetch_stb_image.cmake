
include(FetchContent)

FetchContent_Declare(
    stb_image-github
    URL https://raw.githubusercontent.com/nothings/stb/master/stb_image.h
    DOWNLOAD_NO_EXTRACT ON)

FetchContent_MakeAvailable(stb_image-github)

add_library(stb_image INTERFACE  ${stb_image-github_SOURCE_DIR}/stb_image.h)


# target_include_directories(stb_image PUBLIC ${stb_image-github_SOURCE_DIR})
set_target_properties(stb_image PROPERTIES LINKER_LANGUAGE CXX)

# target_compile_definitions(stb_image PUBLIC STB_IMAGE_IMPLEMENTATION)