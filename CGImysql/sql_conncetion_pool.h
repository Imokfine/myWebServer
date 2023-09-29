#ifndef SQL_CONNECTION_POOL_H
#define SQL_CONNECTION_POOL_H

class connection_pool{
public:
	MYSQL *GetConnection();				 //Get database connection
	bool ReleaseConnection(MYSQL *con); //Release connection
	int GetFreeConn();					 //Get the total number of free connection
	void DestroyPool();					 //Destroy connection pool

	//Singleon pattern
	static connection_pool *GetInstance();

	void init(string url, string User, string PassWord, string DataBaseName, int Port, int MaxConn, int close_log); 

private:
    connection_pool();
    ~connection_pool();

    int m_MaxConn;  //The number of max connection
	int m_CurConn;  //Current number of connection
	int m_FreeConn; //The number of free connection
	locker lock;
	list<MYSQL *> connList; //connection pool
	sem reserve;

public:
	string m_url;		 //host address
	string m_Port;		 //database port
	string m_User;		 //database username
	string m_PassWord;	 //database password
	string m_DatabaseName; //database name
	int m_close_log;	//log switch
};

class connectionRAII{
public:
	connectionRAII(MYSQL **con, *connPool);
	~connectionRAII();

private:
	MYSQL *conRAII;
	connection_pool *poolRAII;
};

#endif