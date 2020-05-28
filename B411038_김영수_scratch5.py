import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split, cross_val_score
import math
from dataset.mnist import load_mnist

y1 = np.array([0.1, 0.05, 0, 0.6, 0, 0.1, 0, 0.4, 0.05, 0])
t1 = np.array([0, 0, 0, 1, 0, 0, 0, 0, 0, 0])
t1_label = np.array([3])

y2 = np.array([[0.1, 0.05, 0, 0.6, 0, 0.1, 0, 0.4, 0.05, 0],
               [0.1, 0.05, 0, 0.06, 0, 0.1, 0, 0.4, 0.5, 0]])
t2 = np.array([[0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
               [0, 0, 0, 0, 0, 0, 0, 0, 1, 0]])
t2_label = np.array([3, 8])

def cross_entropy_error(y, t):
    if y.ndim == 1: # y차원 1이면, 2차원으로 변경
        t = t.reshape(1, t.size)
        y = y.reshape(1, y.size)
    batch_size = y.shape[0]
    epsilon = 1e-7
    cee = (np.sum(-t * np.log(y + epsilon))) / batch_size
    return cee

print(cross_entropy_error(y1, t1))
print(cross_entropy_error(y2, t2))
