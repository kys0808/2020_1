import numpy as np
from functions import sigmoid, softmax

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

def cross_entropy_error_label(y, t):
    epsilon = 1e-7
    if y.ndim == 1:
        y = y.reshape(1, y.size)
        t = t.reshape(1, t.size)
    batch_size = y.shape[0]
    cee = -np.sum(np.log(y[np.arange(batch_size),t]+epsilon))/batch_size
    return cee
#print(cross_entropy_error(y2, t2))
#print(cross_entropy_error(y1, t1))

def function_1(x):
    return 0.01*x**2 + 0.1*x

def numerical_difference(f, x): #수치 미분
    h = 1e-4
    diff = f(x+h) - f(x-h)
    return diff/(2*h)

# x = np.arange(0.0, 20.0, 0.1)
# y = function_1(x)
# plt.xlabel("x")
# plt.ylabel("f(x)")
# plt.plot(x,y)
# plt.show()
# print(numerical_difference(function_1,5.0))
# print(numerical_difference(function_1,10.0))
def numerical_gradient(f,x):
    h = 1e-4
    grad = np.zeros_like(x) # x와 형상이 같은 배열을 생성
    for i in range(x.size):
        xi = x[i]
        x[i] = xi + h
        fx1 = f(x)
        x[i] = xi - h
        fx2 = f(x)
        grad[i] = (fx1 - fx2)/ (2*h)
        x[i] = xi
    return grad

def f2(x):
    f2 = 0
    for i in range(x.size):
        f2 += x[i]**2
    return f2

# x = np.array([3.0, 4.0])
# print(numerical_gradient(f2,x))

def gradient_descent(f, init_x, lr=0.1, epoch = 100):
    x = init_x
    for i in range(epoch):
        x -= lr * numerical_gradient(f,x)
    return x

print(gradient_descent(f2, np.array([3.0, 4.0])))
print(gradient_descent(f2, np.array([3.0, 4.0]),10))
print(gradient_descent(f2, np.array([3.0, 4.0]),1e-5))

class simpleNet:
    def __init__(self):
        self.W = np.random.randn(2,3)
    def predict(self, x):
        return np.dot(x,self.W)
    def loss(self,x,t):
        z = self.predict(x)
        y = softmax(z)
        loss = cross_entropy_error(y, t)
        return loss
    
# 오차역전파

