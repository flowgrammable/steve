find_path(farmhash_ROOT_DIR
    NAMES include/farmhash.h
)

find_path(farmhash_INCLUDE_DIR
    NAMES farmhash.h
    HINTS ${farmhash_ROOT_DIR}/include
)

find_library(farmhash_LIBRARY
    NAMES farmhash
    HINTS ${farmhash_ROOT_DIR}/lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(farmhash DEFAULT_MSG
    farmhash_LIBRARY
    farmhash_INCLUDE_DIR
)

mark_as_advanced(
    farmhash_ROOT_DIR
    farmhash_INCLUDE_DIR
    farmhash_LIBRARY
)

set(farmhash_LIBRARIES ${farmhash_LIBRARY})
set(farmhash_INCLUDE_DIRS ${farmhash_INCLUDE_DIR})
