# alternative layout options

ifneq ($(strip $(NAMERAKA_ALPHAS)),)
  OPT_DEFS += -DNAMERAKA_ALPHAS_$(NAMERAKA_ALPHAS)
endif

ifneq ($(strip $(NAMERAKA_EXTRA)),)
  OPT_DEFS += -DNAMERAKA_EXTRA_$(NAMERAKA_EXTRA)
endif

ifneq ($(strip $(NAMERAKA_TAP)),)
  OPT_DEFS += -DNAMERAKA_TAP_$(NAMERAKA_TAP)
endif

ifneq ($(strip $(NAMERAKA_NAV)),)
  OPT_DEFS += -DNAMERAKA_NAV_$(NAMERAKA_NAV)
endif

ifneq ($(strip $(NAMERAKA_CLIPBOARD)),)
  OPT_DEFS += -DNAMERAKA_CLIPBOARD_$(NAMERAKA_CLIPBOARD)
endif

ifneq ($(strip $(NAMERAKA_LAYERS)),)
  OPT_DEFS += -DNAMERAKA_LAYERS_$(NAMERAKA_LAYERS)
endif


ifneq ($(strip $(NAMERAKA_KEYMAP)),)
  OPT_DEFS += -DNAMERAKA_KEYMAP_$(NAMERAKA_KEYMAP)
endif

# subset mappings

ifneq ($(strip $(NAMERAKA_MAPPING)),)
  OPT_DEFS += -DNAMERAKA_MAPPING_$(NAMERAKA_MAPPING)
endif

# kludges

# thumb combos
ifeq ($(strip $(NAMERAKA_KLUDGE_THUMBCOMBOS)),yes)
  COMBO_ENABLE = yes
  OPT_DEFS += -DNAMERAKA_KLUDGE_THUMBCOMBOS
endif
