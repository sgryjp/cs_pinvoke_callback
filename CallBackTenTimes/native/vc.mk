#######################################
# makefile for Visual C++ 6.0
# note:
#   .
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
OUTPUT		= -oCallBackTenTimes.dll


#--------------------------------------
# files
#--------------------------------------
SOURCES =\
CallBackTenTimes.c\
CallBackTenTimes.def

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
