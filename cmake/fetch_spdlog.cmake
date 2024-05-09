
include(FetchContent)

set(SPDLOG_GIT_TAG
    "v1.14.1"
    CACHE STRING "Spdlog release version git tag.")

FetchContent_Declare(
    spdlog-github
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG ${SPDLOG_GIT_TAG}
)

FetchContent_MakeAvailable(spdlog-github)
