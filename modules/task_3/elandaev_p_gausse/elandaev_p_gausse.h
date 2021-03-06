// Copyright 2020 Elandaev Pavel

#ifndef MODULES_TASK_2_ELANDAEV_P_GAUSSE_ELANDAEV_P_GAUSSE_H_
#define MODULES_TASK_2_ELANDAEV_P_GAUSSE_ELANDAEV_P_GAUSSE_H_

#include <vector>
#include <string>

//std::vector<int> getRandomVector(int  sz);
//int getParallelOperations(std::vector<int> global_vec,
//                          int count_size_vector);
//int getSequentialOperations(std::vector<int> vec, int sz);

const int gaussianRadius = 1;
const int gaussianSize = 3;
const int gaussianKernel[] = {
    1, 2, 1,
    2, 4, 2,
    1, 2, 1
};
const int gaussianNorm = 16;

std::vector<double> getRandomImage(int rows, int cols);
std::vector<double> getSequentialOperations(std::vector<double> image, int rows, int cols);
std::vector<double> getParallelOperations(std::vector<double> global_image, int rows, int cols);


#endif  // MODULES_TASK_1_ELANDAEV_P_GAUSSE_ELANDAEV_P_GAUSSE_H_
