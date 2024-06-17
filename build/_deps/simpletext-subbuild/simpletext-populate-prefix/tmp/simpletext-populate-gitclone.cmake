# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if(EXISTS "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/simpletext-subbuild/simpletext-populate-prefix/src/simpletext-populate-stamp/simpletext-populate-gitclone-lastrun.txt" AND EXISTS "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/simpletext-subbuild/simpletext-populate-prefix/src/simpletext-populate-stamp/simpletext-populate-gitinfo.txt" AND
  "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/simpletext-subbuild/simpletext-populate-prefix/src/simpletext-populate-stamp/simpletext-populate-gitclone-lastrun.txt" IS_NEWER_THAN "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/simpletext-subbuild/simpletext-populate-prefix/src/simpletext-populate-stamp/simpletext-populate-gitinfo.txt")
  message(STATUS
    "Avoiding repeated git clone, stamp file is up to date: "
    "'/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/simpletext-subbuild/simpletext-populate-prefix/src/simpletext-populate-stamp/simpletext-populate-gitclone-lastrun.txt'"
  )
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/simpletext-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/simpletext-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/opt/homebrew/bin/git"
            clone --no-checkout --config "advice.detachedHead=false" "https://github.com/dsmtE/SimpleText/" "simpletext-src"
    WORKING_DIRECTORY "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps"
    RESULT_VARIABLE error_code
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/dsmtE/SimpleText/'")
endif()

execute_process(
  COMMAND "/opt/homebrew/bin/git"
          checkout "master" --
  WORKING_DIRECTORY "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/simpletext-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'master'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/opt/homebrew/bin/git" 
            submodule update --recursive --init 
    WORKING_DIRECTORY "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/simpletext-src"
    RESULT_VARIABLE error_code
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/simpletext-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/simpletext-subbuild/simpletext-populate-prefix/src/simpletext-populate-stamp/simpletext-populate-gitinfo.txt" "/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/simpletext-subbuild/simpletext-populate-prefix/src/simpletext-populate-stamp/simpletext-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/simpletext-subbuild/simpletext-populate-prefix/src/simpletext-populate-stamp/simpletext-populate-gitclone-lastrun.txt'")
endif()