#include <iostream>

#include <net/url.hh>

int main()
{
    net::Url url = net::Url("http://localhost:2048/home?info=test#frag");
    std::cout << url.get_scheme() << std::endl;
    std::cout << url.get_authority_host() << std::endl;
    std::cout << url.get_authority_port() << std::endl;
    std::cout << url.get_path() << std::endl;
    std::cout << url.get_query() << std::endl;
    std::cout << url.get_fragments() << std::endl;
    return 0;
}
