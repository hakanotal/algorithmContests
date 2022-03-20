import sys, string
from functools import cmp_to_key

def isprime(num):
    if num == 2 or num == 3:
        return True
    if num < 2 or num%2 == 0:
        return False
    if num < 9:
        return True
    if num%3 == 0:
        return False
    a = int(num**0.5)
    b = 5
    while b <= a:
        if num%b == 0:
            return False
        if num%(b+2) == 0:
            return False
        b=b+6
    return True

n, m = map(int,input().split())

strings = []
primes = []
for i in range(n):
    s = input()
    strings.append((s,i))
    primes.append(isprime(i))


def compare(s1, s2):
    a, x = s1
    b, y = s2
    for i in range(m):
        if (a[i] != b[i]):
            if (primes[i]):
                if a[i] > b[i]:
                    return -1
                else:
                    return 1
            else:
                if a[i] < b[i]:
                    return -1
                else:
                    return 1
    return -1

strings.sort(key=cmp_to_key(compare))

for s in strings:
    a, b = s
    print(a)

for s in strings:
    a, b = s
    print(b+1, end =" ")
