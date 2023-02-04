set(sources hello.cpp)
set(public_headers hello.hpp)
set(private_headers_dir details)

## Library
add_library(skeleton-core STATIC)
target_include_directories(skeleton-core PRIVATE ${private_headers_dir})
target_sources(skeleton-core
    PRIVATE ${sources}
    PUBLIC FILE_SET HEADERS
    BASE_DIRS ${PROJECT_SOURCE_DIR}/src/
    FILES ${public_headers})
target_compile_features(skeleton-core PUBLIC cxx_std_20)
set_target_properties(skeleton-core
    PROPERTIES
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

## Unit tests
set(test_sources hello.test.cpp)
add_executable(test-skeleton-core ${test_sources})
target_link_libraries(test-skeleton-core PRIVATE skeleton-core gtest_main)
target_compile_features(test-skeleton-core PRIVATE cxx_std_20)
set_target_properties(test-skeleton-core
    PROPERTIES
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

## CMake install
# define the `_Targets` file
install(
    TARGETS skeleton-core
    EXPORT ${PROJECT_NAME}_Targets
    FILE_SET HEADERS
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

include(CMakePackageConfigHelpers)

# create cmake version file
write_basic_package_version_file(
    "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    VERSION ${PROJECT_VERSOIN}
    COMPATIBILITY SameMajorVersion)

# create package config file
configure_package_config_file(
    "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
    "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION
    ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

# copy the `Target.cmake` file to the installation directory
install(
    EXPORT ${PROJECT_NAME}_Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)

# copy the remaining `.cmake` files to the destination
install(
    FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/${PROJECT_NAME}/cmake)
