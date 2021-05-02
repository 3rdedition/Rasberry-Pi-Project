from keras.models import load_model
import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt
from keras.models import Sequential
from keras.layers import Dense, Conv2D, Dropout, Flatten, MaxPooling2D
import cv2

model = load_model('/usr/16011033/mnist_model/MNIST_CNN.h5')
file = "/home/pi/Desktop/output/crop_image.png";


image = cv2.imread(file, cv2.IMREAD_GRAYSCALE)
image = cv2.resize(image, (28,28))
image = image.astype('float64')
image = image.reshape(1, 28, 28, 1)
image = 255-image
image /= 255


plt.imshow(image.reshape(28, 28),cmap='Greys')
plt.show()
pred = model.predict(image.reshape(1, 28, 28, 1), batch_size=1)

f = open("/usr/temp.txt","w")
f.write(str(pred.argmax()))
print(pred.argmax())
