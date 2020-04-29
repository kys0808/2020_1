import numpy as np
import matplotlib.pyplot as plt

#sigmoid 함수
def sigmoid(x):
    return (1/(1+np.exp(-x)))
# ReLU 함수
def reLU(x):
    return (np.maximum(x,0))
# softmax 함수 -- 확률값 처럼 사용가능
def softmax(x):
    exp_a = np.exp(x-np.max(x))
    sum_exp_a = np.sum(exp_a)
    #print(exp_a)
    #print(sum_exp_a)
    return (exp_a/sum_exp_a)

# x1 = np.array([1, -1, 800, -5, 1000, -990])
# print(sigmoid(x1))
# x = np.arange(-5, 5, 0.1)
# y = sigmoid(x)
# plt.plot(x,y)
# plt.show()
#
# print (reLU(x1))
#
# x = np.arange(-5, 5, 0.1)
# y = reLU(x)
# plt.plot(x,y)
# plt.show()
#
# x2 = np.array([1, -1, 5, -4])
#
#
# s = softmax(x1)
# print(s)
# print(np.sum(s))

