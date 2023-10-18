#!/bin/bash
#
# To get ccls support (code intelligence for lsp):
# 1. Compile the keyboard once:
#    qmk flash -c -kb crkbd -km manna-harbour_miryoku   -e MIRYOKU_ALPHAS=QWERTY   -e MIRYOKU_EXTRA=COLEMAKDH   -e MIRYOKU_TAP=QWERTY
# 2. From the main qmk_firmware directory, execute this script.
#    ./users/andjo_corne/ccls_create.sh
#
# Done! ccls should now be available when developing.

echo 'clang' > .ccls; cat .build/obj_crkbd_rev1_manna-harbour_miryoku/cflags.txt | sed 's/ -/\n-/g' >> .ccls
