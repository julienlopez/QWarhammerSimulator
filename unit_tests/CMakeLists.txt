set(EXE_TARGET_NAME unit_tests)

file(GLOB_RECURSE SOURCE_FILES ./*)
add_executable(${EXE_TARGET_NAME} ${SOURCE_FILES})

target_link_libraries(${EXE_TARGET_NAME} QWarhammerSimulator::LibWarhammerEngine CONAN_PKG::catch2)

#include(CTest)
#include(Catch)
#catch_discover_tests(${EXE_TARGET_NAME})

add_test(NAME ${EXE_TARGET_NAME} COMMAND ${EXE_TARGET_NAME} -r junit)
