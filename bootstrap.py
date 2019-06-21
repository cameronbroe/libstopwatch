import os
import subprocess

CATCH_REPO_URL = 'https://github.com/catchorg/Catch2'

def create_vendor_dir():
    print("Checking if vendor directory exists")
    if os.path.exists("./vendor"):
        print("Vendor directory already exists...skipping")
    else:
        os.mkdir("./vendor")
        print("Vendor directory does not exists...creating")

def install_catch():
    print("Checking for Catch2")
    if os.path.exists("./vendor/catch"):
        print("Catch2 FOUND...skipping")
    else:
        print("Downloading Catch2")
        subprocess.run(['git', 'clone', '--depth=1', CATCH_REPO_URL, './vendor/catch'])
        subprocess.run(['rm', '-rf', './vendor/catch/.git'])

if __name__ == "__main__":
    create_vendor_dir()
    install_catch()
