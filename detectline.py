import numpy as np
import cv2 as cv

img = cv.imread('/home/kimmypracha/Desktop/images5.jpg')
gray = cv.cvtColor(img ,cv.COLOR_BGR2GRAY)
blurred = cv.GaussianBlur(gray,(9,9),0)
edged = cv.Canny(blurred,50,150)
cnt = 0
lines = cv.HoughLinesP(edged,1,np.pi/180,10,80,1)
Left = 0;
Right =0;
cl = 0
cr = 0
cv.line(img,(372,0),(372,500),(255,0,0),2)
if(lines.any()):
	for line in lines:
		for x1,y1,x2,y2 in line:
			cnt += 1
			cv.line(img,(x1,y1),(x2,y2),(0,255,0),2)
			if(x1-372<0):
				Left += 372-x1
				cl += 1
			elif(x1-372>0):
				Right += x1-372
				cr += 1
			if(x2-372<0):
				Left += 372-x2
				cl += 1
			elif(x2-372>0):
				Right += x2-372
				cr += 1 
avgl = Left/cl
avgr = Right/cr
print(avgl,avgr)
cv.imshow("line detect test" , img)
cv.waitKey(0) 
print("There is ")
print(cnt)
