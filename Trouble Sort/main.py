def TroubleSort(L):
	done = False
	aux = -1
	while not done:
		done = True
		for i in range(len(L)-2):
			if L[i] > L[i+2]:
				done = False
				aux = L[i]
				L[i] = L[i+2]
				L[i+2] = aux


T = int(input())
N,V = 0, []
for i in range(T):
	N = int(input())
	V = list(map(int, input().split(' ')))
	TroubleSort(V)
	v1, v2 = 0,0
	OV = V[:]
	OV.sort()
	pos = 'OK'
	for j in range(N):
		if V[j] != OV[j]:
			pos = j
			break
	print('Case #{0:d}:'.format(i + 1), pos)
