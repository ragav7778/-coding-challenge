 
from collections import defaultdict
a=[0 for i in range(6)]
b=[0 for i in range(6)]
c=[]
d=[]
s=[1,2,3,4,5,6]
st=defaultdict(lambda :0)
for i in s:
    for j in s:
        st[i+j]+=1
    
        
     
        
        
def rule(a,b):
    t=defaultdict(lambda :0)
    for i in a:
        for j in b:
            if (i!= 0 and j!=0):
                t[i+j]+=1
                
    
    for i,j in t.items():
        print(i,t[i],st[i])
        if(t[i]>st[i]):
            return False
    return True
    
def backtrack(a,b,cur):
    if (cur==6):
        c.append(a)
        d.append(b)
        
        return True
    
    else:
        
        for i in range(1,5):
            a[cur]=i
            for j in range(1,9):
                b[cur]=j
                print(a,b,cur)
                if (rule(a,b)):
                    if(backtrack(a,b,cur+1)==True):
                      return True
                b[cur]=0
            a[cur]=0
            
            
            
    return False
    
    
print(backtrack(a,b,0))
print(c)
print(d)



 
