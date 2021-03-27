import random
import sys

n = 0
if (len(sys.argv) == 2):
    n = int(sys.argv[1])
numbers = random.sample(range(0, n), n)
random.shuffle(numbers)
numbers_str = ' '.join([str(elem) for elem in numbers])
print(numbers_str)
# os.environ["NUMS"] = "yo"
