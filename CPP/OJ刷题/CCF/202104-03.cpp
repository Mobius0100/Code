#include <iostream>
#include <string>
#include <map>

using namespace std;

const int Max = 10000;

map<int, string> OccupyName;

int N,T,Tmax,Tmin,Time,n,Lifetime,IP;
string Send_H,Receive_H,Host,Post;
int ipp[Max],expire[Max];

void init()   //初始化
{
    memset(ipp, 0, sizeof(ipp));
    memset(expire, 0, sizeof(expire));
}

void SetExpire(int ipadd)  //设置过期时间
{
    if(Lifetime == 0) expire[ipadd] = Time + T;
    else if(Lifetime >= Tmax + Time) expire[ipadd] = Time + Tmax;
    else if(Lifetime <= Tmin + Time) expire[ipadd] = Time + Tmin;
    else expire[ipadd] = Lifetime;
}

string process(string post) 
{
    if((Receive_H != Host && Receive_H != "*") && post != "REQ") return "";
    if(Receive_H == "*" && post != "DIS") return "";
    if(Receive_H == Host && post == "DIS") return "";

    if(post == "DIS")   //discover报文处理
    {
        int ipadd = -1;
        if(OccupyName[IP] == Send_H)  ipadd = IP;
        else
        {
            for(int j=1;j<=N;j++)
            {
                if(ipp[j] == 0)
                {
                    ipadd = j;
                    break;
                }
            }
            if(ipadd == -1) 
            {
                for(int j=1;j<=N;j++)
                {
                    if(expire[j] < Time)
                    {
                        ipadd = j;
                        break;
                    }
                }
            }
        }

        if(ipadd != -1)
        {
            ipp[ipadd] = 1;
            OccupyName[ipadd] = Send_H;
            SetExpire(ipadd);
            IP = ipadd;
            return "OFR";
        }
        else return "";
    }

    if(post == "REQ")   //request报文处理
    {
        if(Receive_H != Host)
        {
            for(map<int,string>::iterator it = OccupyName.begin(); it != OccupyName.end(); it++)
            {
                if(it -> second == Send_H && ipp[it->first] == 1)
                {
                    ipp[it->first] = 0;
                    expire[it->first] = 0;
                    OccupyName.erase(it);
                } 
            }
            return "";
        }
        else if( IP <= N && IP >= 1 && OccupyName[IP] == Send_H)
        {
            ipp[IP] = 2;
            SetExpire(IP);
            return "Ack";
        }
        else return "Nak";
    }

    return "";
}

int main()
{
    cin >> N >> T >> Tmax >> Tmin >> Host >> n;
    init();

    for(int i=0;i<n;i++)
    {
        cin >> Time >> Send_H >> Receive_H >> Post >> IP >> Lifetime;

        string postans = process(Post);
        if(postans == "") continue;

        cout << Host << " " << Send_H << " " << postans << " " << IP << " " <<  expire[IP] << endl;
        
    }
    return 0;
}
