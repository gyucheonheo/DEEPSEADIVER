import os
import numpy as np

def getMedian(lst):
    n = len(lst)
    s = sorted(lst)
    return (sum(s[n//2-1:n//2+1])/2.0, s[n//2])[n % 2] if n else None

def get_average(instr):
    PATH = "./data/"+instr+"/"
    files = os.listdir(PATH)
    file_count = len(files)
    data = []
    for f in files:
        fl = open(PATH+f, "r")
        for line in fl:
            data.append(float(line))
    avg = sum(data)/len(data)
    med = getMedian(data)
    print(str(avg)+","+str(med)+"(nano secs)")
            # TODO
            # get data from a file
            # calculate the average
            # Generate a chart!
    
def main():
    get_average("load")
    get_average("str")
    
if __name__ == "__main__":
    main()
