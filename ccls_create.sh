#!/bin/bash
#
# To get ccls support (code intelligence for lsp):
# 1. Compile the keyboard once:
#    qmk flash -c -kb crkbd -km andjo-nameraka -e NAMERAKA_ALPHAS=QWERTY -e NAMERAKA_EXTRA=COLEMAKDH -e NAMERAKA_TAP=QWERTY
# 2. From the main qmk_firmware directory, execute this script.
#    ./users/andjo-nameraka/ccls_create.sh
#
# Done! ccls should now be available when developing.

echo 'clang' > .ccls; cat .build/obj_crkbd_rev1_nameraka/cflags.txt | sed 's/ -/\n-/g' >> .ccls
