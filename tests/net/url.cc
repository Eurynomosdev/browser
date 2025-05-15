#include <gtest/gtest.h>

#include <net/url.hh>

TEST(net_url, url_basic)
{
    net::Url url = net::Url("http://localhost");
    EXPECT_EQ(url, true);
    EXPECT_EQ(url.get_scheme(), "http");
    EXPECT_EQ(url.get_authority_host(), "localhost");
    EXPECT_EQ(url.get_authority_port(), "");
    EXPECT_EQ(url.get_path(), "/");
    EXPECT_EQ(url.get_query(), "");
    EXPECT_EQ(url.get_fragments(), "");
}

TEST(net_url, url_basic_full)
{
    net::Url url = net::Url("http://localhost:2048/home?info=test#frag");
    EXPECT_EQ(url, true);
    EXPECT_EQ(url.get_scheme(), "http");
    EXPECT_EQ(url.get_authority_host(), "localhost");
    EXPECT_EQ(url.get_authority_port(), "2048");
    EXPECT_EQ(url.get_path(), "/home");
    EXPECT_EQ(url.get_query(), "info=test");
    EXPECT_EQ(url.get_fragments(), "frag");
}

TEST(net_url, url_no_path)
{
    net::Url url = net::Url("http://localhost:2048?info=test#frag");
    EXPECT_EQ(url, true);
    EXPECT_EQ(url.get_scheme(), "http");
    EXPECT_EQ(url.get_authority_host(), "localhost");
    EXPECT_EQ(url.get_authority_port(), "2048");
    EXPECT_EQ(url.get_path(), "/");
    EXPECT_EQ(url.get_query(), "info=test");
    EXPECT_EQ(url.get_fragments(), "frag");
}

TEST(net_url, url_no_fragment)
{
    net::Url url = net::Url("http://localhost:2048/home?info=test");
    EXPECT_EQ(url, true);
    EXPECT_EQ(url.get_scheme(), "http");
    EXPECT_EQ(url.get_authority_host(), "localhost");
    EXPECT_EQ(url.get_authority_port(), "2048");
    EXPECT_EQ(url.get_path(), "/home");
    EXPECT_EQ(url.get_query(), "info=test");
    EXPECT_EQ(url.get_fragments(), "");
}

TEST(net_url, url_no_query)
{
    net::Url url = net::Url("http://localhost:2048/home#frag");
    EXPECT_EQ(url, true);
    EXPECT_EQ(url.get_scheme(), "http");
    EXPECT_EQ(url.get_authority_host(), "localhost");
    EXPECT_EQ(url.get_authority_port(), "2048");
    EXPECT_EQ(url.get_path(), "/home");
    EXPECT_EQ(url.get_query(), "");
    EXPECT_EQ(url.get_fragments(), "frag");
}

