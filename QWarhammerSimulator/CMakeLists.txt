set(EXE_TARGET_NAME QWarhammerSimulator)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(
  Qt6
  COMPONENTS Widgets
  REQUIRED)

add_executable(
  ${EXE_TARGET_NAME}
  "main.cpp"
  "mainwindow.cpp"
  "screen.cpp"
  "header.cpp"
  "commandpanel.cpp"
  "playerheader.cpp"
  "screen_event_handler/screeneventhanlderfactory.cpp"
  "screen_event_handler/shooting.cpp"
  "utils.cpp" "selection.hpp" )

target_link_libraries(
  ${EXE_TARGET_NAME} PRIVATE QWarhammerSimulator::LibUtils
                             QWarhammerSimulator::LibWarhammerEngine
                             Qt6::Widgets Qt6::Gui Qt6::Core)

# copy the required librairies
get_target_property(_qmake_executable Qt6::qmake IMPORTED_LOCATION)
get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")

if(WIN32)
  # execute windeployqt in a directory after build and copy it to where the bin
  # is built
  add_custom_command(
    TARGET ${EXE_TARGET_NAME}
    POST_BUILD
    COMMAND
      "${CMAKE_COMMAND}" -E env PATH="${_qt_bin_dir}"
      "${WINDEPLOYQT_EXECUTABLE}" --verbose 0 --dir
      "${CMAKE_CURRENT_BINARY_DIR}/windeployqt"
      \"$<TARGET_FILE:${EXE_TARGET_NAME}>\"
    COMMAND
      "${CMAKE_COMMAND}" -E copy_directory
      \"${CMAKE_CURRENT_BINARY_DIR}/windeployqt/\"
      \"$<TARGET_FILE_DIR:${EXE_TARGET_NAME}>\"
    COMMENT "Deploying Qt...")

  # copy deployment directory during installation
  install(
    DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/windeployqt/"
    DESTINATION "${EXE_TARGET_INSTALL_DIR}"
    COMPONENT ${EXE_TARGET_COMPONENT})
endif()
