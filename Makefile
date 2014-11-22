SRC := src
Includes            :=  -I$(SRC)
CXX      := /usr/bin/g++ 
CXXFLAGS :=  -g -O0 -Wall -std=c++11 $(Includes)
ObjectSuffix           :=.o
SRCObjectSuffix :=.cpp
OutputDir  := Debug
RM := /usr/bin/rm
NAME := rawsockets

Objects=$(OutputDir)/main$(ObjectSuffix) $(OutputDir)/Client$(ObjectSuffix) $(OutputDir)/ClientSocket$(ObjectSuffix) $(OutputDir)/SocketClass$(ObjectSuffix) 
SRCObjects=$(SRC)/main$(SRCObjectSuffix) $(SRC)/Client$(SRCObjectSuffix) $(SRC)/ClientSocket$(SRCObjectSuffix) $(SRC)/SocketClass$(SRCObjectSuffix)  

##
## Build
##
all: $(Objects) 

$(OutputDir)/%$(ObjectSuffix): $(SRC)/%$(SRCObjectSuffix)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
 
# $(SRCObjects) -o $(OutputDir)/$(NAME)

##
## Clean
##
clean:
	$(RM) $(OutputDir)/*

