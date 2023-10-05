# Alternative GNU Make project makefile autogenerated by Premake

CC=arm-vita-eabi-gcc
CXX=arm-vita-eabi-g++

CFLAGS=-fno-strict-aliasing -fomit-frame-pointer -ffunction-sections -fno-lto -fno-optimize-sibling-calls -Wl,-q,--allow-multiple-definition
CXXFLAGS=$(CFLAGS)
LDFLAGS=$(CFLAGS)

ifndef config
  config=debug_vita
endif

ifndef verbose
  SILENT = @
endif

.PHONY: clean prebuild

SHELLTYPE := posix
ifeq (.exe,$(findstring .exe,$(ComSpec)))
	SHELLTYPE := msdos
endif

# Configurations
# #############################################

RESCOMP = windres
INCLUDES += -I../dependencies/SDL2/include -I../dependencies/openal-soft/include -I../PsyCross/include -I${VITASDK}/arm-vita-eabi/include/SDL2
FORCE_INCLUDE +=
ALL_CPPFLAGS += $(CPPFLAGS) -MD -MP $(DEFINES) $(INCLUDES) -D__vita__
ALL_RESFLAGS += $(RESFLAGS) $(DEFINES) $(INCLUDES)
LIBS += -lopenal -lSDL2 -lvitaGL -lvitashark -lSceShaccCgExt -ltaihen_stub -lmathneon -lpthread -lSceShaccCg_stub -lSceSysmodule_stub -lSceKernelDmacMgr_stub -lSceGxm_stub_weak -lSceTouch_stub_weak -lSceHid_stub_weak -lSceDisplay_stub_weak -lSceCommonDialog_stub_weak -lSceMotion_stub_weak -lSceCtrl_stub_weak -lSceAudio_stub_weak -lSceAudioIn_stub_weak -lSceIme_stub_weak -lScePower_stub_weak -lSceAppUtil_stub_weak -lSceAppMgr_stub_weak
LDDEPS +=
LINKCMD = $(AR) -rcs "$@" $(OBJECTS)
define PREBUILDCMDS
endef
define PRELINKCMDS
endef
define POSTBUILDCMDS
endef

ifeq ($(config),debug_vita)
TARGETDIR = ../bin/Debug
TARGET = $(TARGETDIR)/libPsyCross.a
OBJDIR = obj/vita/Debug/PsyCross
DEFINES += -D_DEBUG -DDEBUG -DNTSC_VERSION
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS)  -g -O0 -Wno-narrowing -Wno-endif-labels -Wno-write-strings -Wno-format-security -Wno-unused-result -fpermissive
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS)  -g -O0 -std=c++11 -Wno-narrowing -Wno-endif-labels -Wno-write-strings -Wno-format-security -Wno-unused-result -fpermissive
ALL_LDFLAGS += $(LDFLAGS) -L${VITASDK}/arm-vita-eabi/lib

else ifeq ($(config),release_vita)
TARGETDIR = ../bin/Release
TARGET = $(TARGETDIR)/libPsyCross.a
OBJDIR = obj/vita/Release/PsyCross
DEFINES += -DNDEBUG -DNTSC_VERSION
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS)  -O3 -Wno-narrowing -Wno-endif-labels -Wno-write-strings -Wno-format-security -Wno-unused-result -fpermissive
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS)  -O3 -std=c++11 -Wno-narrowing -Wno-endif-labels -Wno-write-strings -Wno-format-security -Wno-unused-result -fpermissive
ALL_LDFLAGS += $(LDFLAGS) -L${VITASDK}/arm-vita-eabi/lib

else ifeq ($(config),release_dev_vita)
TARGETDIR = ../bin/Release_dev
TARGET = $(TARGETDIR)/libPsyCross.a
OBJDIR = obj/vita/Release_dev/PsyCross
DEFINES += -DNDEBUG -DNTSC_VERSION
ALL_CFLAGS += $(CFLAGS) $(ALL_CPPFLAGS)  -O3 -Wno-narrowing -Wno-endif-labels -Wno-write-strings -Wno-format-security -Wno-unused-result -fpermissive
ALL_CXXFLAGS += $(CXXFLAGS) $(ALL_CPPFLAGS)  -O3 -std=c++11 -Wno-narrowing -Wno-endif-labels -Wno-write-strings -Wno-format-security -Wno-unused-result -fpermissive
ALL_LDFLAGS += $(LDFLAGS) -L${VITASDK}/arm-vita-eabi/lib

endif

# Per File Configurations
# #############################################


# File sets
# #############################################

GENERATED :=
OBJECTS :=

GENERATED += $(OBJDIR)/ABS.o
GENERATED += $(OBJDIR)/INLINE_C.o
GENERATED += $(OBJDIR)/LIBAPI.o
GENERATED += $(OBJDIR)/LIBCD.o
GENERATED += $(OBJDIR)/LIBETC.o
GENERATED += $(OBJDIR)/LIBGPU.o
GENERATED += $(OBJDIR)/LIBGTE.o
GENERATED += $(OBJDIR)/LIBMCRD.o
GENERATED += $(OBJDIR)/LIBPAD.o
GENERATED += $(OBJDIR)/LIBSN.o
GENERATED += $(OBJDIR)/LIBSPU.o
GENERATED += $(OBJDIR)/PsyX_GPU.o
GENERATED += $(OBJDIR)/PsyX_GTE.o
GENERATED += $(OBJDIR)/PsyX_main.o
GENERATED += $(OBJDIR)/PsyX_pad.o
GENERATED += $(OBJDIR)/PsyX_render.o
GENERATED += $(OBJDIR)/crash_handler.o
GENERATED += $(OBJDIR)/glad.o
GENERATED += $(OBJDIR)/half_float.o
GENERATED += $(OBJDIR)/timer.o
OBJECTS += $(OBJDIR)/ABS.o
OBJECTS += $(OBJDIR)/INLINE_C.o
OBJECTS += $(OBJDIR)/LIBAPI.o
OBJECTS += $(OBJDIR)/LIBCD.o
OBJECTS += $(OBJDIR)/LIBETC.o
OBJECTS += $(OBJDIR)/LIBGPU.o
OBJECTS += $(OBJDIR)/LIBGTE.o
OBJECTS += $(OBJDIR)/LIBMCRD.o
OBJECTS += $(OBJDIR)/LIBPAD.o
OBJECTS += $(OBJDIR)/LIBSN.o
OBJECTS += $(OBJDIR)/LIBSPU.o
OBJECTS += $(OBJDIR)/PsyX_GPU.o
OBJECTS += $(OBJDIR)/PsyX_GTE.o
OBJECTS += $(OBJDIR)/PsyX_main.o
OBJECTS += $(OBJDIR)/PsyX_pad.o
OBJECTS += $(OBJDIR)/PsyX_render.o
OBJECTS += $(OBJDIR)/crash_handler.o
OBJECTS += $(OBJDIR)/glad.o
OBJECTS += $(OBJDIR)/half_float.o
OBJECTS += $(OBJDIR)/timer.o

# Rules
# #############################################

all: $(TARGET)
	@:

$(TARGET): $(GENERATED) $(OBJECTS) $(LDDEPS) | $(TARGETDIR)
	$(PRELINKCMDS)
	@echo Linking PsyCross
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning PsyCross
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(GENERATED)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(GENERATED)) del /s /q $(subst /,\\,$(GENERATED))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild: | $(OBJDIR)
	$(PREBUILDCMDS)

ifneq (,$(PCH))
$(OBJECTS): $(GCH) | $(PCH_PLACEHOLDER)
$(GCH): $(PCH) | prebuild
	@echo $(notdir $<)
	$(SILENT) $(CXX) -x c++-header $(ALL_CXXFLAGS) -o "$@" -MF "$(@:%.gch=%.d)" -c "$<"
$(PCH_PLACEHOLDER): $(GCH) | $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) touch "$@"
else
	$(SILENT) echo $null >> "$@"
endif
else
$(OBJECTS): | prebuild
endif


# File Rules
# #############################################

$(OBJDIR)/PsyX_main.o: ../PsyCross/src/PsyX_main.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/PsyX_GPU.o: ../PsyCross/src/gpu/PsyX_GPU.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/PsyX_GTE.o: ../PsyCross/src/gte/PsyX_GTE.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/half_float.o: ../PsyCross/src/gte/half_float.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/PsyX_pad.o: ../PsyCross/src/pad/PsyX_pad.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/ABS.o: ../PsyCross/src/psx/ABS.C
	@echo "$(notdir $<)"
	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/INLINE_C.o: ../PsyCross/src/psx/INLINE_C.C
	@echo "$(notdir $<)"
	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LIBAPI.o: ../PsyCross/src/psx/LIBAPI.C
	@echo "$(notdir $<)"
	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LIBCD.o: ../PsyCross/src/psx/LIBCD.C
	@echo "$(notdir $<)"
	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LIBETC.o: ../PsyCross/src/psx/LIBETC.C
	@echo "$(notdir $<)"
	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LIBGPU.o: ../PsyCross/src/psx/LIBGPU.C
	@echo "$(notdir $<)"
	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LIBGTE.o: ../PsyCross/src/psx/LIBGTE.C
	@echo "$(notdir $<)"
	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LIBMCRD.o: ../PsyCross/src/psx/LIBMCRD.C
	@echo "$(notdir $<)"
	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LIBPAD.o: ../PsyCross/src/psx/LIBPAD.C
	@echo "$(notdir $<)"
	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LIBSN.o: ../PsyCross/src/psx/LIBSN.C
	@echo "$(notdir $<)"
	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/LIBSPU.o: ../PsyCross/src/psx/LIBSPU.C
	@echo "$(notdir $<)"
	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/PsyX_render.o: ../PsyCross/src/render/PsyX_render.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/glad.o: ../PsyCross/src/render/glad.c
	@echo "$(notdir $<)"
	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/crash_handler.o: ../PsyCross/src/util/crash_handler.cpp
	@echo "$(notdir $<)"
	$(SILENT) $(CXX) $(ALL_CXXFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"
$(OBJDIR)/timer.o: ../PsyCross/src/util/timer.c
	@echo "$(notdir $<)"
	$(SILENT) $(CC) $(ALL_CFLAGS) $(FORCE_INCLUDE) -o "$@" -MF "$(@:%.o=%.d)" -c "$<"

-include $(OBJECTS:%.o=%.d)
ifneq (,$(PCH))
  -include $(PCH_PLACEHOLDER).d
endif
