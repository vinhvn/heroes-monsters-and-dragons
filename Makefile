# CXX is just the compiler. CXX means C++ compiler, CC means C compiler.
CXX     = g++
# RM is just a delete command
RM      = rm -f
# DEFINES is a list of preprocessor definitions
# Leave empty if no defines are needed
DEFINES =
# LIBS is a list of lib paths and libraries that might be needed for
# compilation. An example lib is the math library, which can be linked with
# `-lm`
LIBS    =
# INCLUDE is a list of include paths (directories to be searched for header
# files). Here the include paths are this directory and ./include.
INCLUDE = -I. -I./include
# WARNING is all warning flags that are turned on or off. If you don't like
# warnings, just remove everything after the equals sign, but I highly
# recommend keeping -Werror=return-type (it prevents forgetting to return from
# a function with a return type).
WARNING = -Wall -Wextra -Werror=return-type
# FLAGS are additional flags not specified above.
# -g compiles the program with debug information, to make debugging with tools
# like gdb much easier
# -std=c++11 sets the C++ standard to 11. The standard can be set to more
# recent standards (14 or 17) if the course VM can handle newer standards.
# -O2 turns on level 2 optimization, and is needed to turn on some warnings.
FLAGS   = -g -std=c++11 -O2
# CFLAGS is just a list of all of the flags
CFLAGS  = $(INCLUDE) $(LIBS) $(WARNING) $(FLAGS) $(DEFINES)

# Change `NAME` to whatever you want your executable's name to be
NAME    = final

# SOURCES is just a list of all .cc files
SOURCES = $(wildcard *.cc)
# SRC_OBJECTS is all .o files to be generated from each .cc file
SRC_OBJECTS = $(patsubst %.cc,%.o,$(SOURCES))

# Add any .o files that aren't built specifically by this project
# (.o files from other sources), otherwise do not change this line
NONSRC_OBJECTS =

all:	$(NAME)

# This target builds the main executable
$(NAME):	$(SRC_OBJECTS) $(NONSRC_OBJECTS)
	# $@ refers to the target name, in this case sas
	# $^ refers to all dependencies, in this case all source and non-source
	# objects
	$(CXX) $(CFLAGS) -o $@ $^

# This target intelligently only deletes object files compiled by this
# Makefile (not object files from other sources), and the executable.
# .PHONY just means the target does not produce a file when it is executed.
.PHONY: clean
clean:
	$(RM) $(SRC_OBJECTS) $(NAME)

# Run `make run` to build and then run the executable
.PHONY: run
run:	$(NAME)
	./$(NAME)

# Run `make test` to build and then run the executable with in.txt
.PHONY: test
test:	$(NAME)
	./$(NAME) < in.txt

# Run `make submission` to create a tar of all submission files
submission:	clean
	$(RM) submission_filename.tar
	# As you can see, all Unix commands can be run from a Makefile
	tar -cf submission_filename.tar *

# This is a magic target, where it takes any .cc file, and compiles its
# .o file
%.o:	%.cc
	$(CXX) -c $(CFLAGS) $*.cc -o $*.o
