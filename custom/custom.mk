
GEN_CSRCS += $(notdir $(wildcard $(PRJ_DIR)/custom/*.c))

CPPSRCS += lvglGaussian.cpp
CPPSRCS += custom.cpp

DEPPATH += --dep-path $(PRJ_DIR)/custom
VPATH += :$(PRJ_DIR)/custom

CFLAGS += "-I$(PRJ_DIR)/custom"

