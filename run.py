from itertools import chain
from os import listdir, system
from os.path import isdir as is_dir, join as path_join, getmtime
import subprocess

SOLUTIONS_DIR = "solutions"
CXX = "clang++"
CXXFLAGS = "-g -DDEBUG"


def run(full_path: str):
    main = path_join(full_path, "main.cpp")
    out = path_join(full_path, "main")
    cmd = f"{CXX} {main} {CXXFLAGS} -o {out}"
    system(cmd)

    inps = path_join(full_path, "inps.txt")
    outs = path_join(full_path, "outs.txt")

    with open(inps, "r") as i, open(outs, "r") as o:
        p = subprocess.Popen(f"{out}", stdin=i, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        expected_output = o.readlines()
        actual_output = list(map(lambda x: x.decode(), p.stdout.readlines()))
        print(f"{full_path}", end=": ")
        if expected_output == actual_output:
            print("PASSED")
        else:
            print("FAILED")
            print("DEBUG:")
            print(p.stderr.read().decode())
            expected_maxlen = max(
                len(sorted(expected_output, key=len)[0]), len("EXPECTED")
            )
            actual_maxlen = max(len(sorted(actual_output, key=len)[0]), len("GOT"))
            print(
                f"{{:<{expected_maxlen + 2}}} | {{:<{actual_maxlen}}}\n{'-' * (expected_maxlen + 3)}+{'-'*(actual_maxlen+3)}".format(
                    "EXPECTED", "GOT"
                )
            )
            for a, b in chain(zip(expected_output, actual_output)):
                fmt = f"{{:<{expected_maxlen + 2}}} | {{:<{actual_maxlen + 2}}}"
                if a != b:
                    fmt += "!"
                print(fmt.format(a.strip(), b.strip()))

        assert p.wait() == 0


dirs = listdir(SOLUTIONS_DIR)
dirs.sort(key=lambda f: getmtime(path_join(SOLUTIONS_DIR, f)))

for problem_id in dirs:
    if is_dir(contest_dir := path_join(SOLUTIONS_DIR, problem_id)):
        for ch in listdir(contest_dir):
            full_path = path_join(contest_dir, ch)
            run(full_path)
