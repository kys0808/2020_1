import numpy as np
import matplotlib.pyplot as plt


# 1
X = np.arange(0.01, 1, 0.01)
y1 = np.exp(X)
y2 = -1*np.log(X)

plt.plot(X, y1, label="exponential")
plt.plot(X, y2, linestyle="--", label="log")
plt.xlabel('X')
plt.ylabel('Y')
plt.title("exp & -log")
plt.legend()
plt.show()

# 2
X = np.array([[0, 0],
             [0, 1],
             [1, 0],
             [1, 1]])
def AND(x):
    w = np.array([0.5, 0.5])
    b = -0.7
    return int((np.sum(w*x) + b) >= 0)

def OR(x):
    w = np.array([0.6, 0.6])
    b = -0.5
    return int((np.sum(w*x) + b) >= 0)

def NAND(x):
    w = np.array([-0.6, -0.6])
    b = 1.0
    return int((np.sum(w*x)+b) >= 0)

print("AND")
for i in range(len(X)):
    print(X[i][0], X[i][1], AND(X[i]))
print("OR")
for i in range(len(X)):
    print(X[i][0], X[i][1], OR(X[i]))
print("NAND")
for i in range(len(X)):
    print(X[i][0], X[i][1], NAND(X[i]))



