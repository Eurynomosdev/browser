#ifndef NET_URL_HH
#define NET_URL_HH

#include <string>
#include <filesystem>

#define fs filesystem

namespace net
{

class Url
{
private:
    std::string scheme_;
    std::string authority_host_;
    std::string authority_port_;
    std::fs::path path_;
    std::string query_;
    std::string fragment_;

    const char* parse_scheme(const char* src);
    const char* parse_authority(const char* src);
    const char* parse_path(const char* src);
    const char* parse_query(const char* src);
    const char* parse_fragments(const char* src);
public:
    Url(const std::string& url);
    Url();

    const std::string& get_scheme() const;
    const std::string& get_authority_host() const;
    const std::string& get_authority_port() const;
    const std::fs::path& get_path() const;
    const std::string& get_query() const;
    const std::string& get_fragments() const;

    operator bool() const;
};

}

#endif /* NET_URL_HH */

