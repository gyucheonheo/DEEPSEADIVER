import os
import re
import numpy as np

def getMedian(lst):
    n = len(lst)
    s = sorted(lst)
    return (sum(s[n//2-1:n//2+1])/2.0, s[n//2])[n % 2] if n else None

def main():
    PATH = "./data/ram_block_device/"
    dir_list = os.listdir(PATH)
    dir_count = len(os.listdir(PATH))
    data = {}
    datum = []
    count = len(os.listdir(PATH+"512_1"))
    bs = 256
    for j in range(1, dir_count+1):
        datum = []
        for i in range(1, count+1):
            f = open(PATH+"512_"+str(j)+"/"+str(i)+".txt", "r")
            for line in f:
                try:
                    fd = re.findall(r'(1[,]|0[.]\d+)', line, re.MULTILINE)
                    if( len(fd) == 2 and fd[0] == '1,'):
                        datum.append(float(fd[1]))
                except:
                    pass
        med = getMedian(datum)
        avg = sum(datum)/float(len(datum))

        print(str(bs*2)+","+str(avg)+","+str(med))
        bs*=2
        
            
if __name__ == "__main__":
    main()
