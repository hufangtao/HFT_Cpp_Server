#ifndef CHAT_MESSAGE_H
#define CHAT_MESSAGE_H

#include <cstdio>
#include <cstdlib>
#include <cstring>

class chat_message
{
  public:
    enum
    {
        HEADER_LENGTH = 4
    };
    enum
    {
        MAX_BODY_LENGTH = 512
    };
    chat_message();
    ~chat_message();

    const char *data() const;
    std::size_t length() const;
    const char *body() const;
    char *body();
    std::size_t body_length() const;
    void body_length(std::size_t new_length);
    bool decode_header();
    void encode_header();

  private:
    char data_[HEADER_LENGTH + MAX_BODY_LENGTH];
    std::size_t body_length_;
};

#endif