#***********generate extreme knee angles************
import numpy as np
data  = np.load('outputfile.npy')
lst = data
rmin = 180
rmax = 0
lmin = 180
lmax = 0
for item in lst:
    #print(item)
    # print("RH",item[1])
    # print("RK",item[2])
    # print("RF",item[3])
    # print("LH",item[4])    
    # print("LK",item[5])
    # print("LF",item[6])
    a = np.array(item[1]-item[2])
    b = np.array(item[3]-item[2])
    c = np.array(item[4]-item[5])
    d = np.array(item[6]-item[5])
    rangle = np.arccos(np.dot(a,b)/(np.linalg.norm(a)*np.linalg.norm(b)))
    rangle = 180*rangle/np.pi
    langle = np.arccos(np.dot(c,d)/(np.linalg.norm(c)*np.linalg.norm(d)))
    langle = 180*langle/np.pi
    
    if rangle < rmin:
      rmin = rangle
    if rangle > rmax:
      rmax = rangle
    if langle < lmin:
      lmin = langle
    if langle > lmax:
      lmax = langle

round(rmax,2)
round(rmin,2)  
s = "right max: " + rmax + "\n" + "right min: " + rmin + "\n" + "left max: " + lmax + "\n" + "left min: " + lmin
file = open("angle.txt", "w")
print("file name:", file.name)