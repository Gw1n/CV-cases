import cv2
import serial
import time

img = cv2.imread("*Enter your picture adress*")

#img = cv2.resize(img, (3, 3))

#cv2.imshow("Image", img)
#print(img)
#print(img.shape)

#Creating a list of average values of the image colors
lights = [0, 0, 0]
for k in range(0, 3, 1):
    sum = 0.0
    for i in range(0, img.shape[0], 1):
        for j in range(0, img.shape[1], 1):
            sum = img[i][j][k] + sum
    lights[k] += sum/(img.shape[0] * img.shape[1])
print(lights)

transferData = ''

for color in lights:
    transferData += str(color)
    transferData += ' '

print(transferData)
ser = serial.Serial('COM3', 9600, timeout = 5)
time.sleep(2)
ser.flush()
ser.write(str.encode(transferData))
time.sleep(1)
response = ser.readline()
decoded_response = response.decode('utf-8')
ser.close()
print(decoded_response)

cv2.waitKey(0)
