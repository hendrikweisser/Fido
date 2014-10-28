cmake_minimum_required(VERSION 2.8.3 FATAL_ERROR)
project(fido)

if(NOT CMAKE_BUILD_TYPE) ## "DEBUG" is the default
  set(CMAKE_BUILD_TYPE "Release")
endif()

include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-Wall" HAS_WALL)
if(HAS_WALL)
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
endif()

check_cxx_compiler_flag("-ffast-math" HAS_FAST_MATH)
if(HAS_FAST_MATH)
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -ffast-math")
endif()

set(Fido_sources
  src/Set.cpp
  src/Vector.cpp
  src/Numerical.cpp
  src/Matrix.cpp
  src/GramSchmidt.cpp
  src/LPSolver.cpp
  src/ForwardSampler.cpp
  src/Random.cpp
  src/ProteinIdentifier.cpp
  src/BasicBigraph.cpp
  src/BasicGroupBigraph.cpp
  src/GroupPowerBigraph.cpp
  src/PeptideFeatureReader.cpp
  src/KDMethod.cpp
  src/PivdoSplitter.cpp
  src/InputFileShrinker.cpp
)

if (WIN32) ## on Windows, add "getopt" (Linux/Mac have "unistd.h")
  set(Fido_sources ${Fido_sources} src/win/getopt.c)
endif()

include_directories(${PROJECT_SOURCE_DIR}/src)
add_executable(Fido src/mainFido.cpp ${Fido_sources})
add_executable(FidoChooseParameters src/mainFido_ChooseParameters.cpp ${Fido_sources})
