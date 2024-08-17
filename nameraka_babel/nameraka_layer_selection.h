#pragma once

#include "../../../quantum/keymap_extras/keymap_nordic.h"
#if defined(NAMERAKA_KEYMAP_MACOS)
#include "../../../quantum/keymap_extras/keymap_swedish_mac_ansi.h"
#else
#include "../../../quantum/keymap_extras/keymap_swedish.h"
#endif
#include "nameraka_layer_alternatives.h"

#if !defined(NAMERAKA_LAYER_BASE)
  #if defined (NAMERAKA_LAYERS_FLIP)
    #if defined (NAMERAKA_ALPHAS_AZERTY)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_AZERTY_FLIP
    #elif defined (NAMERAKA_ALPHAS_BEAKL15)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_BEAKL15_FLIP
    #elif defined (NAMERAKA_ALPHAS_COLEMAK)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_COLEMAK_FLIP
    #elif defined (NAMERAKA_ALPHAS_COLEMAKDH)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_COLEMAKDH_FLIP
    #elif defined (NAMERAKA_ALPHAS_COLEMAKDHK)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_COLEMAKDHK_FLIP
    #elif defined (NAMERAKA_ALPHAS_DVORAK)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_DVORAK_FLIP
    #elif defined (NAMERAKA_ALPHAS_HALMAK)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_HALMAK_FLIP
    #elif defined (NAMERAKA_ALPHAS_WORKMAN)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_WORKMAN_FLIP
    #elif defined (NAMERAKA_ALPHAS_QWERTY)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_QWERTY_FLIP
    #elif defined (NAMERAKA_ALPHAS_QWERTZ)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_QWERTZ_FLIP
    #else
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_COLEMAKDH_FLIP
    #endif
  #else
    #if defined (NAMERAKA_ALPHAS_AZERTY)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_AZERTY
    #elif defined (NAMERAKA_ALPHAS_BEAKL15)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_BEAKL15
    #elif defined (NAMERAKA_ALPHAS_COLEMAK)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_COLEMAK
    #elif defined (NAMERAKA_ALPHAS_COLEMAKDH)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_COLEMAKDH
    #elif defined (NAMERAKA_ALPHAS_COLEMAKDHK)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_COLEMAKDHK
    #elif defined (NAMERAKA_ALPHAS_DVORAK)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_DVORAK
    #elif defined (NAMERAKA_ALPHAS_HALMAK)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_HALMAK
    #elif defined (NAMERAKA_ALPHAS_WORKMAN)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_WORKMAN
    #elif defined (NAMERAKA_ALPHAS_QWERTY)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_QWERTY
    #elif defined (NAMERAKA_ALPHAS_QWERTZ)
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_QWERTZ
    #else
      #define NAMERAKA_LAYER_BASE NAMERAKA_ALTERNATIVES_BASE_COLEMAKDH
    #endif
  #endif
#endif
#if !defined(NAMERAKA_LAYERMAPPING_BASE)
  #define NAMERAKA_LAYERMAPPING_BASE NAMERAKA_MAPPING
#endif

#if !defined(NAMERAKA_LAYER_EXTRA)
  #if defined (NAMERAKA_LAYERS_FLIP)
    #if defined (NAMERAKA_EXTRA_AZERTY)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_AZERTY_FLIP
    #elif defined (NAMERAKA_EXTRA_BEAKL15)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_BEAKL15_FLIP
    #elif defined (NAMERAKA_EXTRA_COLEMAK)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_COLEMAK_FLIP
    #elif defined (NAMERAKA_EXTRA_COLEMAKDH)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_COLEMAKDH_FLIP
    #elif defined (NAMERAKA_EXTRA_COLEMAKDHK)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_COLEMAKDHK_FLIP
    #elif defined (NAMERAKA_EXTRA_DVORAK)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_DVORAK_FLIP
    #elif defined (NAMERAKA_EXTRA_HALMAK)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_HALMAK_FLIP
    #elif defined (NAMERAKA_EXTRA_WORKMAN)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_WORKMAN_FLIP
    #elif defined (NAMERAKA_EXTRA_QWERTY)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_QWERTY_FLIP
    #elif defined (NAMERAKA_EXTRA_QWERTZ)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_QWERTZ_FLIP
    #else
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_QWERTY_FLIP
    #endif
  #else
    #if defined (NAMERAKA_EXTRA_AZERTY)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_AZERTY
    #elif defined (NAMERAKA_EXTRA_BEAKL15)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_BEAKL15
    #elif defined (NAMERAKA_EXTRA_COLEMAK)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_COLEMAK
    #elif defined (NAMERAKA_EXTRA_COLEMAKDH)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_COLEMAKDH
    #elif defined (NAMERAKA_EXTRA_COLEMAKDHK)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_COLEMAKDHK
    #elif defined (NAMERAKA_EXTRA_DVORAK)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_DVORAK
    #elif defined (NAMERAKA_EXTRA_HALMAK)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_HALMAK
    #elif defined (NAMERAKA_EXTRA_WORKMAN)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_WORKMAN
    #elif defined (NAMERAKA_EXTRA_QWERTY)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_QWERTY
    #elif defined (NAMERAKA_EXTRA_QWERTZ)
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_QWERTZ
    #else
      #define NAMERAKA_LAYER_EXTRA NAMERAKA_ALTERNATIVES_BASE_QWERTY
    #endif
  #endif
#endif
#if !defined(NAMERAKA_LAYERMAPPING_EXTRA)
  #define NAMERAKA_LAYERMAPPING_EXTRA NAMERAKA_MAPPING
#endif

#if !defined(NAMERAKA_LAYER_TAP)
  #if defined (NAMERAKA_LAYERS_FLIP)
    #if defined (NAMERAKA_TAP_AZERTY)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_AZERTY_FLIP
    #elif defined (NAMERAKA_TAP_BEAKL15)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_BEAKL15_FLIP
    #elif defined (NAMERAKA_TAP_COLEMAK)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_COLEMAK_FLIP
    #elif defined (NAMERAKA_TAP_COLEMAKDH)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_COLEMAKDH_FLIP
    #elif defined (NAMERAKA_TAP_COLEMAKDHK)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_COLEMAKDHK_FLIP
    #elif defined (NAMERAKA_TAP_DVORAK)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_DVORAK_FLIP
    #elif defined (NAMERAKA_TAP_HALMAK)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_HALMAK_FLIP
    #elif defined (NAMERAKA_TAP_WORKMAN)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_WORKMAN_FLIP
    #elif defined (NAMERAKA_TAP_QWERTY)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_QWERTY_FLIP
    #elif defined (NAMERAKA_TAP_QWERTZ)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_QWERTZ_FLIP
    #else
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_COLEMAKDH_FLIP
    #endif
  #else
    #if defined (NAMERAKA_TAP_AZERTY)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_AZERTY
    #elif defined (NAMERAKA_TAP_BEAKL15)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_BEAKL15
    #elif defined (NAMERAKA_TAP_COLEMAK)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_COLEMAK
    #elif defined (NAMERAKA_TAP_COLEMAKDH)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_COLEMAKDH
    #elif defined (NAMERAKA_TAP_COLEMAKDHK)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_COLEMAKDHK
    #elif defined (NAMERAKA_TAP_DVORAK)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_DVORAK
    #elif defined (NAMERAKA_TAP_HALMAK)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_HALMAK
    #elif defined (NAMERAKA_TAP_WORKMAN)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_WORKMAN
    #elif defined (NAMERAKA_TAP_QWERTY)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_QWERTY
    #elif defined (NAMERAKA_TAP_QWERTZ)
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_QWERTZ
    #else
      #define NAMERAKA_LAYER_TAP NAMERAKA_ALTERNATIVES_TAP_COLEMAKDH
    #endif
  #endif
#endif
#if !defined(NAMERAKA_LAYERMAPPING_TAP)
  #define NAMERAKA_LAYERMAPPING_TAP NAMERAKA_MAPPING
#endif

#if !defined(NAMERAKA_LAYER_BUTTON)
  #define NAMERAKA_LAYER_BUTTON NAMERAKA_ALTERNATIVES_BUTTON
#endif
#if !defined(NAMERAKA_LAYERMAPPING_BUTTON)
  #define NAMERAKA_LAYERMAPPING_BUTTON NAMERAKA_MAPPING
#endif

#if !defined(NAMERAKA_LAYER_NAV)
  #if defined (NAMERAKA_LAYERS_FLIP)
    #if defined (NAMERAKA_NAV_INVERTEDT)
      #define NAMERAKA_LAYER_NAV NAMERAKA_ALTERNATIVES_NAV_INVERTEDT_FLIP
    #else
      #define NAMERAKA_LAYER_NAV NAMERAKA_ALTERNATIVES_NAV_FLIP
    #endif
  #else
    #if defined (NAMERAKA_NAV_INVERTEDT)
      #define NAMERAKA_LAYER_NAV NAMERAKA_ALTERNATIVES_NAV_INVERTEDT
    #elif defined (NAMERAKA_NAV_VI)
      #define NAMERAKA_LAYER_NAV NAMERAKA_ALTERNATIVES_NAV_VI
    #else
      #define NAMERAKA_LAYER_NAV NAMERAKA_ALTERNATIVES_NAV
    #endif
  #endif
#endif
#if !defined(NAMERAKA_LAYERMAPPING_NAV)
  #define NAMERAKA_LAYERMAPPING_NAV NAMERAKA_MAPPING
#endif

#if !defined(NAMERAKA_LAYER_PROJECT)
  #if defined (NAMERAKA_LAYERS_FLIP)
    #if defined (NAMERAKA_NAV_INVERTEDT)
      #define NAMERAKA_LAYER_PROJECT NAMERAKA_ALTERNATIVES_PROJECT_INVERTEDT_FLIP
    #else
      #define NAMERAKA_LAYER_PROJECT NAMERAKA_ALTERNATIVES_PROJECT_FLIP
    #endif
  #else
    #if defined (NAMERAKA_NAV_INVERTEDT)
      #define NAMERAKA_LAYER_PROJECT NAMERAKA_ALTERNATIVES_PROJECT_INVERTEDT
    #elif defined (NAMERAKA_NAV_VI)
      #define NAMERAKA_LAYER_PROJECT NAMERAKA_ALTERNATIVES_PROJECT_VI
    #else
      #define NAMERAKA_LAYER_PROJECT NAMERAKA_ALTERNATIVES_PROJECT
    #endif
  #endif
#endif
#if !defined(NAMERAKA_LAYERMAPPING_PROJECT)
  #define NAMERAKA_LAYERMAPPING_PROJECT NAMERAKA_MAPPING
#endif

#if !defined(NAMERAKA_LAYER_MEDIA)
  #if defined (NAMERAKA_LAYERS_FLIP)
    #if defined (NAMERAKA_NAV_INVERTEDT)
      #define NAMERAKA_LAYER_MEDIA NAMERAKA_ALTERNATIVES_MEDIA_INVERTEDT_FLIP
    #else
      #define NAMERAKA_LAYER_MEDIA NAMERAKA_ALTERNATIVES_MEDIA_FLIP
    #endif
  #else
    #if defined (NAMERAKA_NAV_INVERTEDT)
      #define NAMERAKA_LAYER_MEDIA NAMERAKA_ALTERNATIVES_MEDIA_INVERTEDT
    #elif defined (NAMERAKA_NAV_VI)
      #define NAMERAKA_LAYER_MEDIA NAMERAKA_ALTERNATIVES_MEDIA_VI
    #else
      #define NAMERAKA_LAYER_MEDIA NAMERAKA_ALTERNATIVES_MEDIA
    #endif
  #endif
#endif
#if !defined(NAMERAKA_LAYERMAPPING_MEDIA)
  #define NAMERAKA_LAYERMAPPING_MEDIA NAMERAKA_MAPPING
#endif

#if !defined(NAMERAKA_LAYER_NUM)
  #if defined (NAMERAKA_LAYERS_FLIP)
    #define NAMERAKA_LAYER_NUM NAMERAKA_ALTERNATIVES_NUM_FLIP
  #else
    #define NAMERAKA_LAYER_NUM NAMERAKA_ALTERNATIVES_NUM
  #endif
#endif
#if !defined(NAMERAKA_LAYERMAPPING_NUM)
  #define NAMERAKA_LAYERMAPPING_NUM NAMERAKA_MAPPING
#endif

#if !defined(NAMERAKA_LAYER_SYM)
  #if defined (NAMERAKA_LAYERS_FLIP)
    #define NAMERAKA_LAYER_SYM NAMERAKA_ALTERNATIVES_SYM_FLIP
  #else
    #define NAMERAKA_LAYER_SYM NAMERAKA_ALTERNATIVES_SYM
  #endif
#endif
#if !defined(NAMERAKA_LAYERMAPPING_SYM)
  #define NAMERAKA_LAYERMAPPING_SYM NAMERAKA_MAPPING
#endif

#if !defined(NAMERAKA_LAYER_FUN)
  #if defined (NAMERAKA_LAYERS_FLIP)
    #define NAMERAKA_LAYER_FUN NAMERAKA_ALTERNATIVES_FUN_FLIP
  #else
    #define NAMERAKA_LAYER_FUN NAMERAKA_ALTERNATIVES_FUN
  #endif
#endif
#if !defined(NAMERAKA_LAYERMAPPING_FUN)
  #define NAMERAKA_LAYERMAPPING_FUN NAMERAKA_MAPPING
#endif