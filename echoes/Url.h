#ifndef URL_H
#define URL_H
#include <cstring>
#include <string>
#include <cctype>

#include <boost/throw_exception.hpp>
#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>

#include "detail/escape_string.hpp"

class Url
{
public:
    Url();

private:

    std::string protocol_;
    std::string user_info_;
    std::string host_;
    std::string port_;
    std::string path_;
    std::string query_;
    std::string fragment_;
    bool ipv6_host_;
};

#endif // URL_H
