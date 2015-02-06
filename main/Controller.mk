##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=Controller
ConfigurationName      :=Release
WorkspacePath          := "G:\Git\Controlador"
ProjectPath            := "G:\Git\Controlador\Controller"
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Lucas
Date                   :=02/05/15
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=arm-linux-gnueabihf-g++
SharedObjectLinkerName :=arm-linux-gnueabihf-g++ -shared -fPIC
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
OutputFile             :=Output/Controller
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Controller.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  -static -static-libstdc++ -static-libgcc
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)C:/boost_arm 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)boost_system-gcc-mt-1_57 $(LibrarySwitch)boost_thread_pthread-gcc-mt-1_57 $(LibrarySwitch)pthread 
ArLibs                 :=  "libboost_system-gcc-mt-1_57.a" "libboost_thread_pthread-gcc-mt-1_57.a" "pthread" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)C:/boost_arm/stage/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := arm-linux-gnueabihf-ar rcu
CXX      := arm-linux-gnueabihf-g++
CC       := arm-linux-gnueabihf-gcc
CXXFLAGS :=  -O2 -Wall -std=c++11 $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := arm-linux-gnueabihf-as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/analog.cpp$(ObjectSuffix) $(IntermediateDirectory)/dashboard.cpp$(ObjectSuffix) $(IntermediateDirectory)/http_handler.cpp$(ObjectSuffix) $(IntermediateDirectory)/interface.cpp$(ObjectSuffix) $(IntermediateDirectory)/logger.cpp$(ObjectSuffix) $(IntermediateDirectory)/manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/timer.cpp$(ObjectSuffix) $(IntermediateDirectory)/util.cpp$(ObjectSuffix) $(IntermediateDirectory)/watch_dog.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/pins_definitions.cpp$(ObjectSuffix) $(IntermediateDirectory)/settings.cpp$(ObjectSuffix) $(IntermediateDirectory)/base64.cpp$(ObjectSuffix) $(IntermediateDirectory)/system.cpp$(ObjectSuffix) $(IntermediateDirectory)/rest.cpp$(ObjectSuffix) $(IntermediateDirectory)/controller.cpp$(ObjectSuffix) $(IntermediateDirectory)/pin.cpp$(ObjectSuffix) $(IntermediateDirectory)/presets.cpp$(ObjectSuffix) $(IntermediateDirectory)/bit_manip.cpp$(ObjectSuffix) $(IntermediateDirectory)/controller_io.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/cppformat_format.cc$(ObjectSuffix) $(IntermediateDirectory)/cppformat_posix.cc$(ObjectSuffix) $(IntermediateDirectory)/lua52_lapi.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lauxlib.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lbaselib.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lbitlib.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lcode.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lcorolib.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lctype.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_ldblib.c$(ObjectSuffix) \
	$(IntermediateDirectory)/lua52_ldebug.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_ldo.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_ldump.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lfunc.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lgc.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_linit.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_liolib.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_llex.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lmathlib.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lmem.c$(ObjectSuffix) \
	$(IntermediateDirectory)/lua52_loadlib.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lobject.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lopcodes.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_loslib.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lparser.c$(ObjectSuffix) 

Objects1=$(IntermediateDirectory)/lua52_lstate.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lstring.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lstrlib.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_ltable.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_ltablib.c$(ObjectSuffix) \
	$(IntermediateDirectory)/lua52_ltm.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lundump.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lvm.c$(ObjectSuffix) $(IntermediateDirectory)/lua52_lzio.c$(ObjectSuffix) $(IntermediateDirectory)/http_connection.cpp$(ObjectSuffix) $(IntermediateDirectory)/http_connection_manager.cpp$(ObjectSuffix) $(IntermediateDirectory)/http_mime_types.cpp$(ObjectSuffix) $(IntermediateDirectory)/http_reply.cpp$(ObjectSuffix) $(IntermediateDirectory)/http_request_handler.cpp$(ObjectSuffix) $(IntermediateDirectory)/http_request_parser.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/http_server.cpp$(ObjectSuffix) $(IntermediateDirectory)/http_authentication.cpp$(ObjectSuffix) $(IntermediateDirectory)/http_header_parser.cpp$(ObjectSuffix) $(IntermediateDirectory)/http_request.cpp$(ObjectSuffix) $(IntermediateDirectory)/modbus_modbus.cpp$(ObjectSuffix) $(IntermediateDirectory)/modbus_modbus_connection.cpp$(ObjectSuffix) $(IntermediateDirectory)/modbus_response.cpp$(ObjectSuffix) $(IntermediateDirectory)/modbus_read_coils_response.cpp$(ObjectSuffix) $(IntermediateDirectory)/modbus_read_discrete_inputs.cpp$(ObjectSuffix) $(IntermediateDirectory)/modbus_read_holding_registers.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/modbus_read_input_registers.cpp$(ObjectSuffix) $(IntermediateDirectory)/modbus_handler.cpp$(ObjectSuffix) $(IntermediateDirectory)/modbus_read_register.cpp$(ObjectSuffix) $(IntermediateDirectory)/modbus_write_register.cpp$(ObjectSuffix) $(IntermediateDirectory)/modbus_write_single_coil.cpp$(ObjectSuffix) 



Objects=$(Objects0) $(Objects1) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	@echo $(Objects1) >> $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/analog.cpp$(ObjectSuffix): analog.cpp $(IntermediateDirectory)/analog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/analog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/analog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/analog.cpp$(DependSuffix): analog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/analog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/analog.cpp$(DependSuffix) -MM "analog.cpp"

$(IntermediateDirectory)/analog.cpp$(PreprocessSuffix): analog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/analog.cpp$(PreprocessSuffix) "analog.cpp"

$(IntermediateDirectory)/dashboard.cpp$(ObjectSuffix): dashboard.cpp $(IntermediateDirectory)/dashboard.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/dashboard.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/dashboard.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/dashboard.cpp$(DependSuffix): dashboard.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/dashboard.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/dashboard.cpp$(DependSuffix) -MM "dashboard.cpp"

$(IntermediateDirectory)/dashboard.cpp$(PreprocessSuffix): dashboard.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/dashboard.cpp$(PreprocessSuffix) "dashboard.cpp"

$(IntermediateDirectory)/http_handler.cpp$(ObjectSuffix): http_handler.cpp $(IntermediateDirectory)/http_handler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/http_handler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/http_handler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/http_handler.cpp$(DependSuffix): http_handler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/http_handler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/http_handler.cpp$(DependSuffix) -MM "http_handler.cpp"

$(IntermediateDirectory)/http_handler.cpp$(PreprocessSuffix): http_handler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/http_handler.cpp$(PreprocessSuffix) "http_handler.cpp"

$(IntermediateDirectory)/interface.cpp$(ObjectSuffix): interface.cpp $(IntermediateDirectory)/interface.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/interface.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/interface.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/interface.cpp$(DependSuffix): interface.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/interface.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/interface.cpp$(DependSuffix) -MM "interface.cpp"

$(IntermediateDirectory)/interface.cpp$(PreprocessSuffix): interface.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/interface.cpp$(PreprocessSuffix) "interface.cpp"

$(IntermediateDirectory)/logger.cpp$(ObjectSuffix): logger.cpp $(IntermediateDirectory)/logger.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/logger.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/logger.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/logger.cpp$(DependSuffix): logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/logger.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/logger.cpp$(DependSuffix) -MM "logger.cpp"

$(IntermediateDirectory)/logger.cpp$(PreprocessSuffix): logger.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/logger.cpp$(PreprocessSuffix) "logger.cpp"

$(IntermediateDirectory)/manager.cpp$(ObjectSuffix): manager.cpp $(IntermediateDirectory)/manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/manager.cpp$(DependSuffix): manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/manager.cpp$(DependSuffix) -MM "manager.cpp"

$(IntermediateDirectory)/manager.cpp$(PreprocessSuffix): manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/manager.cpp$(PreprocessSuffix) "manager.cpp"

$(IntermediateDirectory)/timer.cpp$(ObjectSuffix): timer.cpp $(IntermediateDirectory)/timer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/timer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/timer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/timer.cpp$(DependSuffix): timer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/timer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/timer.cpp$(DependSuffix) -MM "timer.cpp"

$(IntermediateDirectory)/timer.cpp$(PreprocessSuffix): timer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/timer.cpp$(PreprocessSuffix) "timer.cpp"

$(IntermediateDirectory)/util.cpp$(ObjectSuffix): util.cpp $(IntermediateDirectory)/util.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/util.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/util.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/util.cpp$(DependSuffix): util.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/util.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/util.cpp$(DependSuffix) -MM "util.cpp"

$(IntermediateDirectory)/util.cpp$(PreprocessSuffix): util.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/util.cpp$(PreprocessSuffix) "util.cpp"

$(IntermediateDirectory)/watch_dog.cpp$(ObjectSuffix): watch_dog.cpp $(IntermediateDirectory)/watch_dog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/watch_dog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/watch_dog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/watch_dog.cpp$(DependSuffix): watch_dog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/watch_dog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/watch_dog.cpp$(DependSuffix) -MM "watch_dog.cpp"

$(IntermediateDirectory)/watch_dog.cpp$(PreprocessSuffix): watch_dog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/watch_dog.cpp$(PreprocessSuffix) "watch_dog.cpp"

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/pins_definitions.cpp$(ObjectSuffix): pins_definitions.cpp $(IntermediateDirectory)/pins_definitions.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/pins_definitions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pins_definitions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pins_definitions.cpp$(DependSuffix): pins_definitions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pins_definitions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pins_definitions.cpp$(DependSuffix) -MM "pins_definitions.cpp"

$(IntermediateDirectory)/pins_definitions.cpp$(PreprocessSuffix): pins_definitions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pins_definitions.cpp$(PreprocessSuffix) "pins_definitions.cpp"

$(IntermediateDirectory)/settings.cpp$(ObjectSuffix): settings.cpp $(IntermediateDirectory)/settings.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/settings.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/settings.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/settings.cpp$(DependSuffix): settings.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/settings.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/settings.cpp$(DependSuffix) -MM "settings.cpp"

$(IntermediateDirectory)/settings.cpp$(PreprocessSuffix): settings.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/settings.cpp$(PreprocessSuffix) "settings.cpp"

$(IntermediateDirectory)/base64.cpp$(ObjectSuffix): base64.cpp $(IntermediateDirectory)/base64.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/base64.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/base64.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/base64.cpp$(DependSuffix): base64.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/base64.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/base64.cpp$(DependSuffix) -MM "base64.cpp"

$(IntermediateDirectory)/base64.cpp$(PreprocessSuffix): base64.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/base64.cpp$(PreprocessSuffix) "base64.cpp"

$(IntermediateDirectory)/system.cpp$(ObjectSuffix): system.cpp $(IntermediateDirectory)/system.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/system.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/system.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/system.cpp$(DependSuffix): system.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/system.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/system.cpp$(DependSuffix) -MM "system.cpp"

$(IntermediateDirectory)/system.cpp$(PreprocessSuffix): system.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/system.cpp$(PreprocessSuffix) "system.cpp"

$(IntermediateDirectory)/rest.cpp$(ObjectSuffix): rest.cpp $(IntermediateDirectory)/rest.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/rest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/rest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/rest.cpp$(DependSuffix): rest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/rest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/rest.cpp$(DependSuffix) -MM "rest.cpp"

$(IntermediateDirectory)/rest.cpp$(PreprocessSuffix): rest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/rest.cpp$(PreprocessSuffix) "rest.cpp"

$(IntermediateDirectory)/controller.cpp$(ObjectSuffix): controller.cpp $(IntermediateDirectory)/controller.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/controller.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/controller.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/controller.cpp$(DependSuffix): controller.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/controller.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/controller.cpp$(DependSuffix) -MM "controller.cpp"

$(IntermediateDirectory)/controller.cpp$(PreprocessSuffix): controller.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/controller.cpp$(PreprocessSuffix) "controller.cpp"

$(IntermediateDirectory)/pin.cpp$(ObjectSuffix): pin.cpp $(IntermediateDirectory)/pin.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/pin.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pin.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pin.cpp$(DependSuffix): pin.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pin.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pin.cpp$(DependSuffix) -MM "pin.cpp"

$(IntermediateDirectory)/pin.cpp$(PreprocessSuffix): pin.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pin.cpp$(PreprocessSuffix) "pin.cpp"

$(IntermediateDirectory)/presets.cpp$(ObjectSuffix): presets.cpp $(IntermediateDirectory)/presets.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/presets.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/presets.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/presets.cpp$(DependSuffix): presets.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/presets.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/presets.cpp$(DependSuffix) -MM "presets.cpp"

$(IntermediateDirectory)/presets.cpp$(PreprocessSuffix): presets.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/presets.cpp$(PreprocessSuffix) "presets.cpp"

$(IntermediateDirectory)/bit_manip.cpp$(ObjectSuffix): bit_manip.cpp $(IntermediateDirectory)/bit_manip.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/bit_manip.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bit_manip.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bit_manip.cpp$(DependSuffix): bit_manip.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bit_manip.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/bit_manip.cpp$(DependSuffix) -MM "bit_manip.cpp"

$(IntermediateDirectory)/bit_manip.cpp$(PreprocessSuffix): bit_manip.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bit_manip.cpp$(PreprocessSuffix) "bit_manip.cpp"

$(IntermediateDirectory)/controller_io.cpp$(ObjectSuffix): controller_io.cpp $(IntermediateDirectory)/controller_io.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/controller_io.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/controller_io.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/controller_io.cpp$(DependSuffix): controller_io.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/controller_io.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/controller_io.cpp$(DependSuffix) -MM "controller_io.cpp"

$(IntermediateDirectory)/controller_io.cpp$(PreprocessSuffix): controller_io.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/controller_io.cpp$(PreprocessSuffix) "controller_io.cpp"

$(IntermediateDirectory)/cppformat_format.cc$(ObjectSuffix): cppformat/format.cc $(IntermediateDirectory)/cppformat_format.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/cppformat/format.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cppformat_format.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cppformat_format.cc$(DependSuffix): cppformat/format.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cppformat_format.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/cppformat_format.cc$(DependSuffix) -MM "cppformat/format.cc"

$(IntermediateDirectory)/cppformat_format.cc$(PreprocessSuffix): cppformat/format.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cppformat_format.cc$(PreprocessSuffix) "cppformat/format.cc"

$(IntermediateDirectory)/cppformat_posix.cc$(ObjectSuffix): cppformat/posix.cc $(IntermediateDirectory)/cppformat_posix.cc$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/cppformat/posix.cc" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cppformat_posix.cc$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cppformat_posix.cc$(DependSuffix): cppformat/posix.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cppformat_posix.cc$(ObjectSuffix) -MF$(IntermediateDirectory)/cppformat_posix.cc$(DependSuffix) -MM "cppformat/posix.cc"

$(IntermediateDirectory)/cppformat_posix.cc$(PreprocessSuffix): cppformat/posix.cc
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cppformat_posix.cc$(PreprocessSuffix) "cppformat/posix.cc"

$(IntermediateDirectory)/lua52_lapi.c$(ObjectSuffix): lua52/lapi.c $(IntermediateDirectory)/lua52_lapi.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lapi.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lapi.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lapi.c$(DependSuffix): lua52/lapi.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lapi.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lapi.c$(DependSuffix) -MM "lua52/lapi.c"

$(IntermediateDirectory)/lua52_lapi.c$(PreprocessSuffix): lua52/lapi.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lapi.c$(PreprocessSuffix) "lua52/lapi.c"

$(IntermediateDirectory)/lua52_lauxlib.c$(ObjectSuffix): lua52/lauxlib.c $(IntermediateDirectory)/lua52_lauxlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lauxlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lauxlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lauxlib.c$(DependSuffix): lua52/lauxlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lauxlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lauxlib.c$(DependSuffix) -MM "lua52/lauxlib.c"

$(IntermediateDirectory)/lua52_lauxlib.c$(PreprocessSuffix): lua52/lauxlib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lauxlib.c$(PreprocessSuffix) "lua52/lauxlib.c"

$(IntermediateDirectory)/lua52_lbaselib.c$(ObjectSuffix): lua52/lbaselib.c $(IntermediateDirectory)/lua52_lbaselib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lbaselib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lbaselib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lbaselib.c$(DependSuffix): lua52/lbaselib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lbaselib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lbaselib.c$(DependSuffix) -MM "lua52/lbaselib.c"

$(IntermediateDirectory)/lua52_lbaselib.c$(PreprocessSuffix): lua52/lbaselib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lbaselib.c$(PreprocessSuffix) "lua52/lbaselib.c"

$(IntermediateDirectory)/lua52_lbitlib.c$(ObjectSuffix): lua52/lbitlib.c $(IntermediateDirectory)/lua52_lbitlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lbitlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lbitlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lbitlib.c$(DependSuffix): lua52/lbitlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lbitlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lbitlib.c$(DependSuffix) -MM "lua52/lbitlib.c"

$(IntermediateDirectory)/lua52_lbitlib.c$(PreprocessSuffix): lua52/lbitlib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lbitlib.c$(PreprocessSuffix) "lua52/lbitlib.c"

$(IntermediateDirectory)/lua52_lcode.c$(ObjectSuffix): lua52/lcode.c $(IntermediateDirectory)/lua52_lcode.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lcode.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lcode.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lcode.c$(DependSuffix): lua52/lcode.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lcode.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lcode.c$(DependSuffix) -MM "lua52/lcode.c"

$(IntermediateDirectory)/lua52_lcode.c$(PreprocessSuffix): lua52/lcode.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lcode.c$(PreprocessSuffix) "lua52/lcode.c"

$(IntermediateDirectory)/lua52_lcorolib.c$(ObjectSuffix): lua52/lcorolib.c $(IntermediateDirectory)/lua52_lcorolib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lcorolib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lcorolib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lcorolib.c$(DependSuffix): lua52/lcorolib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lcorolib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lcorolib.c$(DependSuffix) -MM "lua52/lcorolib.c"

$(IntermediateDirectory)/lua52_lcorolib.c$(PreprocessSuffix): lua52/lcorolib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lcorolib.c$(PreprocessSuffix) "lua52/lcorolib.c"

$(IntermediateDirectory)/lua52_lctype.c$(ObjectSuffix): lua52/lctype.c $(IntermediateDirectory)/lua52_lctype.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lctype.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lctype.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lctype.c$(DependSuffix): lua52/lctype.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lctype.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lctype.c$(DependSuffix) -MM "lua52/lctype.c"

$(IntermediateDirectory)/lua52_lctype.c$(PreprocessSuffix): lua52/lctype.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lctype.c$(PreprocessSuffix) "lua52/lctype.c"

$(IntermediateDirectory)/lua52_ldblib.c$(ObjectSuffix): lua52/ldblib.c $(IntermediateDirectory)/lua52_ldblib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/ldblib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_ldblib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_ldblib.c$(DependSuffix): lua52/ldblib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_ldblib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_ldblib.c$(DependSuffix) -MM "lua52/ldblib.c"

$(IntermediateDirectory)/lua52_ldblib.c$(PreprocessSuffix): lua52/ldblib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_ldblib.c$(PreprocessSuffix) "lua52/ldblib.c"

$(IntermediateDirectory)/lua52_ldebug.c$(ObjectSuffix): lua52/ldebug.c $(IntermediateDirectory)/lua52_ldebug.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/ldebug.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_ldebug.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_ldebug.c$(DependSuffix): lua52/ldebug.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_ldebug.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_ldebug.c$(DependSuffix) -MM "lua52/ldebug.c"

$(IntermediateDirectory)/lua52_ldebug.c$(PreprocessSuffix): lua52/ldebug.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_ldebug.c$(PreprocessSuffix) "lua52/ldebug.c"

$(IntermediateDirectory)/lua52_ldo.c$(ObjectSuffix): lua52/ldo.c $(IntermediateDirectory)/lua52_ldo.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/ldo.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_ldo.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_ldo.c$(DependSuffix): lua52/ldo.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_ldo.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_ldo.c$(DependSuffix) -MM "lua52/ldo.c"

$(IntermediateDirectory)/lua52_ldo.c$(PreprocessSuffix): lua52/ldo.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_ldo.c$(PreprocessSuffix) "lua52/ldo.c"

$(IntermediateDirectory)/lua52_ldump.c$(ObjectSuffix): lua52/ldump.c $(IntermediateDirectory)/lua52_ldump.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/ldump.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_ldump.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_ldump.c$(DependSuffix): lua52/ldump.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_ldump.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_ldump.c$(DependSuffix) -MM "lua52/ldump.c"

$(IntermediateDirectory)/lua52_ldump.c$(PreprocessSuffix): lua52/ldump.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_ldump.c$(PreprocessSuffix) "lua52/ldump.c"

$(IntermediateDirectory)/lua52_lfunc.c$(ObjectSuffix): lua52/lfunc.c $(IntermediateDirectory)/lua52_lfunc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lfunc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lfunc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lfunc.c$(DependSuffix): lua52/lfunc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lfunc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lfunc.c$(DependSuffix) -MM "lua52/lfunc.c"

$(IntermediateDirectory)/lua52_lfunc.c$(PreprocessSuffix): lua52/lfunc.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lfunc.c$(PreprocessSuffix) "lua52/lfunc.c"

$(IntermediateDirectory)/lua52_lgc.c$(ObjectSuffix): lua52/lgc.c $(IntermediateDirectory)/lua52_lgc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lgc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lgc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lgc.c$(DependSuffix): lua52/lgc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lgc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lgc.c$(DependSuffix) -MM "lua52/lgc.c"

$(IntermediateDirectory)/lua52_lgc.c$(PreprocessSuffix): lua52/lgc.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lgc.c$(PreprocessSuffix) "lua52/lgc.c"

$(IntermediateDirectory)/lua52_linit.c$(ObjectSuffix): lua52/linit.c $(IntermediateDirectory)/lua52_linit.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/linit.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_linit.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_linit.c$(DependSuffix): lua52/linit.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_linit.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_linit.c$(DependSuffix) -MM "lua52/linit.c"

$(IntermediateDirectory)/lua52_linit.c$(PreprocessSuffix): lua52/linit.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_linit.c$(PreprocessSuffix) "lua52/linit.c"

$(IntermediateDirectory)/lua52_liolib.c$(ObjectSuffix): lua52/liolib.c $(IntermediateDirectory)/lua52_liolib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/liolib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_liolib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_liolib.c$(DependSuffix): lua52/liolib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_liolib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_liolib.c$(DependSuffix) -MM "lua52/liolib.c"

$(IntermediateDirectory)/lua52_liolib.c$(PreprocessSuffix): lua52/liolib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_liolib.c$(PreprocessSuffix) "lua52/liolib.c"

$(IntermediateDirectory)/lua52_llex.c$(ObjectSuffix): lua52/llex.c $(IntermediateDirectory)/lua52_llex.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/llex.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_llex.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_llex.c$(DependSuffix): lua52/llex.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_llex.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_llex.c$(DependSuffix) -MM "lua52/llex.c"

$(IntermediateDirectory)/lua52_llex.c$(PreprocessSuffix): lua52/llex.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_llex.c$(PreprocessSuffix) "lua52/llex.c"

$(IntermediateDirectory)/lua52_lmathlib.c$(ObjectSuffix): lua52/lmathlib.c $(IntermediateDirectory)/lua52_lmathlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lmathlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lmathlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lmathlib.c$(DependSuffix): lua52/lmathlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lmathlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lmathlib.c$(DependSuffix) -MM "lua52/lmathlib.c"

$(IntermediateDirectory)/lua52_lmathlib.c$(PreprocessSuffix): lua52/lmathlib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lmathlib.c$(PreprocessSuffix) "lua52/lmathlib.c"

$(IntermediateDirectory)/lua52_lmem.c$(ObjectSuffix): lua52/lmem.c $(IntermediateDirectory)/lua52_lmem.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lmem.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lmem.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lmem.c$(DependSuffix): lua52/lmem.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lmem.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lmem.c$(DependSuffix) -MM "lua52/lmem.c"

$(IntermediateDirectory)/lua52_lmem.c$(PreprocessSuffix): lua52/lmem.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lmem.c$(PreprocessSuffix) "lua52/lmem.c"

$(IntermediateDirectory)/lua52_loadlib.c$(ObjectSuffix): lua52/loadlib.c $(IntermediateDirectory)/lua52_loadlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/loadlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_loadlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_loadlib.c$(DependSuffix): lua52/loadlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_loadlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_loadlib.c$(DependSuffix) -MM "lua52/loadlib.c"

$(IntermediateDirectory)/lua52_loadlib.c$(PreprocessSuffix): lua52/loadlib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_loadlib.c$(PreprocessSuffix) "lua52/loadlib.c"

$(IntermediateDirectory)/lua52_lobject.c$(ObjectSuffix): lua52/lobject.c $(IntermediateDirectory)/lua52_lobject.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lobject.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lobject.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lobject.c$(DependSuffix): lua52/lobject.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lobject.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lobject.c$(DependSuffix) -MM "lua52/lobject.c"

$(IntermediateDirectory)/lua52_lobject.c$(PreprocessSuffix): lua52/lobject.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lobject.c$(PreprocessSuffix) "lua52/lobject.c"

$(IntermediateDirectory)/lua52_lopcodes.c$(ObjectSuffix): lua52/lopcodes.c $(IntermediateDirectory)/lua52_lopcodes.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lopcodes.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lopcodes.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lopcodes.c$(DependSuffix): lua52/lopcodes.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lopcodes.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lopcodes.c$(DependSuffix) -MM "lua52/lopcodes.c"

$(IntermediateDirectory)/lua52_lopcodes.c$(PreprocessSuffix): lua52/lopcodes.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lopcodes.c$(PreprocessSuffix) "lua52/lopcodes.c"

$(IntermediateDirectory)/lua52_loslib.c$(ObjectSuffix): lua52/loslib.c $(IntermediateDirectory)/lua52_loslib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/loslib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_loslib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_loslib.c$(DependSuffix): lua52/loslib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_loslib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_loslib.c$(DependSuffix) -MM "lua52/loslib.c"

$(IntermediateDirectory)/lua52_loslib.c$(PreprocessSuffix): lua52/loslib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_loslib.c$(PreprocessSuffix) "lua52/loslib.c"

$(IntermediateDirectory)/lua52_lparser.c$(ObjectSuffix): lua52/lparser.c $(IntermediateDirectory)/lua52_lparser.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lparser.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lparser.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lparser.c$(DependSuffix): lua52/lparser.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lparser.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lparser.c$(DependSuffix) -MM "lua52/lparser.c"

$(IntermediateDirectory)/lua52_lparser.c$(PreprocessSuffix): lua52/lparser.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lparser.c$(PreprocessSuffix) "lua52/lparser.c"

$(IntermediateDirectory)/lua52_lstate.c$(ObjectSuffix): lua52/lstate.c $(IntermediateDirectory)/lua52_lstate.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lstate.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lstate.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lstate.c$(DependSuffix): lua52/lstate.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lstate.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lstate.c$(DependSuffix) -MM "lua52/lstate.c"

$(IntermediateDirectory)/lua52_lstate.c$(PreprocessSuffix): lua52/lstate.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lstate.c$(PreprocessSuffix) "lua52/lstate.c"

$(IntermediateDirectory)/lua52_lstring.c$(ObjectSuffix): lua52/lstring.c $(IntermediateDirectory)/lua52_lstring.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lstring.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lstring.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lstring.c$(DependSuffix): lua52/lstring.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lstring.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lstring.c$(DependSuffix) -MM "lua52/lstring.c"

$(IntermediateDirectory)/lua52_lstring.c$(PreprocessSuffix): lua52/lstring.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lstring.c$(PreprocessSuffix) "lua52/lstring.c"

$(IntermediateDirectory)/lua52_lstrlib.c$(ObjectSuffix): lua52/lstrlib.c $(IntermediateDirectory)/lua52_lstrlib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lstrlib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lstrlib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lstrlib.c$(DependSuffix): lua52/lstrlib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lstrlib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lstrlib.c$(DependSuffix) -MM "lua52/lstrlib.c"

$(IntermediateDirectory)/lua52_lstrlib.c$(PreprocessSuffix): lua52/lstrlib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lstrlib.c$(PreprocessSuffix) "lua52/lstrlib.c"

$(IntermediateDirectory)/lua52_ltable.c$(ObjectSuffix): lua52/ltable.c $(IntermediateDirectory)/lua52_ltable.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/ltable.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_ltable.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_ltable.c$(DependSuffix): lua52/ltable.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_ltable.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_ltable.c$(DependSuffix) -MM "lua52/ltable.c"

$(IntermediateDirectory)/lua52_ltable.c$(PreprocessSuffix): lua52/ltable.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_ltable.c$(PreprocessSuffix) "lua52/ltable.c"

$(IntermediateDirectory)/lua52_ltablib.c$(ObjectSuffix): lua52/ltablib.c $(IntermediateDirectory)/lua52_ltablib.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/ltablib.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_ltablib.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_ltablib.c$(DependSuffix): lua52/ltablib.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_ltablib.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_ltablib.c$(DependSuffix) -MM "lua52/ltablib.c"

$(IntermediateDirectory)/lua52_ltablib.c$(PreprocessSuffix): lua52/ltablib.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_ltablib.c$(PreprocessSuffix) "lua52/ltablib.c"

$(IntermediateDirectory)/lua52_ltm.c$(ObjectSuffix): lua52/ltm.c $(IntermediateDirectory)/lua52_ltm.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/ltm.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_ltm.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_ltm.c$(DependSuffix): lua52/ltm.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_ltm.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_ltm.c$(DependSuffix) -MM "lua52/ltm.c"

$(IntermediateDirectory)/lua52_ltm.c$(PreprocessSuffix): lua52/ltm.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_ltm.c$(PreprocessSuffix) "lua52/ltm.c"

$(IntermediateDirectory)/lua52_lundump.c$(ObjectSuffix): lua52/lundump.c $(IntermediateDirectory)/lua52_lundump.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lundump.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lundump.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lundump.c$(DependSuffix): lua52/lundump.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lundump.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lundump.c$(DependSuffix) -MM "lua52/lundump.c"

$(IntermediateDirectory)/lua52_lundump.c$(PreprocessSuffix): lua52/lundump.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lundump.c$(PreprocessSuffix) "lua52/lundump.c"

$(IntermediateDirectory)/lua52_lvm.c$(ObjectSuffix): lua52/lvm.c $(IntermediateDirectory)/lua52_lvm.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lvm.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lvm.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lvm.c$(DependSuffix): lua52/lvm.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lvm.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lvm.c$(DependSuffix) -MM "lua52/lvm.c"

$(IntermediateDirectory)/lua52_lvm.c$(PreprocessSuffix): lua52/lvm.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lvm.c$(PreprocessSuffix) "lua52/lvm.c"

$(IntermediateDirectory)/lua52_lzio.c$(ObjectSuffix): lua52/lzio.c $(IntermediateDirectory)/lua52_lzio.c$(DependSuffix)
	$(CC) $(SourceSwitch) "G:/Git/Controlador/Controller/lua52/lzio.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lua52_lzio.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lua52_lzio.c$(DependSuffix): lua52/lzio.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lua52_lzio.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lua52_lzio.c$(DependSuffix) -MM "lua52/lzio.c"

$(IntermediateDirectory)/lua52_lzio.c$(PreprocessSuffix): lua52/lzio.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lua52_lzio.c$(PreprocessSuffix) "lua52/lzio.c"

$(IntermediateDirectory)/http_connection.cpp$(ObjectSuffix): http/connection.cpp $(IntermediateDirectory)/http_connection.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/http/connection.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/http_connection.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/http_connection.cpp$(DependSuffix): http/connection.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/http_connection.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/http_connection.cpp$(DependSuffix) -MM "http/connection.cpp"

$(IntermediateDirectory)/http_connection.cpp$(PreprocessSuffix): http/connection.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/http_connection.cpp$(PreprocessSuffix) "http/connection.cpp"

$(IntermediateDirectory)/http_connection_manager.cpp$(ObjectSuffix): http/connection_manager.cpp $(IntermediateDirectory)/http_connection_manager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/http/connection_manager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/http_connection_manager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/http_connection_manager.cpp$(DependSuffix): http/connection_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/http_connection_manager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/http_connection_manager.cpp$(DependSuffix) -MM "http/connection_manager.cpp"

$(IntermediateDirectory)/http_connection_manager.cpp$(PreprocessSuffix): http/connection_manager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/http_connection_manager.cpp$(PreprocessSuffix) "http/connection_manager.cpp"

$(IntermediateDirectory)/http_mime_types.cpp$(ObjectSuffix): http/mime_types.cpp $(IntermediateDirectory)/http_mime_types.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/http/mime_types.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/http_mime_types.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/http_mime_types.cpp$(DependSuffix): http/mime_types.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/http_mime_types.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/http_mime_types.cpp$(DependSuffix) -MM "http/mime_types.cpp"

$(IntermediateDirectory)/http_mime_types.cpp$(PreprocessSuffix): http/mime_types.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/http_mime_types.cpp$(PreprocessSuffix) "http/mime_types.cpp"

$(IntermediateDirectory)/http_reply.cpp$(ObjectSuffix): http/reply.cpp $(IntermediateDirectory)/http_reply.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/http/reply.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/http_reply.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/http_reply.cpp$(DependSuffix): http/reply.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/http_reply.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/http_reply.cpp$(DependSuffix) -MM "http/reply.cpp"

$(IntermediateDirectory)/http_reply.cpp$(PreprocessSuffix): http/reply.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/http_reply.cpp$(PreprocessSuffix) "http/reply.cpp"

$(IntermediateDirectory)/http_request_handler.cpp$(ObjectSuffix): http/request_handler.cpp $(IntermediateDirectory)/http_request_handler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/http/request_handler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/http_request_handler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/http_request_handler.cpp$(DependSuffix): http/request_handler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/http_request_handler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/http_request_handler.cpp$(DependSuffix) -MM "http/request_handler.cpp"

$(IntermediateDirectory)/http_request_handler.cpp$(PreprocessSuffix): http/request_handler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/http_request_handler.cpp$(PreprocessSuffix) "http/request_handler.cpp"

$(IntermediateDirectory)/http_request_parser.cpp$(ObjectSuffix): http/request_parser.cpp $(IntermediateDirectory)/http_request_parser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/http/request_parser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/http_request_parser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/http_request_parser.cpp$(DependSuffix): http/request_parser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/http_request_parser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/http_request_parser.cpp$(DependSuffix) -MM "http/request_parser.cpp"

$(IntermediateDirectory)/http_request_parser.cpp$(PreprocessSuffix): http/request_parser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/http_request_parser.cpp$(PreprocessSuffix) "http/request_parser.cpp"

$(IntermediateDirectory)/http_server.cpp$(ObjectSuffix): http/server.cpp $(IntermediateDirectory)/http_server.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/http/server.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/http_server.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/http_server.cpp$(DependSuffix): http/server.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/http_server.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/http_server.cpp$(DependSuffix) -MM "http/server.cpp"

$(IntermediateDirectory)/http_server.cpp$(PreprocessSuffix): http/server.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/http_server.cpp$(PreprocessSuffix) "http/server.cpp"

$(IntermediateDirectory)/http_authentication.cpp$(ObjectSuffix): http/authentication.cpp $(IntermediateDirectory)/http_authentication.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/http/authentication.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/http_authentication.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/http_authentication.cpp$(DependSuffix): http/authentication.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/http_authentication.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/http_authentication.cpp$(DependSuffix) -MM "http/authentication.cpp"

$(IntermediateDirectory)/http_authentication.cpp$(PreprocessSuffix): http/authentication.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/http_authentication.cpp$(PreprocessSuffix) "http/authentication.cpp"

$(IntermediateDirectory)/http_header_parser.cpp$(ObjectSuffix): http/header_parser.cpp $(IntermediateDirectory)/http_header_parser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/http/header_parser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/http_header_parser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/http_header_parser.cpp$(DependSuffix): http/header_parser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/http_header_parser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/http_header_parser.cpp$(DependSuffix) -MM "http/header_parser.cpp"

$(IntermediateDirectory)/http_header_parser.cpp$(PreprocessSuffix): http/header_parser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/http_header_parser.cpp$(PreprocessSuffix) "http/header_parser.cpp"

$(IntermediateDirectory)/http_request.cpp$(ObjectSuffix): http/request.cpp $(IntermediateDirectory)/http_request.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/http/request.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/http_request.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/http_request.cpp$(DependSuffix): http/request.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/http_request.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/http_request.cpp$(DependSuffix) -MM "http/request.cpp"

$(IntermediateDirectory)/http_request.cpp$(PreprocessSuffix): http/request.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/http_request.cpp$(PreprocessSuffix) "http/request.cpp"

$(IntermediateDirectory)/modbus_modbus.cpp$(ObjectSuffix): modbus/modbus.cpp $(IntermediateDirectory)/modbus_modbus.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/modbus/modbus.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/modbus_modbus.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/modbus_modbus.cpp$(DependSuffix): modbus/modbus.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/modbus_modbus.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/modbus_modbus.cpp$(DependSuffix) -MM "modbus/modbus.cpp"

$(IntermediateDirectory)/modbus_modbus.cpp$(PreprocessSuffix): modbus/modbus.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/modbus_modbus.cpp$(PreprocessSuffix) "modbus/modbus.cpp"

$(IntermediateDirectory)/modbus_modbus_connection.cpp$(ObjectSuffix): modbus/modbus_connection.cpp $(IntermediateDirectory)/modbus_modbus_connection.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/modbus/modbus_connection.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/modbus_modbus_connection.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/modbus_modbus_connection.cpp$(DependSuffix): modbus/modbus_connection.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/modbus_modbus_connection.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/modbus_modbus_connection.cpp$(DependSuffix) -MM "modbus/modbus_connection.cpp"

$(IntermediateDirectory)/modbus_modbus_connection.cpp$(PreprocessSuffix): modbus/modbus_connection.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/modbus_modbus_connection.cpp$(PreprocessSuffix) "modbus/modbus_connection.cpp"

$(IntermediateDirectory)/modbus_response.cpp$(ObjectSuffix): modbus/response.cpp $(IntermediateDirectory)/modbus_response.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/modbus/response.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/modbus_response.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/modbus_response.cpp$(DependSuffix): modbus/response.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/modbus_response.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/modbus_response.cpp$(DependSuffix) -MM "modbus/response.cpp"

$(IntermediateDirectory)/modbus_response.cpp$(PreprocessSuffix): modbus/response.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/modbus_response.cpp$(PreprocessSuffix) "modbus/response.cpp"

$(IntermediateDirectory)/modbus_read_coils_response.cpp$(ObjectSuffix): modbus/read_coils_response.cpp $(IntermediateDirectory)/modbus_read_coils_response.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/modbus/read_coils_response.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/modbus_read_coils_response.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/modbus_read_coils_response.cpp$(DependSuffix): modbus/read_coils_response.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/modbus_read_coils_response.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/modbus_read_coils_response.cpp$(DependSuffix) -MM "modbus/read_coils_response.cpp"

$(IntermediateDirectory)/modbus_read_coils_response.cpp$(PreprocessSuffix): modbus/read_coils_response.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/modbus_read_coils_response.cpp$(PreprocessSuffix) "modbus/read_coils_response.cpp"

$(IntermediateDirectory)/modbus_read_discrete_inputs.cpp$(ObjectSuffix): modbus/read_discrete_inputs.cpp $(IntermediateDirectory)/modbus_read_discrete_inputs.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/modbus/read_discrete_inputs.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/modbus_read_discrete_inputs.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/modbus_read_discrete_inputs.cpp$(DependSuffix): modbus/read_discrete_inputs.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/modbus_read_discrete_inputs.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/modbus_read_discrete_inputs.cpp$(DependSuffix) -MM "modbus/read_discrete_inputs.cpp"

$(IntermediateDirectory)/modbus_read_discrete_inputs.cpp$(PreprocessSuffix): modbus/read_discrete_inputs.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/modbus_read_discrete_inputs.cpp$(PreprocessSuffix) "modbus/read_discrete_inputs.cpp"

$(IntermediateDirectory)/modbus_read_holding_registers.cpp$(ObjectSuffix): modbus/read_holding_registers.cpp $(IntermediateDirectory)/modbus_read_holding_registers.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/modbus/read_holding_registers.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/modbus_read_holding_registers.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/modbus_read_holding_registers.cpp$(DependSuffix): modbus/read_holding_registers.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/modbus_read_holding_registers.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/modbus_read_holding_registers.cpp$(DependSuffix) -MM "modbus/read_holding_registers.cpp"

$(IntermediateDirectory)/modbus_read_holding_registers.cpp$(PreprocessSuffix): modbus/read_holding_registers.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/modbus_read_holding_registers.cpp$(PreprocessSuffix) "modbus/read_holding_registers.cpp"

$(IntermediateDirectory)/modbus_read_input_registers.cpp$(ObjectSuffix): modbus/read_input_registers.cpp $(IntermediateDirectory)/modbus_read_input_registers.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/modbus/read_input_registers.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/modbus_read_input_registers.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/modbus_read_input_registers.cpp$(DependSuffix): modbus/read_input_registers.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/modbus_read_input_registers.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/modbus_read_input_registers.cpp$(DependSuffix) -MM "modbus/read_input_registers.cpp"

$(IntermediateDirectory)/modbus_read_input_registers.cpp$(PreprocessSuffix): modbus/read_input_registers.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/modbus_read_input_registers.cpp$(PreprocessSuffix) "modbus/read_input_registers.cpp"

$(IntermediateDirectory)/modbus_handler.cpp$(ObjectSuffix): modbus/handler.cpp $(IntermediateDirectory)/modbus_handler.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/modbus/handler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/modbus_handler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/modbus_handler.cpp$(DependSuffix): modbus/handler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/modbus_handler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/modbus_handler.cpp$(DependSuffix) -MM "modbus/handler.cpp"

$(IntermediateDirectory)/modbus_handler.cpp$(PreprocessSuffix): modbus/handler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/modbus_handler.cpp$(PreprocessSuffix) "modbus/handler.cpp"

$(IntermediateDirectory)/modbus_read_register.cpp$(ObjectSuffix): modbus/read_register.cpp $(IntermediateDirectory)/modbus_read_register.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/modbus/read_register.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/modbus_read_register.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/modbus_read_register.cpp$(DependSuffix): modbus/read_register.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/modbus_read_register.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/modbus_read_register.cpp$(DependSuffix) -MM "modbus/read_register.cpp"

$(IntermediateDirectory)/modbus_read_register.cpp$(PreprocessSuffix): modbus/read_register.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/modbus_read_register.cpp$(PreprocessSuffix) "modbus/read_register.cpp"

$(IntermediateDirectory)/modbus_write_register.cpp$(ObjectSuffix): modbus/write_register.cpp $(IntermediateDirectory)/modbus_write_register.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/modbus/write_register.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/modbus_write_register.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/modbus_write_register.cpp$(DependSuffix): modbus/write_register.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/modbus_write_register.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/modbus_write_register.cpp$(DependSuffix) -MM "modbus/write_register.cpp"

$(IntermediateDirectory)/modbus_write_register.cpp$(PreprocessSuffix): modbus/write_register.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/modbus_write_register.cpp$(PreprocessSuffix) "modbus/write_register.cpp"

$(IntermediateDirectory)/modbus_write_single_coil.cpp$(ObjectSuffix): modbus/write_single_coil.cpp $(IntermediateDirectory)/modbus_write_single_coil.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Git/Controlador/Controller/modbus/write_single_coil.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/modbus_write_single_coil.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/modbus_write_single_coil.cpp$(DependSuffix): modbus/write_single_coil.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/modbus_write_single_coil.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/modbus_write_single_coil.cpp$(DependSuffix) -MM "modbus/write_single_coil.cpp"

$(IntermediateDirectory)/modbus_write_single_coil.cpp$(PreprocessSuffix): modbus/write_single_coil.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/modbus_write_single_coil.cpp$(PreprocessSuffix) "modbus/write_single_coil.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Release/*$(ObjectSuffix)
	$(RM) ./Release/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../.build-release/Controller"


