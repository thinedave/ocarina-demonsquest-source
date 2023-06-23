#!/bin/bash

# WARNING: This script assumes it is safe to remove things from the dolphin files directory.
# If there's stuff you want to keep in there and not lose, don't use this script.

[[ $# == 1 ]] && [[ $1 = clean ]]
CLEAN_MODE=$?

PROJECT_ROOT=`git rev-parse --show-toplevel`
BUILD_DIR=$PROJECT_ROOT/build/rom
MOD_TOOLS_DIR=$PROJECT_ROOT/scripts_mod
Z64COMPRESS=$MOD_TOOLS_DIR/z64compress.exe
GZINJECT=$MOD_TOOLS_DIR/gzinject
# DOLPHIN_FILES_DIR=$MOD_TOOLS_DIR/dolphin_files
FLIPS=$MOD_TOOLS_DIR/flips.exe
DOLPHIN_EXE=$MOD_TOOLS_DIR/Dolphin.exe

OOT_DONOR_WAD=$MOD_TOOLS_DIR/oot_donor.wad
OOT_ORIGINAL_ROM=$MOD_TOOLS_DIR/oot_original_rom.z64
INJECTED_WAD="oot_injected.wad"
DQ_VERSION="14"
COMPRESSED_ROM="demonsquest$DQ_VERSION_10U.z64"

exit_with_error() {
    echo $1
    exit 1
}
readlink -e $Z64COMPRESS &>/dev/null || exit_with_error "ERROR: symlink '$Z64COMPRESS' to z64compress binary does not exist."
readlink -e $GZINJECT &>/dev/null || exit_with_error "ERROR: symlink '$GZINJECT' to gzinject binary does not exist."
readlink -e $FLIPS &>/dev/null || exit_with_error "ERROR: symlink '$FLIPS' to flips binary does not exist."

readlink -e $DOLPHIN_EXE &>/dev/null || exit_with_error "ERROR: symlink '$DOLPHIN_EXE' to Dolphin.exe does not exist."
#readlink -e $DOLPHIN_FILES_DIR &>/dev/null || exit_with_error "ERROR: symlink '$DOLPHIN_FILES_DIR' to Dolphin Emulator directory does not exist."
readlink -e $OOT_DONOR_WAD &>/dev/null || exit_with_error "ERROR: symlink '$OOT_DONOR_WAD' to OoT donor wad does not exist."

cd $PROJECT_ROOT

if [[ $CLEAN_MODE == 0 ]]; then
    make distclean
    make -j setup
else
    [[ -d $BUILD_DIR ]] && rm -r $BUILD_DIR/*
fi

mkdir -p $BUILD_DIR
make -j
if [[ $? != 0 ]]; then
    exit_with_error "ERROR: Failed to compile rom. Run `make` again for clearer compiler error messages."
fi

DMADATA_INFO=`python3 dmalength.py`

cd $BUILD_DIR
cp $PROJECT_ROOT/zelda_ocarina_mq_dbg.z64 uncompressed.z64

$Z64COMPRESS \
    --in uncompressed.z64 \
    --out compressed.z64 \
    --mb 32 \
    --codec yaz \
    --dma "$DMADATA_INFO" \
    --compress "9-14,28-END" \
    --threads 64

xxd compressed.z64 > compressed.hex
IN_LINE="00000030: 4c44 4120 0000 0000 0000 004e 5a4c 450f  LDA .......NZLE."
OUT_LINE="00000030: 4c44 4120 0000 0000 0000 0043 5a4c 450f  LDA .......CZLE."
sed -i "s/$IN_LINE/$OUT_LINE/" compressed.hex 
xxd -r compressed.hex > $COMPRESSED_ROM
echo "output rom MD5: " `md5sum $COMPRESSED_ROM`

echo 45e | $GZINJECT -a genkey
$GZINJECT \
    -a inject \
    -k common-key.bin \
    -w $OOT_DONOR_WAD \
    -m $COMPRESSED_ROM \
    -p $MOD_TOOLS_DIR/gz_mem_patch.gzi \
    -o $INJECTED_WAD

$FLIPS --create --bps $OOT_ORIGINAL_ROM $COMPRESSED_ROM demonsquest$DQ_VERSION.bps

# //rm -rf "$(readlink -e $DOLPHIN_FILES_DIR/Backup)"
# //rm -rf "$(readlink -e $DOLPHIN_FILES_DIR/GC)"
# //rm -rf "$(readlink -e $DOLPHIN_FILES_DIR/Wii)"
# //rm -rf "$(readlink -e $DOLPHIN_FILES_DIR/Cache)"
# //rm -rf "$(readlink -e $DOLPHIN_FILES_DIR/ResourcePacks)"

"$DOLPHIN_EXE" "$INJECTED_WAD" &