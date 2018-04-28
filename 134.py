

def func(gas):

    sum_ = sum(gas)
    tot1 = 0
    tot2 = 0
    Maxsum = gas[0]
    Minsum = gas[0]
    Maxpos = 0
    CurMax = 0
    Minpos = 0

    for i in range(len(gas)):
        print(i, tot1, tot2)
        if tot1 + gas[i] < gas[i]:
            tot1 = gas[i]
            CurMax = i

        else:
            tot1 += gas[i]

        if(tot1 > Maxsum):
            Maxsum = tot1
            Maxpos = CurMax


        if tot2 + gas[i] > gas[i]:
            tot2 = gas[i]

        else:
            tot2 += gas[i]

        if(tot2 < Minsum):
            Minsum = tot2
            Minpos = i


    print(f'Maxsum: {Maxsum},  sum - Maxsum : {sum_ - Maxsum}')
    print(f'Maxpos: {Maxpos}')
    print(f'Minpos + 1 % len(gas):  {(Minpos + 1) % len(gas)}')
