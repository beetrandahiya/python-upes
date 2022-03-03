N=int(input("N = "))
scorestr=input("Scores = ")
scores=scorestr.split()

for i in range(N):
    scores[i]=int(scores[i])

scores.sort()
while i>0:
    if scores[i]==scores[i-1]:
        i-=1
    else:
        runnerup=scores[i-1]
        break

print(runnerup)