EE_SRC_DIR = src/
EE_OBJS_DIR = obj/
EE_LIB_DIR = lib/

EE_INCS += -I./include -I$(EE_SRC_DIR)

EE_LIB = $(EE_LIB_DIR)libdlsp.a
EE_OBJS = functions.o interop.o math.o pad.o cheats.o moby.o game.o \
			gamesettings.o weapon.o hud.o player.o team.o math3d.o dl.o \
			spawnpoint.o dialog.o map.o graphics.o \
			sifrpc.o mc.o ui.o guber.o color.o \
			music.o collision.o utils.o camera.o sound.o

EE_OBJS := $(EE_OBJS:%=$(EE_OBJS_DIR)%)

all: $(EE_OBJS_DIR) $(EE_LIB_DIR) $(EE_LIB)

$(EE_OBJS_DIR):
	mkdir -p $(EE_OBJS_DIR)

$(EE_LIB_DIR):
	mkdir -p $(EE_LIB_DIR)

$(EE_OBJS_DIR)%.o : $(EE_SRC_DIR)%.c
	$(EE_C_COMPILE) -c $< -o $@

$(EE_OBJS_DIR)%.o : $(EE_SRC_DIR)%.S
	$(EE_C_COMPILE) -c $< -o $@

install: all
	mkdir -p $(DESTDIR)$(PS2SDK)/ports/include/libdlsp
	mkdir -p $(DESTDIR)$(PS2SDK)/ports/lib
	cp -f $(EE_LIB) $(DESTDIR)$(PS2SDK)/ports/lib
	cp -f include/*.h $(DESTDIR)$(PS2SDK)/ports/include/libdlsp

clean:
	rm -f -r $(EE_OBJS_DIR)
	rm -f -r $(EE_LIB_DIR)

sample:

include $(PS2SDK)/samples/Makefile.pref
include Makefile.eeglobal
