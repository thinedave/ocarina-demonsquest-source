import os

assets_mod = "assets_mod"
assets = "assets"
assets_mod_history = "assets_mod_history"

allowed_types = {
    ".c": True,
    ".h": True,

}

def handle_file(file_name):
    if(os.path.splitext(file_name)[-1] in allowed_types): return
    if(not os.path.exists(file_name)): raise Exception("File '" + file_name + "' is not valid, but was in list of files")

    print("Deleting file '" + file_name + "'")

    os.remove(file_name)

def handle_directory(dir):
    print("Opening directory '" + dir + "'")

    for path, dirs, files in os.walk(dir):
        for file_name in files:
            handle_file(os.path.join(path, file_name))

        for subdir in dirs:
            handle_directory(os.path.join(path, subdir))

handle_directory(assets_mod_history)