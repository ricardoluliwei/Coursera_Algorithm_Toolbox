#! python3

from operator import sub
import os
import sys
from pathlib import Path

WORKSPACE = 'WORKSPACE'
BUILD = 'BUILD'


def CheckWorkspace():
    if not os.path.exists(WORKSPACE):
        print("Run the script in the root directory of a workspace.")
        exit(1)


def CreateBuildFile(path_name):
    if (isinstance(path_name, str)):
        path_name = Path(path_name)
    if (not isinstance(path_name, Path)):
        print("dir should be str or Path.")
        exit(1)
    for sub_path in path_name.iterdir():
        if sub_path.is_dir():
            CreateBuildFile(sub_path)
        elif sub_path.is_file() and not Path("BUILD").is_file():
            target = sub_path.stem
            extension = sub_path.suffix
            if (extension == ".cpp"):
              with (path_name / "BUILD").open() as fw:
                  fw.write("cc_binary(\n")
                  fw.write(f"    name = \"{target}\"\n")
                  fw.write(f"    srcs = \"{sub_path.name}\"\n")
                  fw.write("deps = [\"@com_github_google_glog//:glog\"]\n\n")

def main():
  # CheckWorkspace()
  CreateBuildFile(os.getcwd())


if __name__ == '__main__':
  main()
