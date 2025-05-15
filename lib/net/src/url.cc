#include "net/url.hh"

namespace net
{

const char* Url::parse_scheme(const char* src)
{
    const char* back = src;

    if (!std::isalpha(*src)) {
        return nullptr;
    }
    ++src;

    while (std::isalpha(*src) || std::isdigit(*src) ||
            *src == '+' || *src == '-' || *src == '.') {
        ++src;
    }

    if (*src != ':') {
        return nullptr;
    }

    scheme_ = std::string(back, src - back);
    return src;
}

const char* Url::parse_authority(const char* src)
{
    const char* back = src;
    while (*src != ':' && *src != '/' && *src != '\0' && *src != '?' && *src != '#') {
        ++src;
    }

    if (*src == '/' || *src == '\0' || *src == '?' || *src == '#') {
        authority_host_ = std::string(back, src - back);
        return src;
    } else if (*src != ':') {
        return nullptr;
    }
    authority_host_ = std::string(back, src - back);
    ++src;
    back = src;
    while (std::isdigit(*src)) {
        ++src;
    }

    if (*src != '/' && *src != '?' && *src != '#' && *src != '\0') {
        return nullptr;
    }

    authority_port_ = std::string(back, src - back);
    return src;
}
    
// TODO make sure of path validity
const char* Url::parse_path(const char* src)
{
    const char* back = src;

    while (*src != '?' && *src != '#' && *src != '\0') {
        ++src;
    }

    if (src != back) {
        path_ = std::fs::path(std::string(back, src - back));
    }
    return src;
}

// TODO make sure of query validity
const char* Url::parse_query(const char* src)
{
    const char* back = src;

    while (*src != '#' && *src != '\0') {
        ++src;
    }

    query_ = std::string(back, src - back);
    return src;
}

// TODO make sure of fragment validity
const char* Url::parse_fragments(const char* src)
{
    const char* back = src;

    while (*src != '\0') {
        ++src;
    }

    fragment_ = std::string(back, src - back);
    return src;
}

Url::Url(const std::string& url) :
    scheme_(""), authority_host_(""), authority_port_(""),
    path_("/"), query_(""), fragment_("")
{
    const char* c_url = url.c_str();
   
    c_url = parse_scheme(c_url);
    if (!c_url) {
        authority_host_ = "";
        return;
    }

    if (c_url[1] != '/' && c_url[2] != '/') {
        authority_host_ = "";
        return;
    }
    c_url += 3;
    c_url = parse_authority(c_url);
    if (!c_url) {
        authority_host_ = "";
        return;
    }

    if (c_url[0] == '?') {
        goto query;
    } else if (c_url[0] == '#') {
        goto fragment;
    }

    c_url = parse_path(c_url);
    if (!c_url) {
        authority_host_ = "";
        return;
    }
    if (*c_url == '#') {
        goto fragment;
    }
query:
    if (*c_url == '\0') {
        return;
    }
    // skip '?'
    ++c_url;
    c_url = parse_query(c_url);
    if (!c_url) {
        authority_host_ = "";
        return;
    }
fragment:
    if (*c_url == '\0') {
        return;
    }
    // skip '#'
    ++c_url;
    c_url = parse_fragments(c_url);
    if (!c_url) {
        authority_host_ = "";
        return;
    }
}

Url::Url()
{
}

const std::string& Url::get_scheme() const
{
    return scheme_;
}

const std::string& Url::get_authority_host() const
{
    return authority_host_;
}

const std::string& Url::get_authority_port() const
{
    return authority_port_;
}

const std::fs::path& Url::get_path() const
{
    return path_;
}

const std::string& Url::get_query() const
{
    return query_;
}

const std::string& Url::get_fragments() const
{
    return fragment_;
}

Url::operator bool() const
{
    return authority_host_.size() > 0;
}

}
