import os
from shutil import copyfile

assets_mod = "assets_mod_scenemod"
assets = "assets/scenes"

def handle_file(file_name):
    print("Opening file '" + file_name + "'")

    new_dir = file_name.replace(assets_mod, assets)

    print("Copying non-code asset '" + file_name + "' to file '" + new_dir + "'")

    dir_without_file = os.path.dirname(new_dir)
    os.makedirs(dir_without_file, exist_ok=True)

    copyfile(file_name, new_dir)

def handle_directory(dir):
    print("Opening directory '" + dir + "'")

    for path, dirs, files in os.walk(dir):
        for file_name in files:
            handle_file(os.path.join(path, file_name))

        for subdir in dirs:
            handle_directory(os.path.join(path, subdir))

handle_directory(assets_mod)