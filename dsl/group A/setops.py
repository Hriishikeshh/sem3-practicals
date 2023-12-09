la=["a" ,"b","c","d","k"]
lb=["b" ,"c","d","a","h"]
lc=["d" ,"e","f","g"]
alen=blen=clen=3
# alen=int(input("no. of cricket students :"))
# for i in range(alen):
#     a=input("enter names :")
#     la.append(a)
#
# blen=int(input("no. of badminaton students :"))
# for i in range(blen):
#     b=input("enter names :")
#     lb.append(b)
#
# clen=int(input("no. of football students :"))
# for i in range(clen):
#     c=input("enter names :")
#     lc.append(c)

#cricket and badminton both

def cricket_and_badminton():
    lab=[]
    for i in la:
        for j in lb:
            if(i==j):
                lab.append(i)

    print(lab)
cricket_and_badminton()

def cricket_or_badminton_notboth():
    lab=[]
    for i in la:
        lab.append(i)
        for j in lb:
            if(i==j):
                lab.remove(i)

    for i in lb:
        lab.append(i)
        for j in la:
            if(i==j):
                lab.remove(i)
    print(lab)
cricket_or_badminton_notboth()

#neither cricket nor badminton
def neither_badminton_nor_cricket():
    lab = []
    for i in la:
        lab.append(i)

    for j in lb:
        lab.append(j)

    lcb=[]
    for k in lab:
       for l in lc:
           if(k==l):
               lc.remove(k)

    print(lc)
neither_badminton_nor_cricket()

#cricket and football not badminton
def cricket_and_football_not_badminton():
    lac = []
    for i in la:
        lac.append(i)

    for j in lc:
        lac.append(j)

    for k in lb:
        for l in lac:
            if (k == l):
                lac.remove(k)

    print(lac)
cricket_and_football_not_badminton()

#
