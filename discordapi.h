#ifndef DISCORDAPI_H
#define DISCORDAPI_H
#include <iostream>
#include <vector>
using namespace std;
namespace api {

struct discord_login_response {
    string token;
    bool mfa;
    bool sms;
    string ticket;
};

/*class discordapi
{
public:
    discordapi();

};*/

discord_login_response login(string email, string password);

}

#endif // DISCORDAPI_H
