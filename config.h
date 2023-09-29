#ifndef CONFIG_H
#define CONFIG_H

#include "webserver.h"

using namespace std;

class Config{
public:
    Config();
    ~Config(){};

    void parse_arg(int argc, char*argv[]);

    //Port number
    int PORT;

    //Logging write mode
    int LOGWrite;

    //Trigger combination mode
    int TRIGMode;

    //listenfd trigger mode
    int LISTENTrigmode;

    //connfd trigger mode
    int CONNTrigmode;

    //Graceful shutdown of connections
    int OPT_LINGER;

    //Number of database connections in the connection pool
    int sql_num;

    //Number of threads in the thread pool
    int thread_num;

    //Whether to disable logging
    int close_log;

    //Selection of concurrency model
    int actor_model;
}

#endif