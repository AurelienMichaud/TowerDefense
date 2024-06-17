# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-src"
  "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-build"
  "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix"
  "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix/tmp"
  "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix/src/img-populate-stamp"
  "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix/src"
  "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix/src/img-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix/src/img-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix/src/img-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
