# Revision History -- at the bottom of the document
################################################################################
# The targets in this file are used in .gitlab-ci.yml and  the files created
# are found in the .gitignore
################################################################################
# Changing any names below can change the target names which will require that
# you update .gitlab_ci.yml and .gitignore
################################################################################

################################################################################
# Variable definitions
################################################################################

# Executable names
PROJECT = project
GTEST = test_${PROJECT}

# Compilation command and flags
CXX=g++
CXXVERSION= -std=c++14
CXXFLAGS= ${CXXVERSION} -g
CXXWITHCOVERAGEFLAGS = ${CXXFLAGS} -fprofile-arcs -ftest-coverage
LINKFLAGS= -lgtest

# Directories
GTEST_DIR = test
SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

# Libraries
LIB = -Llibs -lPlayDice

# Tool variables
GCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage
STATIC_ANALYSIS = cppcheck
STYLE_CHECK = cpplint
DESIGN_DIR = docs/design
DOXY_DIR = docs/code

################################################################################
# Targets
################################################################################

# Default goal
.DEFAULT_GOAL := compileProject

################################################################################
# Clean-up targets
################################################################################

.PHONY: clean-docs
clean-docs:
	rm -rf docs/code/html

.PHONY: clean-exec
clean-exec:
	rm -rf ${PROJECT} ${GTEST} ${PROJECT}.exe ${GTEST}.exe

.PHONY: clean-obj
clean-obj:
	rm -rf ${SRC}/*.o

.PHONY: clean-temp
clean-temp:
	rm -rf *~ \#* .\#* \
	${GTEST_DIR}/*~ ${GTEST_DIR}/\#* ${GTEST_DIR}/.\#* \
	${SRC_INCLUDE}/*~ ${SRC_INCLUDE}/\#* ${SRC_INCLUDE}/.\#* \
	${DESIGN_DIR}/*~ ${DESIGN_DIR}/\#* ${DESIGN_DIR}/.\#* \
	*.gcov *.gcda *.gcno 

.PHONY: clean
clean: clean-docs clean-exec clean-obj clean-temp

################################################################################
# Compilaton targets
################################################################################

# default rule for compiling .cc to .o
%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

# Compilation targets

# compilation for performing testing
# using the files in include, src, and test, but not src/project
${GTEST}: ${GTEST_DIR}/*.cpp
	${CXX} ${CXXFLAGS} -o ./${GTEST} ${INCLUDE} \
	${GTEST_DIR}/*.cpp ${LINKFLAGS} ${LIB}

################################################################################
# Test targets
################################################################################

# To perform all tests
all: ${GTEST} docs static style

# To perform the static check 
static: ${GTEST_DIR}
	${STATIC_ANALYSIS} --verbose --enable=all ${GTEST_DIR} \
	${SRC_INCLUDE} --suppress=missingInclude --error-exitcode=1

# To perform the style check
style: ${GTEST_DIR} ${SRC_INCLUDE}
	${STYLE_CHECK} ${GTEST_DIR}/* ${SRC_INCLUDE}/*

################################################################################
# Documentation target
################################################################################

# To produce the documentation
.PHONY: docs
docs: ${SRC_INCLUDE}
	doxygen ${DOXY_DIR}/doxyfile

################################################################################
# Revision History
################################################################################
# Updated: 2022-12-15 Nicole Wilson <n.wilson@uleth.ca>
#  Removed all references to OS as the pipelines are now running on Ubuntu
################################################################################
# Updated: 2022-10-19 Dr. J. Anvik <john.anvik@uleth.ca>
#  Changed the static command to make the pipeline fail on exit with errors.
################################################################################
# Updated: 2022-09-11 Nicole Wilson <n.wilson@uleth.ca>
#  Added reference to OS in setting of STYLE_CHECK.
#  This is a temporary measure until the pipelines are running on Ubuntu
################################################################################
