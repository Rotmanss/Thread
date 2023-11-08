#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <semaphore>
#include <syncstream>


class Manager
{
public:
    Manager() :
        sem_ad(0), sem_ae(0), sem_bcf(0), sem_bcg(0), sem_dfh(0), sem_dfi(0), sem_eg(0), sem_i(0), sem_j(0), sem_thread(4)
    {
        threads.reserve(nt);
    }

    ~Manager()
    {
    }

    void LaunchThreads();

private:
    void SafeOutput(const std::string& message) const;

    void Function(char x, int i) const;
    void ProcessSet(char x, int quantity) const;

private:
    const int nt = 4;
    const int a = 9, b = 5, c = 5, d = 9, e = 8, f = 5, g = 5, h = 4, i = 9, j = 7;

    std::vector<std::jthread> threads;

    std::binary_semaphore sem_ad;
    std::binary_semaphore sem_ae;
    std::binary_semaphore sem_bcf;
    std::binary_semaphore sem_bcg;
    std::binary_semaphore sem_dfh;
    std::binary_semaphore sem_dfi;
    std::binary_semaphore sem_eg;
    std::binary_semaphore sem_i;
    std::binary_semaphore sem_j;

    std::counting_semaphore<4> sem_thread;
};
