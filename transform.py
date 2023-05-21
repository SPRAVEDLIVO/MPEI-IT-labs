# script to convert all .cpp.txt files to .cpp files
import os

for file in os.listdir():
    if os.path.isdir(file) and not file.startswith("."):
        relPath = file
        for f in os.listdir(file):
            curPath = os.path.join(relPath, f)
            if curPath.split(".")[-2] + (ext_inf := os.path.splitext(curPath))[1] == "cpp.txt":
                os.rename(curPath, ext_inf[0])