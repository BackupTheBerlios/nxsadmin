#
# Generated Makefile - do not edit!
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

# Macros
PLATFORM=GNU-Linux-x86

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/Release/${PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/sa_main_window.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/sa_process_window.o \
	${OBJECTDIR}/sa_sys_utils.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=`pkg-config gtkmm-2.4 --cflags` 
CXXFLAGS=`pkg-config gtkmm-2.4 --cflags` 

# Fortran Compiler Flags
FFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Release.mk dist/Release/${PLATFORM}/nxsadmin

dist/Release/${PLATFORM}/nxsadmin: ${OBJECTFILES}
	${MKDIR} -p dist/Release/${PLATFORM}
	${LINK.cc} `pkg-config gtkmm-2.4 --libs` -o dist/Release/${PLATFORM}/nxsadmin -s  ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/sa_main_window.o: sa_main_window.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -Wall -s -DPROGRAMNAME_LOCALEDIR=\"/usr/local/share/locale\" -MMD -MP -MF $@.d -o ${OBJECTDIR}/sa_main_window.o sa_main_window.cc

${OBJECTDIR}/main.o: main.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -Wall -s -DPROGRAMNAME_LOCALEDIR=\"/usr/local/share/locale\" -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cc

${OBJECTDIR}/sa_process_window.o: sa_process_window.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -Wall -s -DPROGRAMNAME_LOCALEDIR=\"/usr/local/share/locale\" -MMD -MP -MF $@.d -o ${OBJECTDIR}/sa_process_window.o sa_process_window.cc

${OBJECTDIR}/sa_sys_utils.o: sa_sys_utils.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -Wall -s -DPROGRAMNAME_LOCALEDIR=\"/usr/local/share/locale\" -MMD -MP -MF $@.d -o ${OBJECTDIR}/sa_sys_utils.o sa_sys_utils.cc

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/Release
	${RM} dist/Release/${PLATFORM}/nxsadmin

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
