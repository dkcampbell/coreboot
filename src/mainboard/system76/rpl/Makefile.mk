## SPDX-License-Identifier: GPL-2.0-only

CPPFLAGS_common += -I$(src)/mainboard/$(MAINBOARDDIR)/include

ifeq ($(CONFIG_DRIVERS_GFX_NVIDIA),y)
CPPFLAGS_common += -I$(src)/mainboard/$(MAINBOARDDIR)/variants/$(VARIANT_DIR)/include
endif

bootblock-y += bootblock.c
bootblock-y += variants/$(VARIANT_DIR)/gpio_early.c

romstage-y += variants/$(VARIANT_DIR)/romstage.c

ramstage-y += ramstage.c
ramstage-y += variants/$(VARIANT_DIR)/hda_verb.c
ramstage-y += variants/$(VARIANT_DIR)/gpio.c

SPD_SOURCES = samsung-M425R1GB4BB0-CQKOD
