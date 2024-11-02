import os

# Define the project structure
structure = {
    "docs": [],
    "inc": [],
    "src": [
        "app",
        "middleware/filesystem",
        "middleware/graphics",
        "adapter/moduleA",
        "adapter/moduleB",
        "adapter/moduleX",
        "hal/moduleA",  # HAL: Hardware Abstraction Layer
        "hal/moduleB",
        "hal/moduleX",
    ],
    "vendor": [
        "third_party",
        "platformA",
        "platformB",
        "platformC",
    ],
    "build": [],
    "scripts": [],
    "config": ["platform_a_config.h", "platform_b_config.h"],
    "tools": [],
}

# Create the directories and files
def create_structure(base, structure):
    for key, items in structure.items():
        path = os.path.join(base, key)
        os.makedirs(path, exist_ok=True)
        if not items:  # Add .gitkeep if the directory is meant to be empty
            open(os.path.join(path, ".gitkeep"), 'a').close()
        for item in items:
            item_path = os.path.join(path, item)
            if "." in item:
                open(item_path, 'a').close()  # Create empty file
            else:
                os.makedirs(item_path, exist_ok=True)
                open(os.path.join(item_path, ".gitkeep"), 'a').close()  # Add .gitkeep to empty directories

# Set base directory as the current working directory
base_directory = os.getcwd()

# Create the structure
create_structure(base_directory, structure)

# Create additional files in the base directory
open(os.path.join(base_directory, "main.c"), 'a').close()
open(os.path.join(base_directory, "README.md"), 'a').close()
open(os.path.join(base_directory, "Makefile"), 'a').close()

print("Project directory structure created successfully.")
