#######################################
# makefile for MinGW
# note:
#   Pass "-l" options to "g++" AFTER
#   sources in command-line.
#######################################


#--------------------------------------
# compiler settings
#--------------------------------------
CXX	= gcc


#--------------------------------------
# system parameters
#--------------------------------------
RM		= rm -f


#--------------------------------------
# compile options
#--------------------------------------
CXXFLAGS	= -shared
INCLUDES	= 
LIBS		= 
DEFINES		= -DNDEBUG -D_WINDOWS -DWIN32
OUTPUT		= -ostdcall_qsort.dll


#--------------------------------------
# files
#--------------------------------------
SOURCES =\
stdcall_qsort.c\
stdcall_qsort.def

CLEANTARGETS =\
*.obj \
*.lib \
*.exp \
*.map


#--------------------------------------
# targets
#--------------------------------------
all:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEFINES) $(SOURCES) $(LIBS) $(OUTPUT)

clean:
	$(RM) $(CLEANTARGETS)
