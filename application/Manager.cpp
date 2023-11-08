#include "Manager.h"


void Manager::SafeOutput(const std::string& message) const
{
    std::osyncstream(std::cout) << message << std::endl;
}

void Manager::Function(char x, int i) const
{
    SafeOutput("З набору " + std::string(1, x) + " виконано дiю " + std::to_string(i) + ".");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}


void Manager::ProcessSet(char x, int quantity) const
{
    for (int i = 1; i <= quantity; ++i)
        Function(x, i);
}


void Manager::LaunchThreads()
{
    SafeOutput("Обчислення розпочато.");

    threads.emplace_back([&]() {
        sem_thread.acquire();
        ProcessSet('a', a);
        sem_ad.release();
        sem_ae.release();
        sem_thread.release();
        });

    threads.emplace_back([&]() {
        sem_thread.acquire();
        ProcessSet('b', b);
        sem_thread.release();
        });

    threads.emplace_back([&]() {
        sem_thread.acquire();
        ProcessSet('c', c);
        sem_bcf.release();
        sem_bcg.release();
        sem_thread.release();
        });

    threads.emplace_back([&]() {
        sem_ad.acquire();
        sem_thread.acquire();
        ProcessSet('d', d);
        sem_dfh.release();
        sem_dfi.release();
        sem_thread.release();
        });

    threads.emplace_back([&]() {
        sem_ae.acquire();
        sem_thread.acquire();
        ProcessSet('e', e);
        sem_eg.release();
        sem_thread.release();
        });

    threads.emplace_back([&]() {
        sem_bcf.acquire();
        sem_thread.acquire();
        ProcessSet('f', f);
        sem_thread.release();
        });

    threads.emplace_back([&]() {
        sem_bcg.acquire();
        sem_thread.acquire();
        ProcessSet('g', g);
        sem_thread.release();
        });

    threads.emplace_back([&]() {
        sem_dfh.acquire();
        sem_thread.acquire();
        ProcessSet('h', h);
        sem_thread.release();
        });

    threads.emplace_back([&]() {
        sem_dfi.acquire();
        sem_thread.acquire();
        ProcessSet('i', i);
        sem_i.release();
        sem_thread.release();
        });

    threads.emplace_back([&]() {
        sem_eg.acquire();
        sem_thread.acquire();
        ProcessSet('j', j);
        sem_j.release();
        sem_thread.release();
        });

    threads.emplace_back([&]() {
        sem_i.acquire();
        sem_j.acquire();

        SafeOutput("Обчислення завершено.");
        });

    // Якщо використовуемо thread замість jthread, очікуємо завершення всіх потоків
    // for (auto& t : threads)
    //    t.join();
}