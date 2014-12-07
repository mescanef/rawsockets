SRC := src
Includes            :=  -I$(SRC)/
CXX      := /usr/bin/g++ 
CXXFLAGS :=  -g -O0 -Wall -std=c++11 $(Includes)
ObjectSuffix           :=.o
SRCObjectSuffix :=.cpp
OutputDir  := Debug
RM := /usr/bin/rm
NAME := rawsockets
MakeDirCommand         := mkdir -p

Objects=$(OutputDir)/main$(ObjectSuffix) $(OutputDir)/Client$(ObjectSuffix) $(OutputDir)/ClientSocket$(ObjectSuffix) $(OutputDir)/SocketClass$(ObjectSuffix) $(OutputDir)/Server$(ObjectSuffix) $(OutputDir)/ServerSocket$(ObjectSuffix) $(OutputDir)/Logger$(ObjectSuffix)
SRCObjects=$(SRC)/main$(SRCObjectSuffix) $(SRC)/Client$(SRCObjectSuffix) $(SRC)/ClientSocket$(SRCObjectSuffix) $(SRC)/SocketClass$(SRCObjectSuffix) $(SRC)/Server$(SRCObjectSuffix) $(SRC)/ServerSocket$(SRCObjectSuffix) $(SRC)/Logger$(SRCObjectSuffix) 

##
## Build
##
all: $(Objects) 

$(OutputDir)/%$(ObjectSuffix): $(SRC)/%$(SRCObjectSuffix) | $(OutputDir)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(OutputDir):
	test -d ./$(OutputDir) || $(MakeDirCommand) $(OutputDir)

all: $(Objects) 
	$(CXX) -o $(OutputDir)/$(NAME) $(Objects) 
	$(RM) $(OutputDir)/*$(ObjectSuffix)

##
## Clean
##
clean:
	$(RM) $(OutputDir)/*
