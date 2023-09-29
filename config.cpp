#include "config.h"

Config::Config(){
    //Port number, default 9006
    PORT = 9006;

    //Logging write mode, default synchronous
    LOGWrite = 0;

    //Trigger combination mode, default listenfd LT + connfd LT
    TRIGMode = 0;

    //listenfd trigger mode, default LT
    LISTENTrigmode = 0;

    //connfd trigger mode, default LT
    CONNTrigmode = 0;

    //Graceful shutdown of connections, default not used
    OPT_LINGER = 0;

    //Number of database connections in the connection pool, default 8
    sql_num = 8;

    //Number of threads in the thread pool, default 8
    thread_num = 8;

    //Close logging, default do not close
    close_log = 0;

    //Concurrency model, default is proactor
    actor_model = 0;
}

void Config::parse_arg(int argc, char*argv[]){
    int opt;
    const char *str = "p:l:m:o:s:t:c:a:";
    while ((opt = getopt(argc, argv, str)) != -1)
    {
        switch (opt)
        {
        case 'p':
        {
            PORT = atoi(optarg);
            break;
        }
        case 'l':
        {
            LOGWrite = atoi(optarg);
            break;
        }
        case 'm':
        {
            TRIGMode = atoi(optarg);
            break;
        }
        case 'o':
        {
            OPT_LINGER = atoi(optarg);
            break;
        }
        case 's':
        {
            sql_num = atoi(optarg);
            break;
        }
        case 't':
        {
            thread_num = atoi(optarg);
            break;
        }
        case 'c':
        {
            close_log = atoi(optarg);
            break;
        }
        case 'a':
        {
            actor_model = atoi(optarg);
            break;
        }
        default:
            break;
        }
    }
}