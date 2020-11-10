cmake_minimum_required(VERSION 3.16)


#---------------------------------------
if (NOT DEFINED ENV{TRAVIS_BUILD_NUMBER})
    set(ENV{TRAVIS_BUILD_NUMBER} 1)
endif()
#---------------------------------------



#---------------------------------------
project(4g_editor VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
#---------------------------------------


#---------------------------------------
SET(FILES ${PROJECT_SOURCE_DIR}/gcore/GModel.h
          ${PROJECT_SOURCE_DIR}/gcore/GPage.h
          ${PROJECT_SOURCE_DIR}/gcore/GSubscriber.h
          ${PROJECT_SOURCE_DIR}/gcore/GNotifier.h
          ${PROJECT_SOURCE_DIR}/gcore/GEntity.h
          ${PROJECT_SOURCE_DIR}/gcore/GTools.h
          ${PROJECT_SOURCE_DIR}/gcore/GTools.cpp
          ${PROJECT_SOURCE_DIR}/gcore/GLoop.h

          ${PROJECT_SOURCE_DIR}/gobjects/GLine.h
          ${PROJECT_SOURCE_DIR}/gobjects/GLine.cpp)

add_executable(${PROJECT_NAME} gcore/main.cpp ${FILES})
#---------------------------------------


target_precompile_headers(4g_editor
  PUBLIC
    ${PROJECT_SOURCE_DIR}/gcore/GModel.h
    ${PROJECT_SOURCE_DIR}/gcore/GPage.h
    ${PROJECT_SOURCE_DIR}/gcore/GSubscriber.h
    ${PROJECT_SOURCE_DIR}/gcore/GNotifier.h
    ${PROJECT_SOURCE_DIR}/gcore/GEntity.h
    ${PROJECT_SOURCE_DIR}/gcore/GTools.h
    ${PROJECT_SOURCE_DIR}/gcore/GLoop.h
    ${PROJECT_SOURCE_DIR}/gobjects/GLine.h
)


#---------------------------------------
set_target_properties(4g_editor PROPERTIES CXX_STANDART 17 CXX_STANDART_REQUIRED ON
if (NOT WIN32)
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
else())
#---------------------------------------



#---------------------------------------
target_link_libraries (4g_editor)
#---------------------------------------



#---------------------------------------
install (TARGETS 4g_editor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT nikbar93@gmail.com)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

