# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild

# Utility rule file for img-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/img-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/img-populate.dir/progress.make

CMakeFiles/img-populate: CMakeFiles/img-populate-complete

CMakeFiles/img-populate-complete: img-populate-prefix/src/img-populate-stamp/img-populate-install
CMakeFiles/img-populate-complete: img-populate-prefix/src/img-populate-stamp/img-populate-mkdir
CMakeFiles/img-populate-complete: img-populate-prefix/src/img-populate-stamp/img-populate-download
CMakeFiles/img-populate-complete: img-populate-prefix/src/img-populate-stamp/img-populate-update
CMakeFiles/img-populate-complete: img-populate-prefix/src/img-populate-stamp/img-populate-patch
CMakeFiles/img-populate-complete: img-populate-prefix/src/img-populate-stamp/img-populate-configure
CMakeFiles/img-populate-complete: img-populate-prefix/src/img-populate-stamp/img-populate-build
CMakeFiles/img-populate-complete: img-populate-prefix/src/img-populate-stamp/img-populate-install
CMakeFiles/img-populate-complete: img-populate-prefix/src/img-populate-stamp/img-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'img-populate'"
	/opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E make_directory /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/CMakeFiles
	/opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E touch /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/CMakeFiles/img-populate-complete
	/opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E touch /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix/src/img-populate-stamp/img-populate-done

img-populate-prefix/src/img-populate-stamp/img-populate-update:
.PHONY : img-populate-prefix/src/img-populate-stamp/img-populate-update

img-populate-prefix/src/img-populate-stamp/img-populate-build: img-populate-prefix/src/img-populate-stamp/img-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'img-populate'"
	cd /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-build && /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E echo_append
	cd /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-build && /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E touch /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix/src/img-populate-stamp/img-populate-build

img-populate-prefix/src/img-populate-stamp/img-populate-configure: img-populate-prefix/tmp/img-populate-cfgcmd.txt
img-populate-prefix/src/img-populate-stamp/img-populate-configure: img-populate-prefix/src/img-populate-stamp/img-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'img-populate'"
	cd /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-build && /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E echo_append
	cd /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-build && /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E touch /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix/src/img-populate-stamp/img-populate-configure

img-populate-prefix/src/img-populate-stamp/img-populate-download: img-populate-prefix/src/img-populate-stamp/img-populate-gitinfo.txt
img-populate-prefix/src/img-populate-stamp/img-populate-download: img-populate-prefix/src/img-populate-stamp/img-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'img-populate'"
	cd /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps && /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -P /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix/tmp/img-populate-gitclone.cmake
	cd /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps && /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E touch /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix/src/img-populate-stamp/img-populate-download

img-populate-prefix/src/img-populate-stamp/img-populate-install: img-populate-prefix/src/img-populate-stamp/img-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'img-populate'"
	cd /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-build && /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E echo_append
	cd /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-build && /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E touch /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix/src/img-populate-stamp/img-populate-install

img-populate-prefix/src/img-populate-stamp/img-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'img-populate'"
	/opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -Dcfgdir= -P /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix/tmp/img-populate-mkdirs.cmake
	/opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E touch /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix/src/img-populate-stamp/img-populate-mkdir

img-populate-prefix/src/img-populate-stamp/img-populate-patch: img-populate-prefix/src/img-populate-stamp/img-populate-patch-info.txt
img-populate-prefix/src/img-populate-stamp/img-populate-patch: img-populate-prefix/src/img-populate-stamp/img-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'img-populate'"
	/opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E echo_append
	/opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E touch /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix/src/img-populate-stamp/img-populate-patch

img-populate-prefix/src/img-populate-stamp/img-populate-update:
.PHONY : img-populate-prefix/src/img-populate-stamp/img-populate-update

img-populate-prefix/src/img-populate-stamp/img-populate-test: img-populate-prefix/src/img-populate-stamp/img-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'img-populate'"
	cd /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-build && /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E echo_append
	cd /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-build && /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -E touch /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix/src/img-populate-stamp/img-populate-test

img-populate-prefix/src/img-populate-stamp/img-populate-update: img-populate-prefix/tmp/img-populate-gitupdate.cmake
img-populate-prefix/src/img-populate-stamp/img-populate-update: img-populate-prefix/src/img-populate-stamp/img-populate-update-info.txt
img-populate-prefix/src/img-populate-stamp/img-populate-update: img-populate-prefix/src/img-populate-stamp/img-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Performing update step for 'img-populate'"
	cd /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-src && /opt/homebrew/Cellar/cmake/3.27.8/bin/cmake -Dcan_fetch=YES -P /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/img-populate-prefix/tmp/img-populate-gitupdate.cmake

img-populate: CMakeFiles/img-populate
img-populate: CMakeFiles/img-populate-complete
img-populate: img-populate-prefix/src/img-populate-stamp/img-populate-build
img-populate: img-populate-prefix/src/img-populate-stamp/img-populate-configure
img-populate: img-populate-prefix/src/img-populate-stamp/img-populate-download
img-populate: img-populate-prefix/src/img-populate-stamp/img-populate-install
img-populate: img-populate-prefix/src/img-populate-stamp/img-populate-mkdir
img-populate: img-populate-prefix/src/img-populate-stamp/img-populate-patch
img-populate: img-populate-prefix/src/img-populate-stamp/img-populate-test
img-populate: img-populate-prefix/src/img-populate-stamp/img-populate-update
img-populate: CMakeFiles/img-populate.dir/build.make
.PHONY : img-populate

# Rule to build all files generated by this target.
CMakeFiles/img-populate.dir/build: img-populate
.PHONY : CMakeFiles/img-populate.dir/build

CMakeFiles/img-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/img-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/img-populate.dir/clean

CMakeFiles/img-populate.dir/depend:
	cd /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild /Users/aurelienmichaud/Documents/IMAC/C++/TowerDefense/build/_deps/img-subbuild/CMakeFiles/img-populate.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/img-populate.dir/depend
