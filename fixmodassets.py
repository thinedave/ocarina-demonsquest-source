import os

assets_mod = "assets_mod"
assets = "assets"

allowed_types = {
    ".c": True,
    ".h": True,

}

def handle_file(file_name):
    if(not os.path.splitext(file_name)[-1] in allowed_types): return

    print("Opening file '" + file_name + "'")

    f = open(file_name)
    if(not f): raise Exception("File '" + f + "' is not valid")

    new_dir = file_name.replace("assets/", "assets_mod/")

    if(os.path.isfile(new_dir)):
        print("File '" + new_dir + "' already exists, skipping.")
        return

    print("Copying file '" + file_name + "' to file '" + new_dir + "'")

    new_file = open(new_dir, "w")

    new_file.write(f.read())

    new_file.close()
    f.close()

def handle_directory(dir):
    print("Opening directory '" + dir + "'")

    new_dir = dir.replace("assets", "assets_mod")

    if(not os.path.exists(new_dir)):
        print("Directory '" + new_dir + "' does not exist, skipping.")
        return

    for path, dirs, files in os.walk(dir):
        for file_name in files:
            handle_file(os.path.join(path, file_name))

        for subdir in dirs:
            handle_directory(os.path.join(path, subdir))

dirs_to_search = []

def handle_dir_finddirs(path, files):
    if(len(files) <= 0):
        print("Directory '" + path + "' has no files. Skipping")
        return

    for file_name in files:
        if(not os.path.splitext(file_name)[-1] in allowed_types): continue

        break

    print("Directory '" + path + "' is missing files.")

    dirs_to_search.append(path.replace("assets_mod", "assets"))

def find_dirs(dir):
    print("Looking for missing files in '" + dir + "'")

    for path, dirs, files in os.walk(dir):
        handle_dir_finddirs(path, files)

        for subdir in dirs:
            find_dirs(os.path.join(path, subdir))

find_dirs(assets_mod)

for dir in dirs_to_search:
    handle_directory(dir)