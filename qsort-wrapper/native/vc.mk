#######################################
# makefile for Visual C++ 6.0
#######################################


#--------------------------------------
# compiler settings
#--------------------------------------
CXX	= cl


#--------------------------------------
# system parameters
#--------------------------------------
RM		= rm -f


#--------------------------------------
# compile options
#--------------------------------------
# LD : create DLL
# W4 : warning level 4 (max)
CXXFLAGS	= /LD /W3 /GX
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
