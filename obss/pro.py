from random import randint
import time

'''
Problem:
count how many possible combinations exist for A[i]<B[j]<C[k]
(if count is higher than 1000000000, return -1)
'''
def solution(A,B,C):
    ans = 0

    mapA = {}
    mapB = {}
    N = len(A)
    C.sort()

    for i in range(N):
        if mapA.get(A[i]) != None:
            #print(A[i])
            ans += mapA[A[i]]
        else:
            countA = ans
            for j in range(N):
                if A[i] < B[j]:
                    if mapB.get(B[j]) != None:
                        #print(A[i],B[j])
                        ans += mapB[B[j]]
                    else:
                        for k in range(N):
                            if B[j] < C[k]:
                                #print(A[i],B[j],C[k])
                                ans += N-k
                                mapB[B[j]] = N-k
                                break
            mapA[A[i]] = ans-countA

        if ans > 1e9:
            return -1

    return ans

def generator(N):
    A = []
    B = []
    C = []
    for i in range(N):
        A.append(randint(1, 1e5))
        B.append(randint(1, 1e5))
        C.append(randint(1, 1e5))
    #print(A,B,C)
    return A,B,C


if __name__ == '__main__':
    A,B,C = generator(20000)
    print("arrays generated.")

    start = time.time()
    print(solution(A,B,C))
    end = time.time()

    print("time elapsed: ", end - start)