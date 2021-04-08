def its(c,j,k):
    c = ''
    c = str(j) + str(k)
    return(c)
        
def arrange_lexicographically(string1,string2,index):
    str1 = len(string1)
    str2 = len(string2)
    if ((index == str1) and (index == str2)):
        return 0
    elif (index == str1):
        string1=string1+'0'
        value = arrange_lexicographically(string1,string2,index+1)
    elif (index == str2):
        string2=string2+'0'
        value = arrange_lexicographically(string1,string2,index+1)
    else:
        if (string1[index] > string2[index]):
            return 0
        elif (string1[index] < string2[index]):
            return 1
        else:
            value = arrange_lexicographically(string1,string2,index+1)
    return value
if __name__ == '__main__':
    zero = "00"
    T = int(input())
    for i in range(T):
        j = 0
        k = 0
        index = 0
        strlist = []
        str1 = zero
        str2 = zero
        N = int(input())
        for j in range(1,int(N**(0.5)) + 1):
            for k in range(1,int(N**(0.5)) + 1):
                if (k*k == (N - j*j)):
                    str1 = its(str1,j,k)
                    str2 = its(str2,k,j)
                    strlist.append(str1)
                    strlist.append(str2)
                    index=index+2
        if ((str1 != zero) and (str2 != zero)):
            k = 0
            while (k <= (index - 2)):
                if (arrange_lexicographically(strlist[k],strlist[k+1],0) == 0):
                    max_ = strlist[k]
                else:
                    max_ = strlist[k+1]
                k=k+1
            print(max_)
        
