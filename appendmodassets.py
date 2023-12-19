import os
from shutil import copyfile

assets_mod = "assets_mod"
assets = "assets"
assets_mod_history = "assets_mod_history"

allowed_types = {
    ".c": True,
    ".h": True,

}

def handle_file_noncode(file_name):
    print("Opening file '" + file_name + "'")

    new_dir = file_name.replace(assets_mod, assets)

    print("Copying non-code asset '" + file_name + "' to file '" + new_dir + "'")

    copyfile(file_name, new_dir)

def handle_file(file_name):
    if(not os.path.splitext(file_name)[-1] in allowed_types):
        handle_file_noncode(file_name)
        return

    print("Opening file '" + file_name + "'")

    f = open(file_name)
    if(not f): raise Exception("File '" + f + "' is not valid")

    new_dir = file_name.replace(assets_mod, assets)

    #if(not os.path.isfile(new_dir)):
    #    print("File '" + new_dir + "' does not exist, skipping.")
    #    return

    print("Appending file '" + file_name + "' to file '" + new_dir + "'")

    hist_dir = file_name.replace(assets_mod, assets_mod_history)

    if(os.path.isfile(hist_dir) and os.path.isfile(new_dir)):
        hist_file = open(hist_dir, "r")
        new_file = open(new_dir, "r")

        code = new_file.read().replace(hist_file.read(), "")

        hist_file.close()
        new_file.close()

        new_file = open(new_dir, "w")
        new_file.write(code)
        new_file.close()

    old_file_code = f.read()
    f.close()

    dir_without_file = os.path.dirname(new_dir)

    os.makedirs(dir_without_file, exist_ok=True)

    new_file = open(new_dir, "a")
    new_file.write(old_file_code)
    new_file.close()

    hist_file = open(hist_dir, "w")
    hist_file.write(old_file_code)
    hist_file.close()

def handle_directory(dir):
    print("Opening directory '" + dir + "'")

    for path, dirs, files in os.walk(dir):
        for file_name in files:
            handle_file(os.path.join(path, file_name))

        for subdir in dirs:
            handle_directory(os.path.join(path, subdir))

handle_directory(assets_mod)