def get_section_address(ovl_name, section_name):
  section_start_name = "_" + ovl_name + "Segment" + section_name + "Start"
  # 'section_start_name' is a 'text variable' according to gdb, this can not be resolved via python directly
  return int(gdb.execute('printf "%x", &' + section_start_name, False, True), 16)

def hook_stop(ev):
  frame = gdb.selected_frame()
  func_name = frame.name()

  if func_name == "Overlay_Load":
    alloc_address = frame.read_var("allocatedRamAddr").cast(gdb.lookup_type('u32'))

    # get first symbol-name starting from vramStart (usually the first function in the overlay)
    target_func_name = gdb.execute("info symbol vramStart", False, True).partition(' ')[0].rstrip()

    # get section in main ELF (returns: "EnKusa_SetupAction in section ..ovl_En_Kusa of zelda_ocarina_mq_dbg.elf")
    ovl_sec_name = gdb.execute("info sym " + target_func_name, False, True)
    # extract section name (@TODO: check if there is a direct API for this)
    ovl_sec_name = ovl_sec_name.partition('section ..')[2].partition(" ")[0].rstrip()

    ovl_address_text   = get_section_address(ovl_sec_name, "Text")
    ovl_address_data   = get_section_address(ovl_sec_name, "Data")
    ovl_address_rodata = get_section_address(ovl_sec_name, "RoData")
    ovl_address_bss    = get_section_address(ovl_sec_name, "Bss")

    ovl_offset_text   = alloc_address
    ovl_offset_data   = alloc_address + (ovl_address_data   - ovl_address_text)
    ovl_offset_rodata = alloc_address + (ovl_address_rodata - ovl_address_text)
    ovl_offset_bss    = alloc_address + (ovl_address_bss    - ovl_address_text)

    # get full object-file path that contains the first symbol
    target_filename = gdb.lookup_symbol(target_func_name)[0].symtab.filename
    obj_name = "build/" + target_filename[:-1] + "o"

    print("Loaded overlay: ", obj_name, "(.text:", hex(ovl_offset_text), " .data:", hex(ovl_offset_data), " .rodata:", hex(ovl_offset_rodata), " .bss:", hex(ovl_offset_bss), ")")

    gdb.execute("add-symbol-file -readnow " + obj_name +
      " -o 0xFF000000" +
      " -s .text "   + hex(ovl_offset_text)   +
      " -s .data "   + hex(ovl_offset_data)   +
      " -s .rodata " + hex(ovl_offset_rodata) +
      " -s .bss "    + hex(ovl_offset_bss),
      False, True)

    gdb.execute("c", False, True)
    return

gdb.events.stop.connect(hook_stop)
gdb.execute("b Overlay_Load")

# Unused Stuff:

# def read_overlay_table():
#   actor_table = gdb.lookup_global_symbol("gActorOverlayTable").value()
#   table_size = 0x0192
#
#   for i in range(table_size):
#     entry_address = int(actor_table[i]["vramStart"])
#     entry_name = actor_table[i]["name"].string()
#     entry_loaded = int(actor_table[i]["numLoaded"])
#
#     if entry_address > 0 and entry_loaded > 0:
#       print("Table[", i, "]: address =", hex(entry_address), " name =", entry_name, " loaded =", entry_loaded)
