#include "discordapi.h"

namespace api{

discord_login_response login(string email, string password) {
    discord_login_response tmp = discord_login_response();
    tmp.token = email;
    tmp.ticket = password;
    return tmp;
}

}
