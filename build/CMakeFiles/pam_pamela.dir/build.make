# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jean/pamela

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jean/pamela/build

# Include any dependencies generated for this target.
include CMakeFiles/pam_pamela.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pam_pamela.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pam_pamela.dir/flags.make

CMakeFiles/pam_pamela.dir/src/Exception.cpp.o: CMakeFiles/pam_pamela.dir/flags.make
CMakeFiles/pam_pamela.dir/src/Exception.cpp.o: ../src/Exception.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jean/pamela/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/pam_pamela.dir/src/Exception.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pam_pamela.dir/src/Exception.cpp.o -c /home/jean/pamela/src/Exception.cpp

CMakeFiles/pam_pamela.dir/src/Exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pam_pamela.dir/src/Exception.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jean/pamela/src/Exception.cpp > CMakeFiles/pam_pamela.dir/src/Exception.cpp.i

CMakeFiles/pam_pamela.dir/src/Exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pam_pamela.dir/src/Exception.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jean/pamela/src/Exception.cpp -o CMakeFiles/pam_pamela.dir/src/Exception.cpp.s

CMakeFiles/pam_pamela.dir/src/Exception.cpp.o.requires:
.PHONY : CMakeFiles/pam_pamela.dir/src/Exception.cpp.o.requires

CMakeFiles/pam_pamela.dir/src/Exception.cpp.o.provides: CMakeFiles/pam_pamela.dir/src/Exception.cpp.o.requires
	$(MAKE) -f CMakeFiles/pam_pamela.dir/build.make CMakeFiles/pam_pamela.dir/src/Exception.cpp.o.provides.build
.PHONY : CMakeFiles/pam_pamela.dir/src/Exception.cpp.o.provides

CMakeFiles/pam_pamela.dir/src/Exception.cpp.o.provides.build: CMakeFiles/pam_pamela.dir/src/Exception.cpp.o

CMakeFiles/pam_pamela.dir/src/Logger.cpp.o: CMakeFiles/pam_pamela.dir/flags.make
CMakeFiles/pam_pamela.dir/src/Logger.cpp.o: ../src/Logger.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jean/pamela/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/pam_pamela.dir/src/Logger.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pam_pamela.dir/src/Logger.cpp.o -c /home/jean/pamela/src/Logger.cpp

CMakeFiles/pam_pamela.dir/src/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pam_pamela.dir/src/Logger.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jean/pamela/src/Logger.cpp > CMakeFiles/pam_pamela.dir/src/Logger.cpp.i

CMakeFiles/pam_pamela.dir/src/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pam_pamela.dir/src/Logger.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jean/pamela/src/Logger.cpp -o CMakeFiles/pam_pamela.dir/src/Logger.cpp.s

CMakeFiles/pam_pamela.dir/src/Logger.cpp.o.requires:
.PHONY : CMakeFiles/pam_pamela.dir/src/Logger.cpp.o.requires

CMakeFiles/pam_pamela.dir/src/Logger.cpp.o.provides: CMakeFiles/pam_pamela.dir/src/Logger.cpp.o.requires
	$(MAKE) -f CMakeFiles/pam_pamela.dir/build.make CMakeFiles/pam_pamela.dir/src/Logger.cpp.o.provides.build
.PHONY : CMakeFiles/pam_pamela.dir/src/Logger.cpp.o.provides

CMakeFiles/pam_pamela.dir/src/Logger.cpp.o.provides.build: CMakeFiles/pam_pamela.dir/src/Logger.cpp.o

CMakeFiles/pam_pamela.dir/src/pam.cpp.o: CMakeFiles/pam_pamela.dir/flags.make
CMakeFiles/pam_pamela.dir/src/pam.cpp.o: ../src/pam.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jean/pamela/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/pam_pamela.dir/src/pam.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pam_pamela.dir/src/pam.cpp.o -c /home/jean/pamela/src/pam.cpp

CMakeFiles/pam_pamela.dir/src/pam.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pam_pamela.dir/src/pam.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jean/pamela/src/pam.cpp > CMakeFiles/pam_pamela.dir/src/pam.cpp.i

CMakeFiles/pam_pamela.dir/src/pam.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pam_pamela.dir/src/pam.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jean/pamela/src/pam.cpp -o CMakeFiles/pam_pamela.dir/src/pam.cpp.s

CMakeFiles/pam_pamela.dir/src/pam.cpp.o.requires:
.PHONY : CMakeFiles/pam_pamela.dir/src/pam.cpp.o.requires

CMakeFiles/pam_pamela.dir/src/pam.cpp.o.provides: CMakeFiles/pam_pamela.dir/src/pam.cpp.o.requires
	$(MAKE) -f CMakeFiles/pam_pamela.dir/build.make CMakeFiles/pam_pamela.dir/src/pam.cpp.o.provides.build
.PHONY : CMakeFiles/pam_pamela.dir/src/pam.cpp.o.provides

CMakeFiles/pam_pamela.dir/src/pam.cpp.o.provides.build: CMakeFiles/pam_pamela.dir/src/pam.cpp.o

CMakeFiles/pam_pamela.dir/src/Crypt.cpp.o: CMakeFiles/pam_pamela.dir/flags.make
CMakeFiles/pam_pamela.dir/src/Crypt.cpp.o: ../src/Crypt.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jean/pamela/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/pam_pamela.dir/src/Crypt.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pam_pamela.dir/src/Crypt.cpp.o -c /home/jean/pamela/src/Crypt.cpp

CMakeFiles/pam_pamela.dir/src/Crypt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pam_pamela.dir/src/Crypt.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jean/pamela/src/Crypt.cpp > CMakeFiles/pam_pamela.dir/src/Crypt.cpp.i

CMakeFiles/pam_pamela.dir/src/Crypt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pam_pamela.dir/src/Crypt.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jean/pamela/src/Crypt.cpp -o CMakeFiles/pam_pamela.dir/src/Crypt.cpp.s

CMakeFiles/pam_pamela.dir/src/Crypt.cpp.o.requires:
.PHONY : CMakeFiles/pam_pamela.dir/src/Crypt.cpp.o.requires

CMakeFiles/pam_pamela.dir/src/Crypt.cpp.o.provides: CMakeFiles/pam_pamela.dir/src/Crypt.cpp.o.requires
	$(MAKE) -f CMakeFiles/pam_pamela.dir/build.make CMakeFiles/pam_pamela.dir/src/Crypt.cpp.o.provides.build
.PHONY : CMakeFiles/pam_pamela.dir/src/Crypt.cpp.o.provides

CMakeFiles/pam_pamela.dir/src/Crypt.cpp.o.provides.build: CMakeFiles/pam_pamela.dir/src/Crypt.cpp.o

CMakeFiles/pam_pamela.dir/src/Utils.cpp.o: CMakeFiles/pam_pamela.dir/flags.make
CMakeFiles/pam_pamela.dir/src/Utils.cpp.o: ../src/Utils.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jean/pamela/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/pam_pamela.dir/src/Utils.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pam_pamela.dir/src/Utils.cpp.o -c /home/jean/pamela/src/Utils.cpp

CMakeFiles/pam_pamela.dir/src/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pam_pamela.dir/src/Utils.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jean/pamela/src/Utils.cpp > CMakeFiles/pam_pamela.dir/src/Utils.cpp.i

CMakeFiles/pam_pamela.dir/src/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pam_pamela.dir/src/Utils.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jean/pamela/src/Utils.cpp -o CMakeFiles/pam_pamela.dir/src/Utils.cpp.s

CMakeFiles/pam_pamela.dir/src/Utils.cpp.o.requires:
.PHONY : CMakeFiles/pam_pamela.dir/src/Utils.cpp.o.requires

CMakeFiles/pam_pamela.dir/src/Utils.cpp.o.provides: CMakeFiles/pam_pamela.dir/src/Utils.cpp.o.requires
	$(MAKE) -f CMakeFiles/pam_pamela.dir/build.make CMakeFiles/pam_pamela.dir/src/Utils.cpp.o.provides.build
.PHONY : CMakeFiles/pam_pamela.dir/src/Utils.cpp.o.provides

CMakeFiles/pam_pamela.dir/src/Utils.cpp.o.provides.build: CMakeFiles/pam_pamela.dir/src/Utils.cpp.o

# Object files for target pam_pamela
pam_pamela_OBJECTS = \
"CMakeFiles/pam_pamela.dir/src/Exception.cpp.o" \
"CMakeFiles/pam_pamela.dir/src/Logger.cpp.o" \
"CMakeFiles/pam_pamela.dir/src/pam.cpp.o" \
"CMakeFiles/pam_pamela.dir/src/Crypt.cpp.o" \
"CMakeFiles/pam_pamela.dir/src/Utils.cpp.o"

# External object files for target pam_pamela
pam_pamela_EXTERNAL_OBJECTS =

pam_pamela.so: CMakeFiles/pam_pamela.dir/src/Exception.cpp.o
pam_pamela.so: CMakeFiles/pam_pamela.dir/src/Logger.cpp.o
pam_pamela.so: CMakeFiles/pam_pamela.dir/src/pam.cpp.o
pam_pamela.so: CMakeFiles/pam_pamela.dir/src/Crypt.cpp.o
pam_pamela.so: CMakeFiles/pam_pamela.dir/src/Utils.cpp.o
pam_pamela.so: CMakeFiles/pam_pamela.dir/build.make
pam_pamela.so: /usr/lib/x86_64-linux-gnu/libpam.so
pam_pamela.so: /usr/lib/x86_64-linux-gnu/libdl.so
pam_pamela.so: CMakeFiles/pam_pamela.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library pam_pamela.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pam_pamela.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pam_pamela.dir/build: pam_pamela.so
.PHONY : CMakeFiles/pam_pamela.dir/build

CMakeFiles/pam_pamela.dir/requires: CMakeFiles/pam_pamela.dir/src/Exception.cpp.o.requires
CMakeFiles/pam_pamela.dir/requires: CMakeFiles/pam_pamela.dir/src/Logger.cpp.o.requires
CMakeFiles/pam_pamela.dir/requires: CMakeFiles/pam_pamela.dir/src/pam.cpp.o.requires
CMakeFiles/pam_pamela.dir/requires: CMakeFiles/pam_pamela.dir/src/Crypt.cpp.o.requires
CMakeFiles/pam_pamela.dir/requires: CMakeFiles/pam_pamela.dir/src/Utils.cpp.o.requires
.PHONY : CMakeFiles/pam_pamela.dir/requires

CMakeFiles/pam_pamela.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pam_pamela.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pam_pamela.dir/clean

CMakeFiles/pam_pamela.dir/depend:
	cd /home/jean/pamela/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jean/pamela /home/jean/pamela /home/jean/pamela/build /home/jean/pamela/build /home/jean/pamela/build/CMakeFiles/pam_pamela.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pam_pamela.dir/depend

