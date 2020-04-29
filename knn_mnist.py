import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_iris
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split, cross_val_score
import math

class KNN:
    def __init__(self, X_train, y_train, y_name):
        self.k = 1                  # k-nearest neighbor 의 k 값
        self.X_train = X_train      # train x 데이터
        self.y_train = y_train      # train y 데이터
        self.y_name = y_name        # y 값에 대응되는 y_name 9종류
        self.distance = []          # 거리계산 결과를 갖는 list
        self.mark_point_train = []  # train의 행과 열의 marking 갯수를 저장하는 list
        self.mark_point_test = []   # test의 행과 열의 marking 갯수를 저장하는 list
        self.feature = 0            # feature 수를 저장하는 인자

    def set_k(self,k):
        self.k = k

    def caculate_distance(self, X_test, x_train):
        result_distance = []
        # 거리 계산 결과, 해당 index(행) 저장하기 위한 list / [거리, train_idx]
        # X_test의 input x1,x2,x3,x4에 전달 ( main에서 한 행씩 입력으로 준다 )
        for i in X_test:
            index = 0
            for j in x_train:
                distance = 0
                distance += (i - j)**2
                sum_dist = 0
                sum_dist = sum(distance)
                sqrt_dist = math.sqrt(sum_dist)
                result_distance.append([sqrt_dist, index])
                index += 1
            # [거리,index]를 list에 저장
        self.distance = result_distance

    def majority_vote(self):
        sorted_dist = sorted(self.distance)
        # 계산된 거리를 기준으로 오름차순 정렬 (거리 가장 짧은 순서 )
        result = []
        # 거리가 가장 짧은 순서 k개 train index를 저장할 list
        i = 0
        while i < self.k:
            result.append(sorted_dist[i][1])
            # k개 가까운 점의 train index를 result list에 append한다
            i += 1
        # k개 점 중에서, 해당 숫자가 나타난 횟수를 저장하기 위한 변수
        check_num = [0 for i in range(len(self.y_name))]
        for i in range(len(result)):
        # result의 수, 즉 k개 만큼 반복하면서, 해당 숫자의 등장 횟수 저장
            index = self.y_train[result[i]]
            check_num[index] += 1
        check = []
        for i in range(len(self.y_name)):
            check.append(check_num[i])
        # check 횟수 중 가장 많이 나타난 숫자를 return , majority vote인 결과를 return
        return self.get_name(check.index(max(check)))

    def weighted_majority_vote(self):
        sorted_dist = sorted(self.distance)
        # 계산된 거리를 기준으로 오름차순 정렬 (거리 가장 짧은 순서 )
        result = []
        # 거리가 가장 짧은 순서 k개 train index를 저장할 list
        i = 0
        while i < self.k:
            result.append(sorted_dist[i][1])
            # k개 가까운 점들의 index를 result 리스트에 append한다
            i += 1
        # k개 점 중에서, 해당 숫자가 나타난 횟수를 저장하기 위한 변수
        check_num = [0 for i in range(len(self.y_name))]
        for i in range(len(result)):
        # result의 수, 즉 k개 만큼 반복하면서, 나타난 횟수를 가중치와 곱해서 저장
        # weight = 1/distance라 할 때, 해당 숫자면, 가중치를 check로 넣어준다
            index = self.y_train[result[i]]
            check_num[index] += 1 * (1/sorted_dist[i][0])
        check = []
        for i in range(len(self.y_name)):
            check.append(check_num[i])
        # check 횟수 중 가중치가 가장 큰 숫자를 return
        return self.get_name(check.index(max(check)))

    def get_name(self, index):
        # y_train 결과를 y_name으로 변환하기 위한 함수
        result = []
        for i in range(len(self.y_name)):
            if index == i:
                return(self.y_name[i])

    def set_train_craft(self):
        # train전체 데이터에 대해서 feature수 변환을 수행
        self.feature = 56
        mark_point_train = []
        for i in range(len(self.X_train)):
            x_train_reshape = self.X_train[i:i + 1].reshape(28, 28)
            result = []
            # 각각의 행과 열의 marking수를 센다 (행 28개, 열 28개 총 56개)
            for i in range(0, 28):
                row_marking = 0
                for j in range(0, 28):
                    if (x_train_reshape[i][j] > 0):
                        row_marking += 1
                result.append(row_marking)
            for i in range(0, 28):
                col_marking = 0
                for j in range(0, 28):
                    if (x_train_reshape[j][i] > 0):
                        col_marking += 1
                result.append(col_marking)
            # 해당 행과 열의 marking수를 센 result를 append
            mark_point_train.append(result)
        # mark_point_train이 list 이기 때문에 nparray로 변환
        self.mark_point_train = np.array(mark_point_train)

    def set_test_craft(self,x_test):
        # test 데이터에 대해서 feature수 변환을 수행
        mark_point_test = []
        x_test_reshape = x_test.reshape(28, 28)
        result = []
        #각각의 행과 열의 marking 수를 센다 (행 28개, 열 28개 총 56개)
        for i in range(0,28):
            row_marking = 0
            for j in range(0,28):
                if (x_test_reshape[i][j] > 0):
                    row_marking += 1
            result.append(row_marking)
        for i in range(0,28):
            col_marking = 0
            for j in range(0,28):
                if(x_test_reshape[j][i] >0):
                    col_marking += 1
            result.append(col_marking)
        # 해당 행과 열의 marking수를 센 result를 append
        mark_point_test.append(result)
        # mark_point_test가 list 이기때문에 nparray로 변환
        self.mark_point_test = np.array(mark_point_test)


    def set_train_craft2(self):
        # train 전체 데이터에 대해서 feature수 변환을 수행
        self.feature = 49
        mark_point_train = []
        for i in range(len(self.X_train)):
            x_train_reshape = self.X_train[i:i + 1].reshape(28, 28)
            row_result = []
            # 4x4 행렬을 하나의 feature로 7x7행렬로 변환
            for i in range(0, 7):
                row_marking = 0
                for j in range(0, 7):
                    # 4x4행렬(1개의 feature)의 marking수를 센다
                    for k in range(0,4):
                        if (x_train_reshape[i*4][j*4+k] > 0):
                            row_marking += 1
                    row_result.append(row_marking)
            # 7x7 행렬에 대해서 각각의 marking수(feature)를 저장한다
            mark_point_train.append(row_result)
        self.mark_point_train = np.array(mark_point_train)

    def set_test_craft2(self,x_test):
        # test 데이터에 대해서 feature수 변환을 수행
        mark_point_test = []
        x_test_reshape = x_test.reshape(28, 28)
        row_result = []
        # 4x4 행렬을 하나의 feature로 7x7행렬로 변환
        for i in range(0,7):
            row_marking = 0
            for j in range(0,7):
                # 4x4행렬(1개의 feature)의 marking수를 센다
                for k in range(0,4):
                    if (x_test_reshape[i*4][j*4+k] > 0):
                        row_marking += 1
                row_result.append(row_marking)
        # 7x7 행렬에 대해서 각각의 marking수(feature)를 저장한다
        mark_point_test.append(row_result)
        self.mark_point_test = np.array(mark_point_test)

    def hand_craft(self):
        # feature수가 49개 (hand_craft 두 번째 방법) 일때
        if self.feature == 49:
            # 49개 feature에 대해서 거리게산을 한다
            self.caculate_distance(self.mark_point_test, self.mark_point_train)
            # 거리계산후, majority_vote()를 진행
            majority = self.majority_vote()
            return majority
        # feature수가 56개 (hand_craft 첫 번째 방법) 일때
        if self.feature == 56:
            # 56개 feature에 대해서 거리계산을 한다
            self.caculate_distance(self.mark_point_test, self.mark_point_train)
            # 거리계산후, majority_vote()를 진행
            majority = self.majority_vote()
            return majority