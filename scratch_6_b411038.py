import numpy as np
from functions import sigmoid, softmax

class TwoLayerNeuralNetwork1():
    """ a neural network with one hidden layer"""
    def __init__(self ,input_size, hidden_size, output_size):
        """ initialize attributes W1, b1, W2,b2"""
        self.params = {}
        # W1 : x --> hidden layer
        self.params['W1'] = np.random.randn(input_size, hidden_size)
        self.params['b1'] = np.random.randn(hidden_size)
        # W2 : hidden layer --> output layer
        self.params['W2'] = np.random.randn(hidden_size, output_size)
        self.params['b2'] = np.random.randn(output_size)

        self.input_size = input_size
        self.output_size = output_size

        def predict(self, x):
            """ given input x, calculate output using current parameters: W1,b1,W2,b2"""
            # input --> hidden layer
            z2 = np.dot(x, self.params['W1']) + self.params['b1']
            a2 = sigmoid(z2)
            # hidden layer --> output
            z3 = np.dot(a2, self.params['W2']) + self.params['b2']
            y = softmax(z3)

            return y
