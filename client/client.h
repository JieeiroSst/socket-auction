#ifndef CLIENT_H
#define CLIENT_H
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
#include <ostream>
#include <sstream>
#include <algorithm>
#include <vector>
#define PORT 8080
using namespace std;

// struct numberUer
// {
//   string user;
//   int password;
// };
// struct IDbank
// {
//   int ID;
//   string nameBank;
// };
// struct Buyers
// {
//   string idBuyer;
//   string priceBuyer;
// };
//send data
char senduser[50];
char sendpassword[50];
char sendIDBank[10];
char sendnameBank[50];
char sendidBuyer[50];
char sendpriceBuyer[50];

//read data
char recvUser[50];
char recvPassword[50];
char recvIDBank[10];
char recvNameBank[50];
char recvIdBuyer[50];
char recvPriceBuyer[50];

void timerCountdown();
#endif // CLIENT_H
