// Copyright 2020 Elandaev Pavel

#ifndef MODULES_TASK_2_ELANDAEV_P_REDUCE_ELANDAEV_P_REDUCE_H_
#define MODULES_TASK_2_ELANDAEV_P_REDUCE_ELANDAEV_P_REDUCE_H_

#include <vector>
#include <string>
#include <mpi.h>

int Reduce(void *sendbuf, void *recvbuf, int count, MPI_Datatype type, MPI_Op op, int root, MPI_Comm comm);


#endif  // MODULES_TASK_1_ELANDAEV_P_REDUCE_ELANDAEV_P_REDUCE_H_
