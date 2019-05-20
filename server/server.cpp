#include "server.h"

// void IDuser(numberUer user)
// {
//     cout << "nhap name user for account";
//     cin >> user.user;
//     cout << "nhap password for account";
//     cin >> user.password;
// }

// void idBank(IDbank id)
// {
//     cout << "nhap so tai khoan ngan hang";
//     cin >> id.ID;
//     cout << "nhap ten ngan hang";
//     cin >> id.nameBank;
// }

bool checkBank()
{
    int numID = atoi(recvID);
    //kiem tra ma the ngan hang
    if (numID > 10)
        return true;
    return false;
}

void PrintBank()
{
    checkBank() ? cout << "hop le" << endl : cout << "khong hop le";
}
// int numberAccount()
// {
//     int n;
//     cout << "nhap so luonmg client";
//     cin >> n;
//     return n;
// }

string getFile(string fileName)
{
    string buffer;
    char c;
    ifstream in(fileName);
    if (!in)
    {
        cout << fileName << " not found";
        exit(1);
    }
    while (in.get(c))
        buffer += c;
    in.close();

    return buffer;
}

vector<string> getDataId(const string &text, string idTag)
{
    vector<string> collection;
    int pos = 0, start;

    while (true)
    {
        start = text.find("<" + idTag, pos);
        if (start == string::npos)
            return collection;
        start = text.find(">", start);
        start++;

        pos = text.find("</" + idTag, start);
        if (pos == string::npos)
            return collection;
        collection.push_back(text.substr(start, pos - start));
    }
}

vector<string> getDataName(const string &text, string nameTag)
{
    vector<string> collection;
    unsigned int pos = 0, start;

    while (true)
    {
        start = text.find("<" + nameTag, pos);
        if (start == string::npos)
            return collection;
        start = text.find(">", start);
        start++;

        pos = text.find("</" + nameTag, start);
        if (pos == string::npos)
            return collection;
        collection.push_back(text.substr(start, pos - start));
    }
}

vector<string> getDataPrice(const string &text, string priceTag)
{
    vector<string> collection;
    unsigned int pos = 0, start;

    while (true)
    {
        start = text.find("<" + priceTag, pos);
        if (start == string::npos)
            return collection;
        start = text.find(">", start);
        start++;

        pos = text.find("</" + priceTag, start);
        if (pos == string::npos)
            return collection;
        collection.push_back(text.substr(start, pos - start));
    }
}

void stripTagID(string &testID)
{
    unsigned int start = 0, pos;
    while (start < testID.size())
    {
        start = testID.find("<", start);
        if (start == string::npos)
            break;
        pos = testID.find(">", start);
        if (pos == string::npos)
            break;
        testID.erase(start, pos - start + 1);
    }
}

void stripTagName(string &testName)
{
    unsigned int start = 0, pos;
    while (start < testName.size())
    {
        start = testName.find("<", start);
        if (start == string::npos)
            break;
        pos = testName.find(">", start);
        if (pos == string::npos)
            break;
        testName.erase(start, pos - start + 1);
    }
}

void stripTagPrice(string &testPrice)
{
    unsigned int start = 0, pos;
    while (start < testPrice.size())
    {
        start = testPrice.find("<", start);
        if (start == string::npos)
            break;
        pos = testPrice.find(">", start);
        if (pos == string::npos)
            break;
        testPrice.erase(start, pos - start + 1);
    }
}

// void stripTagPrice(string &testPrice)
// {
//     unsigned int start = 0, pos;
//     while (start < testPrice.size())
//     {
//         start = testPrice.find("<", start);
//         if (start == string::npos)
//             break;
//         pos = testPrice.find(">", start);
//         if (pos == string::npos)
//             break;
//         testPrice.erase(start, pos - start + 1);
//     }
// }
void readItemList()
{
    int id, price;
    string fileName = "itemList.xml";
    string idTag = "id";
    string priceTag = "price";
    string nameTag = "name";
    bool stripOtherTagsId = true;
    bool stripOtherTagsName = true;
    bool stripOthertagsPrice = true;

    string textID = getFile(fileName);
    vector<string> allID = getDataId(textID, idTag);
    for (string &s : allID)
    {
        if (stripOtherTagsId)
            stripTagID(s);
        cout << s << '\n';
    }

    string textName = getFile(fileName);
    vector<string> allName = getDataName(textName, nameTag);
    for (string &s : allName)
    {
        if (stripOtherTagsName)
            stripTagName(s);
        cout << s << endl;
    }

    string textPrice = getFile(fileName);
    vector<string> allPrice = getDataPrice(textPrice, priceTag);
    for (string &s : allPrice)
    {
        if (stripOthertagsPrice)
            stripTagPrice(s);
        cout << s << endl;
    }
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
// void auctionBuyers(Buyers peolpe)
// {
//     Buyers userBuy;
//     int numPrice[sizeof(userBuy)];
//     cout << "Enter the order code:";
//     cin >> peolpe.idBuyer;
//     cout << "Enter the valuation amount";
//     cin >> peolpe.priceBuyer;
// }
// void checkAuction()
// {
//     string numberId;
//     string numberPrice;
//     int numPrice[50];
//     string fileName = "itemList.xml";
//     string getPrice = getFile(fileName);
//     vector<string> price = getDataPrice(getPrice, numberPrice);
//     string *new_price = &price[0];

//     int numUserBuy = stoi(userBuy.priceBuyer);
//     //ep kieu vector sang mang tinh la gia tri id hang hoa
//     string getId = getFile(fileName);
//     vector<string> id = getDataId(getId, numberId);
//     string *new_id = &id[0];
//     for (int i = 0; i < sizeof(new_id); i++)
//     {
//         if (userBuy.idBuyer == new_id[i])
//         {
//             // ep chuoi mang sang mang int
//             for (int j = 0; j < sizeof(userBuy); j++)
//             {
//                 numberPrice[j] = stoi(new_price[j].c_str());
//                 if (numUserBuy > numberPrice[j])
//                 {
//                 }
//                 else
//                 {
//                 }
//             }
//         }
//     }
// }
// void compareAuctions()
// {
// }
// void converStringToInt(string strings[], int ints[])
// {
//     for (int i = 1; i < sizeof(); i++)
//     {
//     }
// }
int main(int argc, char *argv[])
{
    char server_message[256] = "you have reached the server";
    char sendbuff[256];    // buffer send data
    char recvbuff[256];    //bufferto read data
    int server_socket;     //socket server tạo ra để nghe kết nối
    int new_server_socket; //socket tạo ra khi server chấp nhận một kết nối từ client
    int len;               //chieu dai cua kich thuoc cua client
    int client_socket;
    struct sockaddr_in server_address; // dia chi cua server duoc luu tru
    struct sockaddr_in client_address; //dia chi cua client duoc luu tru
    string fileName = "itemList.xml";  //doc file xml
    int id, price;
    bool stripOtherTagsId = true;    //kiem tra tag ma id trong danh sach don hang
    bool stripOtherTagsPrice = true; //kiem tra tag price trong danh sach don hang
    //char *IP = "192.168.51.100";
    //Buyers userBuy;
    string numberId;
    string numberPrice;
    //IDbank peopleID;
    int numPrice[50];
    char announceVictory[51] = "ban la nguoi chien thang trong cuoc dau gia  ";
    char NoticeLoss[51] = "ban la nguoi thua trong cuoc dau gia ";
    bool checkBank = true;
    // string ID[50];
    // string PRICE[51];
    //create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) //cheack socket
    {
        perror("error socket"); //bao loi
    }
    //defines the server address
    server_address.sin_family = AF_INET;         //thiet lap giao thuc thuc ip la ipv4
    server_address.sin_addr.s_addr = INADDR_ANY; //xac dinh ip trong giao thuc
    //inet_pton(AF_INET, IP, server_address->sin_addr);
    server_address.sin_port = htons(PORT); //xac dinh duong port trong giao thuc giuawx server a client
    //initialize device value
    memset(&server_address, '0', sizeof(server_address));
    memset(&client_address, '0', sizeof(client_address));
    memset(announceVictory, '0', sizeof(announceVictory));
    memset(NoticeLoss, '0', sizeof(NoticeLoss));

    // memset(IDuser, 0, 100);
    // memset(idBank, 0, 100);
    // memset(auctionBuyers, 0, 100);
    //memset(numberUer, "0", sizeof(numberAccount));
    //bind the socket to our specifiled IP and PORT
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("bind error");
    }
    //listenning from server to client
    listen(server_socket, 5);     //tao toi da 5 backlog trong hang doi
    len = sizeof(client_address); // lay thong tin tu phia client sang server

    //khoi tao bo nho cho du lieu doc
    memset(recvUser, 0, 50);
    memset(recvPassword, 0, 50);
    memset(recvID, 0, 10);
    memset(recvNameBank, 0, 50);
    memset(recvPriceBuyer, 0, 50);
    memset(recvIdBuyer, 0, 50);

    //khoi tao du lieu cho du lieu gui
    memset(senduser, '0', 50);
    memset(sendpassword, '0', 50);
    memset(sendIDBank, '0', 10);
    memset(sendnameBank, '0', 50);
    memset(sendidBuyer, '0', 50);
    memset(sendpriceBuyer, '0', 50);
    //danh sach cac don hang dau gia
    readItemList();
    //server send 1 for from server to client
    while (1)
    {
        cout << "server is listening a port" << PORT << endl;
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&len);
        if (client_socket < 0)
        {
            perror("error accpet");
            continue;
        }
        char clinet_send[256];
        inet_ntop(client_address.sin_family, (struct sockaddr *)&client_address, clinet_send, sizeof(clinet_send));
        cout << "server got connection from" << clinet_send;
        //client_socket *client = new client_socket[n];
        //so luong client duoc ket noi den server
        //int accontPeople = read(client_socket, &IDuser, sizeof(IDuser));
        int accountPeopleUser = read(client_socket, recvUser, sizeof(recvUser));
        int accountPeoplePassword = read(client_socket, recvID, sizeof(recvID));
        // if (!accountPeopleUser)
        // {
        //     write(client_socket, senduser, sizeof(senduser));
        // }
        do
        {
            write(client_socket, senduser, 50);
        } while (!accountPeopleUser);
        //if (!accontPeople)
        //{
        //write(client_socket, "yeu cau nhap tao lai tai khoan", 100);
        //    send(client_socket, IDuser, 20, 0);
        //}
        //else
        //{
        //write(client_socket, "tao tai khoan thanh cong", 100);
        //}
        //int account = sendto(client_socket, IDuser, 10, 0, );
        //int timeOut = write(client_socket, timerCountdown, sizeof(timerCountdown));
        //int user = read(client_socket, auctionBuyers, sizeof(auctionBuyers));
        int readerIntID = read(client_socket, recvIdBuyer, 50);
        int readerIntPrice = read(client_socket, recvPriceBuyer, 50);
        // ep kieu vector sang mang tinh lay gia tri tien cua hang hong
        string getPrice = getFile(fileName);
        vector<string> price = getDataPrice(getPrice, numberPrice);
        int nPrice = price.size();
        string *new_price = &price[0];

        int numUserBuy = stoi(recvPriceBuyer);
        //ep kieu vector sang mang tinh la gia tri id hang hoa
        string getId = getFile(fileName);
        vector<string> id = getDataId(getId, numberId);
        int nID = id.size();
        string *new_id = &id[0];

        //chuyen int sangs tring
        //chuyen id
        string readStringID;
        ostringstream convertID;
        convertID << readerIntID;
        readStringID = convertID.str();
        //chuyen price
        string readstringPrime;
        ostringstream convertPrice;
        convertPrice << readerIntPrice;
        readstringPrime = convertPrice.str();
        for (int i = 0; i < nID; i++)
        {
            if (readStringID == new_id[i])
            {
                // ep chuoi mang sang mang int
                for (int j = 0; j < nPrice; j++)
                {
                    numberPrice[j] = atoi(new_price[j].c_str());
                    if (readerIntPrice > numberPrice[j])
                    {
                        write(client_socket, announceVictory, sizeof(announceVictory));
                    }
                    else
                    {
                        write(client_socket, NoticeLoss, sizeof(NoticeLoss));
                    }
                }
            }
            else
            {
                perror("Ma don hang khong ton tai");
                exit(0);
            }
        }
        //int checkUser = write(client_socket, checkAuction, sizeof(checkAuction));
        // int userBank = read(client_socket, idBank, 100);
        int readIdBank = read(client_socket, recvID, 50);
        int readNameBank = read(client_socket, recvNameBank, 50);
        //kiem tra va gui du lieu ve client
        do
        {
            int sendID = write(client_socket, sendIDBank, 10);
        } while (readIdBank > 10);
        //write(client_socket, PrintBank, 100);

        close(client_socket);
        sleep(1);
    }
    //close socket
    close(server_socket);
    return 0;
}