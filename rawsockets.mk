##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=rawsockets
ConfigurationName      :=Debug
WorkspacePath          := "/home/mescanef/guestAgentProject/sfs"
ProjectPath            := "/home/mescanef/guestAgentProject/rawsockets"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=mescanef
Date                   :=11/22/14
CodeLitePath           :="/home/mescanef/.codelite"
LinkerName             :=/usr/bin/g++ 
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="rawsockets.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++ 
CC       := /usr/bin/gcc 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Client.cpp$(ObjectSuffix) $(IntermediateDirectory)/ClientSocket.cpp$(ObjectSuffix) $(IntermediateDirectory)/SocketClass.cpp$(ObjectSuffix) $(IntermediateDirectory)/getoptpp_getopt_pp.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mescanef/guestAgentProject/rawsockets/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Client.cpp$(ObjectSuffix): Client.cpp $(IntermediateDirectory)/Client.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mescanef/guestAgentProject/rawsockets/Client.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Client.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Client.cpp$(DependSuffix): Client.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Client.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Client.cpp$(DependSuffix) -MM "Client.cpp"

$(IntermediateDirectory)/Client.cpp$(PreprocessSuffix): Client.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Client.cpp$(PreprocessSuffix) "Client.cpp"

$(IntermediateDirectory)/ClientSocket.cpp$(ObjectSuffix): ClientSocket.cpp $(IntermediateDirectory)/ClientSocket.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mescanef/guestAgentProject/rawsockets/ClientSocket.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ClientSocket.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ClientSocket.cpp$(DependSuffix): ClientSocket.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ClientSocket.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ClientSocket.cpp$(DependSuffix) -MM "ClientSocket.cpp"

$(IntermediateDirectory)/ClientSocket.cpp$(PreprocessSuffix): ClientSocket.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ClientSocket.cpp$(PreprocessSuffix) "ClientSocket.cpp"

$(IntermediateDirectory)/SocketClass.cpp$(ObjectSuffix): SocketClass.cpp $(IntermediateDirectory)/SocketClass.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mescanef/guestAgentProject/rawsockets/SocketClass.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SocketClass.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SocketClass.cpp$(DependSuffix): SocketClass.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SocketClass.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SocketClass.cpp$(DependSuffix) -MM "SocketClass.cpp"

$(IntermediateDirectory)/SocketClass.cpp$(PreprocessSuffix): SocketClass.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SocketClass.cpp$(PreprocessSuffix) "SocketClass.cpp"

$(IntermediateDirectory)/getoptpp_getopt_pp.cpp$(ObjectSuffix): getoptpp/getopt_pp.cpp $(IntermediateDirectory)/getoptpp_getopt_pp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/mescanef/guestAgentProject/rawsockets/getoptpp/getopt_pp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/getoptpp_getopt_pp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/getoptpp_getopt_pp.cpp$(DependSuffix): getoptpp/getopt_pp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/getoptpp_getopt_pp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/getoptpp_getopt_pp.cpp$(DependSuffix) -MM "getoptpp/getopt_pp.cpp"

$(IntermediateDirectory)/getoptpp_getopt_pp.cpp$(PreprocessSuffix): getoptpp/getopt_pp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/getoptpp_getopt_pp.cpp$(PreprocessSuffix) "getoptpp/getopt_pp.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) "../sfs/.build-debug/rawsockets"


