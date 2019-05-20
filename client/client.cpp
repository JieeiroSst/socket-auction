#include "client.h"

// void IDuser()
// {
//     cout << "nhap name user for account";
//     cin >> user;
//     cout << "nhap password for account";
//     cin >> password;
// }

// void idBank()
// {
//     cout << "nhap so tai khoan ngan hang";
//     cin >> ID;
//     cout << "nhap ten ngan hang";
//     cin >> nameBank;
// }

void auctionList()
{
    cout << "--Danh sach cac mat hang dau gia--" << endl;
    cout << "100.laptop asus pro.600" << endl;
    cout << "110.laptop dell.700" << endl;
    cout << "120.laptop acer x100.800" << endl;
    cout << "130.macbook pro 2019.1000" << endl;
    cout << "140.macbook pro 2007.600" << endl;
    cout << "150.macbook pro 2008.800" << endl;
    cout << "160.macbook pro 2009.900" << endl;
    cout << "170.macbook air 2006.700" << endl;
    cout << "180.macbook air 2007.800" << endl;
    cout << "190.macbook air 2008.800" << endl;
    cout << "200.macbook air 2009.800" << endl;
    cout << "210.macbook air 2010.900" << endl;
    cout << "220.macbook air 20011.900" << endl;
    cout << "330.hose Q1.2000" << endl;
    cout << "310.boeing 747.1000000" << endl;
    cout << "330.table apple 2019.900" << endl;
}

void timerCountdown()
{
    int counter = 60;
    sleep(100);
    while (counter >= 1)
    {
        cout << "time  remaining" << counter << endl;
        sleep(100);
        counter--;
    }
}

// void auctionBuyers()
// {
//     cout << "Enter the order code:";
//     cin >> sendidBuyer;
//     cout << "Enter the valuation amount";
//     cin >> sendpriceBuyer;
// }

int main(int argc, char *argv[])
{
    int resendAgainPeple;
    int newAccontPeople;
    int accountPeople;
    // numberUer user;
    // IDbank id;
    // Buyers people;
    //thong bao ket qua dau gia
    char announceVictory[51] = "ban la nguoi chien thang trong cuoc dau gia  ";
    char NoticeLoss[51] = "ban la nguoi thua trong cuoc dau gia ";
    struct sockaddr_in server_address; //Cau truc chua dia chi server ma client can biet de ket noi toi
    //create socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (network_socket < 0)
    {
        perror("connect socket faild");
    }
    //cap phat bo nho
    memset(&server_address, '0', sizeof(server_address));

    //address  for the socket

    server_address.sin_family = AF_INET;         //mac dinh
    server_address.sin_port = htons(PORT);       //cong dich vu
    server_address.sin_addr.s_addr = INADDR_ANY; //dich vu dia chi
    //khoi tao gia tri
    // memset(IDuser, 0, sizeof(IDuser));
    // memset(idBank, 0, sizeof(idBank));
    // memset(auctionBuyers, 0, sizeof(auctionBuyers));
    // memset(announceVictory, '0', sizeof(announceVictory));
    // memset(NoticeLoss, '0', sizeof(NoticeLoss));
    //du lieu doc
    memset(recvUser, 0, 50);
    memset(recvPassword, 0, 50);
    memset(recvIDBank, 0, 10);
    memset(recvNameBank, 0, 50);
    memset(recvPriceBuyer, 0, 50);
    memset(recvIdBuyer, 0, 50);

    memset(announceVictory, 0, 51);
    memset(NoticeLoss, 0, 51);

    //dia chi ip server
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0)
    {
        cout << "inet pton error connect fail" << endl;
        return 1;
    }
    int connection_status = connect(network_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    //check coonect
    if (connection_status == -1)
    {
        cout << "the was an error making a connectinzg to remove socket\n\n";
    }
    //call function connect to server
    if (connect(network_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("connect fialed");
        return 1;
    }

    cout << "chuong trinh dau gia online" << endl;
    cout << "---------------------------------------" << endl;

    cout << "tao tai khoan ket noi voi server" << endl;
    //tao tai khoan dang nhap
    cin >> senduser;
    cout << "nhap password for account";
    cin >> sendpassword;
    //accountPeople = write(network_socket, IDuser, sizeof(IDuser));
    memset(senduser, '0', 50);
    memset(sendpassword, '0', 50);
    int accountUser = write(network_socket, senduser, 50);
    int accountPassword = write(network_socket, sendpassword, 50);
    // if (!recvUser)
    // {
    //     cin >> senduser;
    //     cout << "nhap password for account";
    //     cin >> sendpassword;
    //     int accountUser = write(network_socket, senduser, sizeof(senduser));
    //     int accountPassword = write(network_socket, sendpassword, sizeof(sendpassword));
    // }

    int readRecvUser = read(network_socket, recvUser, 50);
    do
    {
        /* code */
        cin >> senduser;
        cout << "nhap password for account";
        cin >> sendpassword;
        int accountUser = write(network_socket, senduser, sizeof(senduser));
        int accountPassword = write(network_socket, sendpassword, sizeof(sendpassword));
    } while (!readRecvUser);

    //newAccontPeople = read(network_socket, IDuser, sizeof(IDuser));
    //kiem tra tai khoan ben server con ton tai hay khong
    // if (!newAccontPeople)
    // {
    //     IDuser(user);
    //     //neu ton tai thi yeu tao lai tai khoan moi
    //     resendAgainPeple = write(network_socket, IDuser, sizeof(IDuser));
    //     do
    //     {
    //         resendAgainPeple = write(network_socket, IDuser, sizeof(IDuser));
    //     } while (resendAgainPeple < 0);
    // }
    auctionList();

    //int time = read(network_socket, timerCountdown, sizeof(timerCountdown));
    // do
    // {
    //     write(network_socket, auctionBuyers, sizeof(auctionBuyers));

    // } while (time = 0);

    //don dat hang mua do
    memset(sendidBuyer, '0', 50);
    memset(sendpriceBuyer, '0', 50);
    cout << "Enter the order code:";
    cin >> sendidBuyer;
    cout << "Enter the valuation amount";
    cin >> sendpriceBuyer;

    int readVictory = read(network_socket, announceVictory, 51);
    int readLoss = read(network_socket, NoticeLoss, 51);
    if (!readVictory)
    {
        cout << announceVictory << endl;
    }
    if (!readLoss)
    {
        cout << NoticeLoss << endl;
    }

    //write(network_socket, idBank, sizeof(idBank));
    //tai khoang ngan hang
    memset(sendIDBank, '0', 10);
    memset(sendnameBank, '0', 50);
    cout << "nhap so tai khoan ngan hang";
    cin >> sendIDBank;
    cout << "nhap ten ngan hang";
    cin >> sendnameBank;
    int accountID = write(network_socket, sendIDBank, 10);
    int accountNameBank = write(network_socket, sendnameBank, 50);

    //doc du lieu check tu server cua tk ngan hang
    int readIDBank = read(network_socket, recvIDBank, 10);
    int readNameBank = read(network_socket, recvNameBank, 50);
    do
    {
        cout << "nhap so tai khoan ngan hang";
        cin >> sendIDBank;
        cout << "nhap ten ngan hang";
        cin >> sendnameBank;
        int accountID = write(network_socket, sendIDBank, 10);
        int accountNameBank = write(network_socket, sendnameBank, 50);
    } while (!readIDBank);
    //close socket
    close(network_socket);
    return 0;
}