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


def test_100_stacks(stacks: list, test_name: str):
    op_nb = []
    error_flg = False
    print(colors.BOLD + '\nPerforming '
          + test_name + ' test.' + colors.ENDC)
    for i in stacks:
        proc = subprocess.Popen(['./push_swap', i],
                                stdout=subprocess.PIPE,
                                universal_newlines=True,
                                text=True)
        check = subprocess.Popen(['./checker_linux', i],
                                 stdin=proc.stdout,
                                 stdout=subprocess.PIPE,
                                 text=True)
        out, err = check.communicate()
        if out != 'OK\n':
            print(colors.FAIL + colors.BOLD
                  + '\t>>> ERROR! checker returned KO for test ' + i
                  + colors.ENDC)
            error_flg = True
    if (error_flg is False):
        print(colors.GREEN + '\t>>> Checker returned OK for all tests.'
              + colors.ENDC)
    for i in stacks:
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
    print('\t>>> Average number of operations: ', int(avg),
          '\n\t>>> Max number of operations: ', max_op,
          '\n\t>>> Min number of operations: ', min_op)


def test_small_stacks(perm: list, test_num: str):
    op_nb = []
    error_flg = False
    print(colors.BOLD + '\nTesting all permutations of '
          + test_num + ' numbers.' + colors.ENDC)
    for i in perm:
        proc = subprocess.Popen(['./push_swap', i],
                                stdout=subprocess.PIPE,
                                universal_newlines=True,
                                text=True)
        check = subprocess.Popen(['./checker_linux', i],
                                 stdin=proc.stdout,
                                 stdout=subprocess.PIPE,
                                 text=True)
        out, err = check.communicate()
        if out != 'OK\n':
            print(colors.FAIL + colors.BOLD
                  + '\t>>> ERROR! checker returned KO for test ' + i
                  + colors.ENDC)
            error_flg = True
    if (error_flg is False):
        print(colors.GREEN + '\t>>> Checker returned OK for all tests.'
              + colors.ENDC)
    for i in perm:
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
    print('\t>>> Average number of operations: ', int(avg),
          '\n\t>>> Max number of operations: ', max_op,
          '\n\t>>> Min number of operations: ', min_op)


def main():
    print(colors.BOLD + colors.HEADER
          + '################################################################'
          + '###########################\n###'
          + '\t\t\tTHIS IS A TESTER FOR THE 42 PROJECT PUSH_SWAP.\t\t\t'
          + '###\n###' + colors.ENDC + colors.HEADER
          + ' IT TESTS THE PUSH_SWAP PROGRAM WITH ALL PERMUTATIONS'
          + ' OF STACKS OF SIZE 3, 4, AND 5. ' + colors.BOLD
          + '###\n############################################################'
          + '###############################'
          + colors.ENDC)

    # test_small_stacks(perm.perm_3, '3')
    # test_small_stacks(perm.perm_4, '4')
    # test_small_stacks(perm.perm_5, '5')
    test_100_stacks(perm.s100_ez, '100 easy')
    test_100_stacks(perm.s100_hard, '100 hard')
    # test_100_stacks(perm.s500, '500')


if __name__ == '__main__':
    main()
