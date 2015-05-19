ARCH ?= x86
TARGET ?= i586-elf

MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
SRC_DIR := $(shell cd $(shell dirname $(MAKEFILE_PATH)); pwd -P)

TOOLS_DIR := $(shell cd $(SRC_DIR)/../tools; pwd -P)
TOOLS_BINUTILS := $(TOOLS_DIR)/$(TARGET)/binutils/bin

RUSTC ?= rustc
LD := $(TOOLS_BINUTILS)/$(TARGET)-ld
AS := $(TOOLS_BINUTILS)/$(TARGET)-as
OBJDUMP := $(TOOLS_BINUTILS)/$(TARGET)-objdump
OBJCOPY := $(TOOLS_BINUTILS)/$(TARGET)-objcopy

OBJDIR_ROOT := $(SRC_DIR)/obj
OBJDIR := $(OBJDIR_ROOT)/$(ARCH)

LINKSCRIPT := arch/$(ARCH)/link.ld
LINKFLAGS := -T $(LINKSCRIPT)
LINKFLAGS += -Map $(OBJDIR)/map.txt
LINKFLAGS += --gc-sections
LINKFLAGS += -z max-page-size=0x1000

BIN := $(SRC_DIR)/../kernel.$(ARCH).bin
OBJS := boot.o
OBJS := $(OBJS:%=$(OBJDIR)/%)

.PHONY: all clean

all: $(BIN)
	@echo $(SRC_DIR)
	@echo $(TOOLS_DIR)
	@echo $(TOOLS_BINUTILS)

clean:
	@echo cleaning
	$(RM) -rf $(OBJDIR_ROOT)

$(BIN): $(OBJS)
	$(LD) -o $@ $(LINKFLAGS) $(OBJS)
	$(OBJDUMP) -S $@ > $@.dsm

$(OBJDIR)/boot.o: arch/$(ARCH)/boot.S
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<