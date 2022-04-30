// client1.cpp - A client that communicates with a second client using triple RSA encrpytion/decryption
#include <arpa/inet.h>
#include <iostream>
#include <math.h>
#include <net/if.h>
#include <netinet/in.h>
#include <queue>
#include <signal.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

using namespace std;

const char IP_ADDR[]="127.0.0.1";
const int BUF_LEN=256;
bool is_running;
int srcPort=1153;
int destPort=1155;
// Encrpytion/Decryption variables
double n;
double e;
double d;
double phi;

queue<unsigned char*> messageQueue;

pthread_mutex_t lock_x;

void *recv_func(void *arg);

static void shutdownHandler(int sig)
{
    switch(sig) {
        case SIGINT:
            is_running=false;
            break;
    }
}

// Returns a^b mod c
unsigned char PowerMod(int a, int b, int c)
{
    int res = 1;
    for(int i=0; i<b; ++i) {
        res=fmod(res*a, c);
    }
    return (unsigned char)res;
}
  
// Returns gcd of a and b
int gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a%h;
        if (temp == 0)
          return h;
        a = h;
        h = temp;
    }
}
  
// Code to demonstrate RSA algorithm
int main()
{
    // Two random prime numbers
    double p = 11;
    double q = 23;
  
    // First part of public key:
    n = p*q;
  
    // Finding other part of public key.
    // e stands for encrypt
    e = 2;
    phi = (p-1)*(q-1);
    while (e < phi)
    {
        // e must be co-prime to phi and
        // smaller than phi.
        if (gcd((int)e, (int)phi)==1)
            break;
        else
            e++;
  
    }
    // Private key (d stands for decrypt)
    // choosing d such that it satisfies
    // d*e = 1 + k * totient
    int k = 2;  // A constant value
    d = (1 + (k*phi))/e;
    cout<<"p:"<<p<<" q:"<<q<<" n:"<<n<<" phi:"<<phi<<" e:"<<e<<" d:"<<d<<endl;

    const int numMessages=5;
    const unsigned char messages[numMessages][BUF_LEN]={
	    "House? You were lucky to have a house!",
	    "We used to live in one room, all hundred and twenty-six of us, no furniture.",
	    "Half the floor was missing;",
	    "we were all huddled together in one corner for fear of falling.",
            "Quit"};

    signal(SIGINT, shutdownHandler);

    //TODO: Complete the rest
}

//TODO: Complete the receive thread