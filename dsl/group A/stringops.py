x=input("enter string :")

#calculate length of string
xlen=0
for i in x:
    xlen+=1
print(xlen)

#calculate frequency of character
def characterfrequency():
    a=input("enter character ")
    afreq=0
    for i in range(xlen):
        if x[i]==a:
            afreq+=1

    print(afreq)


#palindrome checl
def palindromecheck():
    flag=0
    for i in range(xlen):
        if(x[i]==x[xlen-i-1]):
            flag=1
        else:
            flag=0
            break
    if(flag==1):
        print("palindrome hai")

    else:
        print("palindrome nahi hai")

#first appearance of substring in string
def substring():
    m=input("enter substring to check :")
    mlen=len(m)
    print(mlen)
    if m in x:
        for i in range(xlen):
            if(x[i:i+mlen]==m):
                print("first appearance at index :",i)
                break
    else:
        print("word is absent")


#frequency of each word
def frequency():
    l = []
    count={}
    a = x+" "
    word = ""
    for i in a:
        if (i != " "):
            if( i != "."):
                word+=i

        else:
            l.append(word)
            word = ""

    for i in l:
        if i not in count:
            count[i]=1
        else:
            count[i]+=1

    for k in count:
        print("word :", k ,"frequency :", count[k])

#longest word in string
def longest():
    l = []
    a = x+" "
    word=""
    longest_word = 0
    longest_w=""

    for i in a:
        if(i!=" "):
            if(i!="."):
                word+=i

        else:
            l.append(word)
            word=""

    for j in l:
        if(len(j)>longest_word):
            longest_word = len(j)
            longest_w = j

    print("longest word :",longest_w,"characters :",longest_word)
longest()