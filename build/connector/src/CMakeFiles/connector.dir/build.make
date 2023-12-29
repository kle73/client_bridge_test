# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/karlkoerner/CODE/Nautilus/client_bridge_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/karlkoerner/CODE/Nautilus/client_bridge_test/build

# Include any dependencies generated for this target.
include connector/src/CMakeFiles/connector.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include connector/src/CMakeFiles/connector.dir/compiler_depend.make

# Include the progress variables for this target.
include connector/src/CMakeFiles/connector.dir/progress.make

# Include the compile flags for this target's objects.
include connector/src/CMakeFiles/connector.dir/flags.make

connector/src/CMakeFiles/connector.dir/connector.c.o: connector/src/CMakeFiles/connector.dir/flags.make
connector/src/CMakeFiles/connector.dir/connector.c.o: /Users/karlkoerner/CODE/Nautilus/client_bridge_test/connector/src/connector.c
connector/src/CMakeFiles/connector.dir/connector.c.o: connector/src/CMakeFiles/connector.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/karlkoerner/CODE/Nautilus/client_bridge_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object connector/src/CMakeFiles/connector.dir/connector.c.o"
	cd /Users/karlkoerner/CODE/Nautilus/client_bridge_test/build/connector/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT connector/src/CMakeFiles/connector.dir/connector.c.o -MF CMakeFiles/connector.dir/connector.c.o.d -o CMakeFiles/connector.dir/connector.c.o -c /Users/karlkoerner/CODE/Nautilus/client_bridge_test/connector/src/connector.c

connector/src/CMakeFiles/connector.dir/connector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/connector.dir/connector.c.i"
	cd /Users/karlkoerner/CODE/Nautilus/client_bridge_test/build/connector/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/karlkoerner/CODE/Nautilus/client_bridge_test/connector/src/connector.c > CMakeFiles/connector.dir/connector.c.i

connector/src/CMakeFiles/connector.dir/connector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/connector.dir/connector.c.s"
	cd /Users/karlkoerner/CODE/Nautilus/client_bridge_test/build/connector/src && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/karlkoerner/CODE/Nautilus/client_bridge_test/connector/src/connector.c -o CMakeFiles/connector.dir/connector.c.s

# Object files for target connector
connector_OBJECTS = \
"CMakeFiles/connector.dir/connector.c.o"

# External object files for target connector
connector_EXTERNAL_OBJECTS =

connector/src/libconnector.a: connector/src/CMakeFiles/connector.dir/connector.c.o
connector/src/libconnector.a: connector/src/CMakeFiles/connector.dir/build.make
connector/src/libconnector.a: connector/src/CMakeFiles/connector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/karlkoerner/CODE/Nautilus/client_bridge_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libconnector.a"
	cd /Users/karlkoerner/CODE/Nautilus/client_bridge_test/build/connector/src && $(CMAKE_COMMAND) -P CMakeFiles/connector.dir/cmake_clean_target.cmake
	cd /Users/karlkoerner/CODE/Nautilus/client_bridge_test/build/connector/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/connector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
connector/src/CMakeFiles/connector.dir/build: connector/src/libconnector.a
.PHONY : connector/src/CMakeFiles/connector.dir/build

connector/src/CMakeFiles/connector.dir/clean:
	cd /Users/karlkoerner/CODE/Nautilus/client_bridge_test/build/connector/src && $(CMAKE_COMMAND) -P CMakeFiles/connector.dir/cmake_clean.cmake
.PHONY : connector/src/CMakeFiles/connector.dir/clean

connector/src/CMakeFiles/connector.dir/depend:
	cd /Users/karlkoerner/CODE/Nautilus/client_bridge_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/karlkoerner/CODE/Nautilus/client_bridge_test /Users/karlkoerner/CODE/Nautilus/client_bridge_test/connector/src /Users/karlkoerner/CODE/Nautilus/client_bridge_test/build /Users/karlkoerner/CODE/Nautilus/client_bridge_test/build/connector/src /Users/karlkoerner/CODE/Nautilus/client_bridge_test/build/connector/src/CMakeFiles/connector.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : connector/src/CMakeFiles/connector.dir/depend

