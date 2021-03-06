
# required to specify the c++ standard
cmake_minimum_required(VERSION 3.0)

# required for install
include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# project settings
# ----------------

# name
project(cppmat)

# file that contains the version information
set(parse_version src/${PROJECT_NAME}/${PROJECT_NAME}.h)

# header files
set(headers
  src/${PROJECT_NAME}/cppmat.h
  src/${PROJECT_NAME}/private.hpp
  src/${PROJECT_NAME}/private.h
  src/${PROJECT_NAME}/stl.hpp
  src/${PROJECT_NAME}/stl.h
  src/${PROJECT_NAME}/histogram.hpp
  src/${PROJECT_NAME}/histogram.h
  src/${PROJECT_NAME}/fix_cartesian.hpp
  src/${PROJECT_NAME}/fix_cartesian.h
  src/${PROJECT_NAME}/fix_cartesian_2.hpp
  src/${PROJECT_NAME}/fix_cartesian_3.hpp
  src/${PROJECT_NAME}/fix_cartesian_tensor2.hpp
  src/${PROJECT_NAME}/fix_cartesian_tensor2.h
  src/${PROJECT_NAME}/fix_cartesian_tensor2d.hpp
  src/${PROJECT_NAME}/fix_cartesian_tensor2d.h
  src/${PROJECT_NAME}/fix_cartesian_tensor2s.hpp
  src/${PROJECT_NAME}/fix_cartesian_tensor2s.h
  src/${PROJECT_NAME}/fix_cartesian_tensor4.hpp
  src/${PROJECT_NAME}/fix_cartesian_tensor4.h
  src/${PROJECT_NAME}/fix_cartesian_vector.hpp
  src/${PROJECT_NAME}/fix_cartesian_vector.h
  src/${PROJECT_NAME}/fix_diagonal_matrix.hpp
  src/${PROJECT_NAME}/fix_diagonal_matrix.h
  src/${PROJECT_NAME}/fix_misc_matrix.hpp
  src/${PROJECT_NAME}/fix_misc_matrix.h
  src/${PROJECT_NAME}/fix_regular_array.hpp
  src/${PROJECT_NAME}/fix_regular_array.h
  src/${PROJECT_NAME}/fix_regular_matrix.hpp
  src/${PROJECT_NAME}/fix_regular_matrix.h
  src/${PROJECT_NAME}/fix_regular_vector.hpp
  src/${PROJECT_NAME}/fix_regular_vector.h
  src/${PROJECT_NAME}/fix_symmetric_matrix.hpp
  src/${PROJECT_NAME}/fix_symmetric_matrix.h
  src/${PROJECT_NAME}/map_cartesian_tensor2.hpp
  src/${PROJECT_NAME}/map_cartesian_tensor2.h
  src/${PROJECT_NAME}/map_cartesian_tensor2d.hpp
  src/${PROJECT_NAME}/map_cartesian_tensor2d.h
  src/${PROJECT_NAME}/map_cartesian_tensor2s.hpp
  src/${PROJECT_NAME}/map_cartesian_tensor2s.h
  src/${PROJECT_NAME}/map_cartesian_tensor4.hpp
  src/${PROJECT_NAME}/map_cartesian_tensor4.h
  src/${PROJECT_NAME}/map_cartesian_vector.hpp
  src/${PROJECT_NAME}/map_cartesian_vector.h
  src/${PROJECT_NAME}/map_diagonal_matrix.hpp
  src/${PROJECT_NAME}/map_diagonal_matrix.h
  src/${PROJECT_NAME}/map_regular_array.hpp
  src/${PROJECT_NAME}/map_regular_array.h
  src/${PROJECT_NAME}/map_regular_matrix.hpp
  src/${PROJECT_NAME}/map_regular_matrix.h
  src/${PROJECT_NAME}/map_regular_vector.hpp
  src/${PROJECT_NAME}/map_regular_vector.h
  src/${PROJECT_NAME}/map_symmetric_matrix.hpp
  src/${PROJECT_NAME}/map_symmetric_matrix.h
  src/${PROJECT_NAME}/var_cartesian.hpp
  src/${PROJECT_NAME}/var_cartesian.h
  src/${PROJECT_NAME}/var_cartesian_tensor2.hpp
  src/${PROJECT_NAME}/var_cartesian_tensor2.h
  src/${PROJECT_NAME}/var_cartesian_tensor2d.hpp
  src/${PROJECT_NAME}/var_cartesian_tensor2d.h
  src/${PROJECT_NAME}/var_cartesian_tensor2s.hpp
  src/${PROJECT_NAME}/var_cartesian_tensor2s.h
  src/${PROJECT_NAME}/var_cartesian_tensor4.hpp
  src/${PROJECT_NAME}/var_cartesian_tensor4.h
  src/${PROJECT_NAME}/var_cartesian_vector.hpp
  src/${PROJECT_NAME}/var_cartesian_vector.h
  src/${PROJECT_NAME}/var_diagonal_matrix.hpp
  src/${PROJECT_NAME}/var_diagonal_matrix.h
  src/${PROJECT_NAME}/var_misc_matrix.hpp
  src/${PROJECT_NAME}/var_misc_matrix.h
  src/${PROJECT_NAME}/var_regular_array.hpp
  src/${PROJECT_NAME}/var_regular_array.h
  src/${PROJECT_NAME}/var_regular_matrix.hpp
  src/${PROJECT_NAME}/var_regular_matrix.h
  src/${PROJECT_NAME}/var_regular_vector.hpp
  src/${PROJECT_NAME}/var_regular_vector.h
  src/${PROJECT_NAME}/var_symmetric_matrix.hpp
  src/${PROJECT_NAME}/var_symmetric_matrix.h
  src/${PROJECT_NAME}/pybind11.h
  src/${PROJECT_NAME}/pybind11_fix_cartesian_tensor2.hpp
  src/${PROJECT_NAME}/pybind11_fix_cartesian_tensor2d.hpp
  src/${PROJECT_NAME}/pybind11_fix_cartesian_tensor2s.hpp
  src/${PROJECT_NAME}/pybind11_fix_cartesian_tensor4.hpp
  src/${PROJECT_NAME}/pybind11_fix_cartesian_vector.hpp
  src/${PROJECT_NAME}/pybind11_fix_diagonal_matrix.hpp
  src/${PROJECT_NAME}/pybind11_fix_regular_array.hpp
  src/${PROJECT_NAME}/pybind11_fix_regular_matrix.hpp
  src/${PROJECT_NAME}/pybind11_fix_regular_vector.hpp
  src/${PROJECT_NAME}/pybind11_fix_symmetric_matrix.hpp
  src/${PROJECT_NAME}/pybind11_var_cartesian_tensor2.hpp
  src/${PROJECT_NAME}/pybind11_var_cartesian_tensor2d.hpp
  src/${PROJECT_NAME}/pybind11_var_cartesian_tensor2s.hpp
  src/${PROJECT_NAME}/pybind11_var_cartesian_tensor4.hpp
  src/${PROJECT_NAME}/pybind11_var_cartesian_vector.hpp
  src/${PROJECT_NAME}/pybind11_var_diagonal_matrix.hpp
  src/${PROJECT_NAME}/pybind11_var_regular_array.hpp
  src/${PROJECT_NAME}/pybind11_var_regular_matrix.hpp
  src/${PROJECT_NAME}/pybind11_var_regular_vector.hpp
  src/${PROJECT_NAME}/pybind11_var_symmetric_matrix.hpp
)

# automatically parse the version number
file(READ "${parse_version}" version)
string(REGEX MATCH "define[ \t]+CPPMAT_WORLD_VERSION[ \t]+([0-9]+)" _ "${version}")
set(world_version "${CMAKE_MATCH_1}")
string(REGEX MATCH "define[ \t]+CPPMAT_MAJOR_VERSION[ \t]+([0-9]+)" _ "${version}")
set(major_version "${CMAKE_MATCH_1}")
string(REGEX MATCH "define[ \t]+CPPMAT_MINOR_VERSION[ \t]+([0-9]+)" _ "${version}")
set(minor_version "${CMAKE_MATCH_1}")
set(CPPMAT_VERSION_NUMBER ${world_version}.${major_version}.${minor_version})

# paths
# -----

set(CPPMAT_ROOT_DIR          "${CMAKE_INSTALL_PREFIX}")
set(CPPMAT_INCLUDE_DIR       "${CMAKE_INSTALL_INCLUDEDIR}")
set(INCLUDE_INSTALL_DIR      "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}")
set(CMAKEPACKAGE_INSTALL_DIR "${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME}")
set(PKGCONFIG_INSTALL_DIR    "${CMAKE_INSTALL_DATADIR}/pkgconfig")
set(fcmake                   "${PROJECT_NAME}Config.cmake")
set(fpkg                     "${PROJECT_NAME}.pc")

# options
# -------

# configure pkg-config (default: on)
option(PKGCONFIG "Build pkg-config ${fpkg} file" ON)

# disable pkg-config for native Windows builds
if(WIN32 OR CMAKE_HOST_SYSTEM_NAME MATCHES Windows)
  option(PKGCONFIG "Build pkg-config ${fpkg} file" OFF)
endif()

# C++ standard
# ------------

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if(NOT CMAKE_CXX_STANDARD OR CMAKE_CXX_STANDARD LESS 14)
  set(CMAKE_CXX_STANDARD 14)
endif()

# configure CMake
# ---------------

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  PATH_VARS CPPMAT_INCLUDE_DIR CPPMAT_ROOT_DIR
  INSTALL_DESTINATION ${CMAKEPACKAGE_INSTALL_DIR}
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

# install
# -------

# pkg-config
if(PKGCONFIG)
  configure_file(${fpkg}.in ${fpkg} @ONLY)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${fpkg} DESTINATION ${PKGCONFIG_INSTALL_DIR})
endif()

# CMake
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${fcmake} DESTINATION ${CMAKEPACKAGE_INSTALL_DIR})

# header files
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/${headers} DESTINATION ${INCLUDE_INSTALL_DIR})

# print information to screen
# ---------------------------

message(STATUS "")
message(STATUS "+---------------------------------------------------------------------------------")
message(STATUS "|")
message(STATUS "| Use 'make install' to install in")
message(STATUS "|   ${CMAKE_INSTALL_PREFIX}")
message(STATUS "|")
message(STATUS "| To specify a custom directory call")
message(STATUS "|   cmake /path/to/${PROJECT_NAME} -DCMAKE_INSTALL_PREFIX=yourprefix")
message(STATUS "|")
message(STATUS "| For custom paths, add the following line to your '~/.bashrc'")
message(STATUS "|   export PKG_CONFIG_PATH=${CMAKE_INSTALL_PREFIX}/share/pkgconfig:$PKG_CONFIG_PATH")
message(STATUS "|")
message(STATUS "+---------------------------------------------------------------------------------")
message(STATUS "")
