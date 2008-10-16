#
# Gererated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/Release/GNU-Linux-x86

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/tos-staff.o \
	${OBJECTDIR}/Tokenizer.o \
	${OBJECTDIR}/tos-xconf.o \
	${OBJECTDIR}/tos-nxsession.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Os -fconserve-space -fno-enforce-eh-specs -fno-exceptions -fno-rtti
CXXFLAGS=-Os -fconserve-space -fno-enforce-eh-specs -fno-exceptions -fno-rtti

# Fortran Compiler Flags
FFLAGS=-s

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS} dist/Release/GNU-Linux-x86/tos-miniconf

dist/Release/GNU-Linux-x86/tos-miniconf: ${OBJECTFILES}
	${MKDIR} -p dist/Release/GNU-Linux-x86
	${LINK.cc} -o dist/Release/GNU-Linux-x86/tos-miniconf -s ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/main.o: main.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -Wall -s -o ${OBJECTDIR}/main.o main.cc

${OBJECTDIR}/tos-staff.o: tos-staff.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -Wall -s -o ${OBJECTDIR}/tos-staff.o tos-staff.cc

${OBJECTDIR}/Tokenizer.o: Tokenizer.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -Wall -s -o ${OBJECTDIR}/Tokenizer.o Tokenizer.cc

${OBJECTDIR}/tos-xconf.o: tos-xconf.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -Wall -s -o ${OBJECTDIR}/tos-xconf.o tos-xconf.cc

${OBJECTDIR}/tos-nxsession.o: tos-nxsession.cc 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.cc) -Wall -s -o ${OBJECTDIR}/tos-nxsession.o tos-nxsession.cc

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/GNU-Linux-x86/tos-miniconf

# Subprojects
.clean-subprojects:
