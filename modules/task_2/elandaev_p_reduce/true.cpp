// Copyright 2020 Elandaev Pavel

#include <mpi.h>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>
#include "../../../modules/task_2/elandaev_p_reduce/elandaev_p_reduce.h"

int Reduce(void *sendbuf, void *recvbuf, int count, MPI_Datatype type, MPI_Op op, int root, MPI_Comm comm) {
    if (sendbuf == nullptr || recvbuf == nullptr || sendbuf == recvbuf)
        return MPI_ERR_BUFFER;
    if (count <= 0)
        return MPI_ERR_COUNT;
    if (op != MPI_MAX && op != MPI_MIN && op != MPI_SUM && op != MPI_PROD)
        return MPI_ERR_OP;
    if (comm != MPI_COMM_WORLD && comm != MPI_COMM_SELF)
        return MPI_ERR_COMM;

    int size, rank;
    MPI_Comm_size(comm, &size);
    MPI_Comm_rank(comm, &rank);

    void* buffer;

    if (type == MPI_INT) {
        buffer = new int[count];
        std::memcpy(recvbuf, sendbuf, count * sizeof(int));
    } else if (type == MPI_FLOAT) {
        buffer = new float[count];
        std::memcpy(recvbuf, sendbuf, count * sizeof(float));
    } else if (type == MPI_DOUBLE) {
        buffer = new double[count];
        std::memcpy(recvbuf, sendbuf, count * sizeof(double));
    } else {
        return MPI_ERR_TYPE;
    }
    
    if(rank != root){
        MPI_Send(recvbuf, count, type, root, 0, comm);
    }
    
    if(rank == root){
        MPI_Status status;
        MPI_Recv(buffer, count, type, rank, 0, comm, &status);
        if (datatype == MPI_INT) {
            if (op == MPI_MAX) {
                for (int j = 0; j < count; ++j) {
                    if (static_cast<int *>(recvbuf)[j] < static_cast<int *>(buffer)[j])
                        static_cast<int *>(recvbuf)[j] = static_cast<int *>(buffer)[j];
                }
            } else if (op == MPI_MIN) {
                for (int j = 0; j < count; ++j) {
                    if (static_cast<int *>(recvbuf)[j] > static_cast<int *>(buffer)[j])
                        static_cast<int *>(recvbuf)[j] = static_cast<int *>(buffer)[j];
                }
            } else if (op == MPI_SUM) {
                for (int j = 0; j < count; ++j) {
                    static_cast<int*>(recvbuf)[j] += static_cast<int*>(buffer)[j];
                }
            } else if (op == MPI_PROD) {
                for (int j = 0; j < count; ++j) {
                    static_cast<int *>(recvbuf)[j] *= static_cast<int *>(buffer)[j];
                }
            }
        } else if (datatype == MPI_FLOAT) {
            if (op == MPI_MAX) {
                for (int j = 0; j < count; ++j) {
                    if (static_cast<float *>(recvbuf)[j] < static_cast<float *>(buffer)[j])
                        static_cast<float *>(recvbuf)[j] = static_cast<float *>(buffer)[j];
                }
            } else if (op == MPI_MIN) {
                for (int j = 0; j < count; ++j) {
                    if (static_cast<float *>(recvbuf)[j] > static_cast<float *>(buffer)[j])
                        static_cast<float *>(recvbuf)[j] = static_cast<float *>(buffer)[j];
                }
            } else if (op == MPI_SUM) {
                for (int j = 0; j < count; ++j) {
                    static_cast<float *>(recvbuf)[j] += static_cast<float *>(buffer)[j];
                }
            } else if (op == MPI_PROD) {
                for (int j = 0; j < count; ++j) {
                    static_cast<float *>(recvbuf)[j] *= static_cast<float *>(buffer)[j];
                }
            }
        } else if (datatype == MPI_DOUBLE) {
            if (op == MPI_MAX) {
                for (int j = 0; j < count; ++j) {
                    if (static_cast<double *>(recvbuf)[j] < static_cast<double *>(buffer)[j])
                        static_cast<double *>(recvbuf)[j] = static_cast<double *>(buffer)[j];
                }
            } else if (op == MPI_MIN) {
                for (int j = 0; j < count; ++j) {
                    if (static_cast<double *>(recvbuf)[j] > static_cast<double *>(buffer)[j])
                        static_cast<double *>(recvbuf)[j] = static_cast<double *>(buffer)[j];
                }
            } else if (op == MPI_SUM) {
                for (int j = 0; j < count; ++j) {
                    static_cast<double *>(recvbuf)[j] += static_cast<double *>(buffer)[j];
                }
            } else if (op == MPI_PROD) {
                for (int j = 0; j < count; ++j) {
                    static_cast<double *>(recvbuf)[j] *= static_cast<double *>(buffer)[j];
                }
            }
        }
    }
    if (type == MPI_INT)
        delete[] static_cast<int*>(buffer);
    else if (type == MPI_FLOAT)
        delete[] static_cast<float*>(buffer);
    else if (type == MPI_DOUBLE)
        delete[] static_cast<double*>(buffer);

    return MPI_SUCCESS;
}

