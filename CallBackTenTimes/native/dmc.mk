#######################################
# makefile for Digital Mars C++
#######################################


#--------------------------------------
# compiler settings
#--------------------------------------
CXX	= dmc


#--------------------------------------
# system parameters
#--------------------------------------
RM		= DEL /Q


#--------------------------------------
# compile options
#--------------------------------------
# WD : Windows DLL
CXXFLAGS	= -WD
INCLUDES	= 
LIBS		= kernel32.lib
DEFINES		= -DNDEBUG -D_WINDOWS -DWIN32
#OUTPUT		= 


#--------------------------------------
# files
#--------------------------------------
SOURCES =\
CallBackTenTimes.c\
CallBackTenTimes.def

CLEANTARGETS =\
*.obj \
*.map


#--------------------------------------
# targets
#--------------------------------------
all:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(SOURCES) $(LIBS) $(OUTPUT)
