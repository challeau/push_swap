import subprocess
import perm

# 3 values --> 2 or 3
# 5 values --> max 12
# 100 values
#   - < 700: 5
#   - < 900: 4
#   - < 1100: 3
#   - < 1300: 2
#   - < 1500: 1
# 500 values
#   - < 5500: 5
#   - < 7000: 4
#   - < 8500: 3
#   - < 10000: 2
#   - < 11500: 1
# test for stacks with extreme values very far from each other
# test for stacks withvsome very small/big values + rest normal
# 1. check that list is sorted
# 2. check the number of operations


class colors:
    HEADER = '\033[95m'
    BLUE = '\033[94m'
    CYAN = '\033[96m'
    GREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'
    ENDC = '\033[0m'


def test_small_numbers():
    op_nb = []
    print(colors.BOLD + 'Testing all permutations of 3 numbers.' + colors.ENDC)
    for i in perm.perm_3:
        proc = subprocess.Popen(['./push_swap', i],
                                stdout=subprocess.PIPE,
                                universal_newlines=True,
                                text=True)
        check = subprocess.Popen(['./checker_linux', i],
                                 stdin=proc.stdout,
                                 stdout=subprocess.PIPE,
                                 text=True)
        out, err = check.communicate()
        if out == 'KO\n':
            print(colors.FAIL + colors.BOLD
                  + '\tERROR! checker returned KO for test ' + i
                  + colors.ENDC)
            exit()
    print('\t>>> Checker returned OK for all tests.')
    for i in perm.perm_3:
        line_count = 0
        proc = subprocess.run(['./push_swap', i],
                              capture_output=True,
                              text=True)
        for c in proc.stdout:
            if c == '\n':
                line_count += 1
                op_nb.append(line_count)
    avg = sum(op_nb) / len(op_nb)
    max_op = max(op_nb)
    min_op = min(op_nb)
    print('\t>>> Average number of operations: ', avg,
          '\n\t>>> Max number of operations: ', max_op,
          '\n\t>>> Min number of operations: ', min_op)


def main():
    test_small_numbers()


if __name__ == '__main__':
    main()
