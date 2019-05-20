#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include <future>
#include <functional>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/signal.h>
#include <sys/uio.h>
#include <fstream>
#include <vector>
#include <ostream>
#include <sstream>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <sstream>
//#include <libxml/xmlreader.h>
#define PORT 8080
using namespace std;

//read data
char recvUser[50];
char recvPassword[50];
char recvID[10];
char recvNameBank[50];
char recvIdBuyer[50];
char recvPriceBuyer[50];

//send data
char senduser[50];
char sendpassword[50];
char sendIDBank[10];
char sendnameBank[50];
char sendidBuyer[50];
char sendpriceBuyer[50];

#endif // SERVER_H
