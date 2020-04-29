import numpy as np
from dataset.mnist import load_mnist
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split, cross_val_score
import math
import knn
import sys, os
from PIL import Image

if __name__ == "__main__":
    sys.path.append(os.pardir)  # 부모 디렉토리에서 import할 수 있도록 설정
    # train 과 test 데이터 분리

    (x_train, t_train), (x_test, t_test) = \
        load_mnist(flatten=True, normalize=True)
    y_name = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
#    image = image.reshape(28, 28)
    size = 100
    sample = np.random.randint(0, t_test.shape[0], size)
    # hand crafted feature
    # 2차원으로 reshape 후 각 행마다 mark를 count 이후 train의 각 행 mark count와 비교
    k = [3]
    knn_mnist = knn.KNN(x_train, t_train, y_name)
    # weighted majority vote 시작
    print("weighted majority vote")
    success = 0
    for j in sample:
        knn_mnist.caculate_distance(x_test[j:j+1],x_train)
        weight = knn_mnist.weighted_majority_vote()
        print("{}th data result {}, label {}"
              .format(j, weight, knn_mnist.get_name(t_test[j:j+1])))
        if(weight == knn_mnist.get_name(t_test[j:j+1])):
            success += 1
    accuracy = float(success/size)
    print("accuracy = {}".format(accuracy))

    # hand_craft 첫 번째
    print("hand_craft")
    knn_mnist.set_train_craft()
    for i in k:
        knn_mnist.set_k(i)
        print("K = {}".format(i))
        success = 0
        for j in sample:
            knn_mnist.set_test_craft((x_test[j]))
            hand_craft = knn_mnist.hand_craft()
            print("{}th data result {}, label {}".format(j, hand_craft  , knn_mnist.get_name(t_test[j])))
            if (hand_craft == knn_mnist.get_name(t_test[j])):
                success += 1
        accuracy = float(success / size)
        print("accuracy = {}".format(accuracy))
    # hand_craft 두 번째
    print("hand_craft2")
    knn_mnist.set_train_craft2()
    for i in k:
        knn_mnist.set_k(i)
        print("K = {}".format(i))
        success = 0
        for j in sample:
            knn_mnist.set_test_craft2((x_test[j]))
            hand_craft = knn_mnist.hand_craft()
            print("{}th data result {}, label {}".format(j, hand_craft, knn_mnist.get_name(t_test[j])))
            if (hand_craft == knn_mnist.get_name(t_test[j])):
                success += 1
        accuracy = float(success / size)
        print("accuracy = {}".format(accuracy))
    """
    # majority vote 시작
    print("majority vote")
    success = 0
    for j in sample:
        knn_mnist.caculate_distance(x_test[j:j+1],x_train[0:100])
        majority = knn_mnist.majority_vote()
        print("{}th data result {}, label {}"
              .format(j, majority, knn_mnist.get_name(t_test[j:j+1])))
        if(majority == knn_mnist.get_name(t_test[j:j+1])):
            success += 1
    accuracy = float(success/size)
    print("accuracy = {}".format(accuracy))
    """