#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <list>
#include <cstdio>
#include <exception>
#include <pthread.h>
#include "../lock/locker.h"
#include "../CGImysql/sql_connection_pool.h"

template <typename T>
class threadpool
{
public:
    //thread_number is the number of threads in the thread pool, 
    //max_requests is the maximum number of requests waiting to be processed in the request queue.
    threadpool(int actor_model, connection_pool *connPool, int thread_number = 8, int max_request = 10000);
    ~threadpool();
    bool append(T *request, int state);
    bool append_p(T *request);

private:
    //Worker thread function, which continuously removes tasks from the work queue and executes them
    static void *worker(void *arg);
    void run();

private:
    int m_thread_number;        //The number of threads in thread pool
    int m_max_requests;         //The max number of requests in request queue
    pthread_t *m_threads;       //An Array describing the thread pool with size m_thread_number
    std::list<T *> m_workqueue; //request queue
    locker m_queuelocker;       //Mutex protecting request queue
    sem m_queuestat;            //Whether has tasks to handle
    connection_pool *m_connPool;  //database connection pool
    int m_actor_model;          //Model switch
};

#endif