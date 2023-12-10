r1=int(input("enter rows:"))
c1=int(input("enter column :"))

r2=int(input("enter rows:"))
c2=int(input("enter column :"))

print('''enter operation no. to perform :
1.addition
2.subtraction
3.product
4.transpose''')

z=int(input("enter choice:"))

if(z==1):
    if(r1==r2 and c1==c2):
        #first matrix
        m1=[]
        for i in range(r1):
            row=[]
            for j in range(c1):
                x=int(input("enter element:"))
                row.append(x)
            m1.append(row)

        for i in range(r1):
            print(m1[i])

        # second matrix
        m2 = []
        for i in range(r2):
            row = []
            for j in range(c2):
                x = int(input("enter element:"))
                row.append(x)
            m2.append(row)

        for i in range(r2):
            print(m2[i])

        #sum
        m3=[]
        for i in range(r1):
            row=[]
            for  j in range(c1):
                x=m1[i][j]+m2[i][j]
                row.append(x)
            m3.append(row)

        print("sum is:")
        for i in range(r2):
            print(m3[i])


    else:
        print("can't")

if(z==3):

    if(c1==r2):
        # first matrix
        m1 = []
        for i in range(r1):
            row = []
            for j in range(c1):
                x = int(input("enter element:"))
                row.append(x)
            m1.append(row)

        for i in range(r1):
            print(m1[i])

        # second matrix
        m2 = []
        for i in range(r2):
            row = []
            for j in range(c2):
                x = int(input("enter element:"))
                row.append(x)
            m2.append(row)

        for i in range(r2):
            print(m2[i])

        # product
        m3 = []
        for i in range(r1):
            row = []
            for j in range(c2):
                t=0
                for k in range(c1):
                    t += m1[i][k] * m2[k][j]
                row.append(t)
            m3.append(row)

        #product
        print("product is:")
        for i in range(r1):
            print(m3[i])

    if(r1==c2):
        # first matrix
        m1 = []
        for i in range(r1):
            row = []
            for j in range(c1):
                x = int(input("enter element:"))
                row.append(x)
            m1.append(row)

        for i in range(r1):
            print(m1[i])

        # second matrix
        m2 = []
        for i in range(r2):
            row = []
            for j in range(c2):
                x = int(input("enter element:"))
                row.append(x)
            m2.append(row)

        for i in range(r2):
            print(m2[i])

        # product
        m3 = []
        for i in range(r2):
            row = []
            for j in range(c1):
                t=0
                for k in range(c2):
                    t +=m2[i][k]*m1[k][j]
                row.append(t)
            m3.append(row)

        #product
        print("product is:")
        for i in range(r2):
            print(m3[i])



