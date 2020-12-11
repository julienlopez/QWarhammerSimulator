set(EXE_TARGET_NAME QWarhammerSimulator)

file(GLOB_RECURSE SOURCE_FILES ./*)
add_executable(${EXE_TARGET_NAME} ${SOURCE_FILES})

target_link_libraries(${EXE_TARGET_NAME})
