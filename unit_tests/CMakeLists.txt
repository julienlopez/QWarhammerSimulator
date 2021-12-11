set(EXE_TARGET_NAME unit_tests)

add_executable(${EXE_TARGET_NAME} "main.cpp" "custom_matchers.cpp" "test_monadic_pointer.cpp" "test_rectangle.cpp" "test_turnphase.cpp" "test_unit.cpp")

target_link_libraries(${EXE_TARGET_NAME} QWarhammerSimulator::LibUtils QWarhammerSimulator::LibWarhammerEngine CONAN_PKG::catch2)

include(CTest)
include(Catch)
catch_discover_tests(${EXE_TARGET_NAME})
