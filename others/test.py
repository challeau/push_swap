import subprocess

perm_5 = {
    "1 2 3 4 5",
    "2 1 3 4 5",
    "3 1 2 4 5",
    "1 3 2 4 5",
    "2 3 1 4 5",
    "3 2 1 4 5",
    "3 2 4 1 5",
    "2 3 4 1 5",
    "4 3 2 1 5",
    "3 4 2 1 5",
    "2 4 3 1 5",
    "4 2 3 1 5",
    "4 1 3 2 5",
    "1 4 3 2 5",
    "3 4 1 2 5",
    "4 3 1 2 5",
    "1 3 4 2 5",
    "3 1 4 2 5",
    "2 1 4 3 5",
    "1 2 4 3 5",
    "4 2 1 3 5",
    "2 4 1 3 5",
    "1 4 2 3 5",
    "4 1 2 3 5",
    "5 1 2 3 4",
    "1 5 2 3 4",
    "2 5 1 3 4",
    "5 2 1 3 4",
    "1 2 5 3 4",
    "2 1 5 3 4",
    "2 1 3 5 4",
    "1 2 3 5 4",
    "3 2 1 5 4",
    "2 3 1 5 4",
    "1 3 2 5 4",
    "3 1 2 5 4",
    "3 5 2 1 4",
    "5 3 2 1 4",
    "2 3 5 1 4",
    "3 2 5 1 4",
    "5 2 3 1 4",
    "2 5 3 1 4",
    "1 5 3 2 4",
    "5 1 3 2 4",
    "3 1 5 2 4",
    "1 3 5 2 4",
    "5 3 1 2 4",
    "3 5 1 2 4",
    "4 5 1 2 3",
    "5 4 1 2 3",
    "1 4 5 2 3",
    "4 1 5 2 3",
    "5 1 4 2 3",
    "1 5 4 2 3",
    "1 5 2 4 3",
    "5 1 2 4 3",
    "2 1 5 4 3",
    "1 2 5 4 3",
    "5 2 1 4 3",
    "2 5 1 4 3",
    "2 4 1 5 3",
    "4 2 1 5 3",
    "1 2 4 5 3",
    "2 1 4 5 3",
    "4 1 2 5 3",
    "1 4 2 5 3",
    "5 4 2 1 3",
    "4 5 2 1 3",
    "2 5 4 1 3",
    "5 2 4 1 3",
    "4 2 5 1 3",
    "2 4 5 1 3",
    "3 4 5 1 2",
    "4 3 5 1 2",
    "5 3 4 1 2",
    "3 5 4 1 2",
    "4 5 3 1 2",
    "5 4 3 1 2",
    "5 4 1 3 2",
    "4 5 1 3 2",
    "1 5 4 3 2",
    "5 1 4 3 2",
    "4 1 5 3 2",
    "1 4 5 3 2",
    "1 3 5 4 2",
    "3 1 5 4 2",
    "5 1 3 4 2",
    "1 5 3 4 2",
    "3 5 1 4 2",
    "5 3 1 4 2",
    "4 3 1 5 2",
    "3 4 1 5 2",
    "1 4 3 5 2",
    "4 1 3 5 2",
    "3 1 4 5 2",
    "1 3 4 5 2",
    "2 3 4 5 1",
    "3 2 4 5 1",
    "4 2 3 5 1",
    "2 4 3 5 1",
    "3 4 2 5 1",
    "4 3 2 5 1",
    "4 3 5 2 1",
    "3 4 5 2 1",
    "5 4 3 2 1",
    "4 5 3 2 1",
    "3 5 4 2 1",
    "5 3 4 2 1",
    "5 2 4 3 1",
    "2 5 4 3 1",
    "4 5 2 3 1",
    "5 4 2 3 1",
    "2 4 5 3 1",
    "4 2 5 3 1",
    "3 2 5 4 1",
    "2 3 5 4 1",
    "5 3 2 4 1",
    "3 5 2 4 1",
    "2 5 3 4 1",
    "5 2 3 4 1",
}

perm_4 = {
    "1 2 3 4",
    "2 1 3 4",
    "3 1 2 4",
    "1 3 2 4",
    "2 3 1 4",
    "3 2 1 4",
    "3 2 4 1",
    "2 3 4 1",
    "4 3 2 1",
    "3 4 2 1",
    "2 4 3 1",
    "4 2 3 1",
    "4 1 3 2",
    "1 4 3 2",
    "3 4 1 2",
    "4 3 1 2",
    "1 3 4 2",
    "3 1 4 2",
    "2 1 4 3",
    "1 2 4 3",
    "4 2 1 3",
    "2 4 1 3",
    "1 4 2 3",
    "4 1 2 3",
}

perm_3 = {
    "1 2 3",
    "1 3 2",
    "2 1 3",
    "2 3 1",
    "3 1 2",
    "3 2 1",
}

op_nb = []

print(">> Testing all permutations of 3 numbers.")
for i in perm_3:
    proc = subprocess.Popen(["./push_swap", i],
                            stdout=subprocess.PIPE,
                            universal_newlines=True,
                            text=True)
    check = subprocess.Popen(["./checker_linux", i],
                             stdin=proc.stdout,
                             text=True)

for i in perm_3:
    line_count = 0
    proc = subprocess.run(["./push_swap", i],
                          capture_output=True,
                          text=True)
    for c in proc.stdout:
        if c == '\n':
            line_count += 1
    op_nb.append(line_count)
    if (line_count > 12):
        print(i, line_count)

avg = sum(op_nb) / len(op_nb)
max_op = max(op_nb)
min_op = min(op_nb)
print(avg, max_op, min_op)

print("\n>> Testing all permutations of 4 numbers.")
for i in perm_4:
    proc = subprocess.Popen(["./push_swap", i],
                            stdout=subprocess.PIPE,
                            universal_newlines=True,
                            text=True)
    check = subprocess.Popen(["./checker_linux", i],
                             stdin=proc.stdout,
                             text=True)

for i in perm_4:
    line_count = 0
    proc = subprocess.run(["./push_swap", i],
                          capture_output=True,
                          text=True)
    for c in proc.stdout:
        if c == '\n':
            line_count += 1
    op_nb.append(line_count)
    if (line_count > 12):
        print(i, line_count)

avg = sum(op_nb) / len(op_nb)
max_op = max(op_nb)
min_op = min(op_nb)
print(avg, max_op, min_op)

print("\n>> Testing all permutations of 5 numbers.")
for i in perm_5:
    proc = subprocess.Popen(["./push_swap", i],
                            stdout=subprocess.PIPE,
                            universal_newlines=True,
                            text=True)
    check = subprocess.Popen(["./checker_linux", i],
                             stdin=proc.stdout,
                             text=True)

for i in perm_5:
    line_count = 0
    proc = subprocess.run(["./push_swap", i],
                          capture_output=True,
                          text=True)
    for c in proc.stdout:
        if c == '\n':
            line_count += 1
    op_nb.append(line_count)
    if (line_count > 12):
        print(i, line_count)

avg = sum(op_nb) / len(op_nb)
max_op = max(op_nb)
min_op = min(op_nb)
print(avg, max_op, min_op)
