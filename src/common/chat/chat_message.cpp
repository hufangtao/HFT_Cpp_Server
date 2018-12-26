#include "chat_message.h"

chat_message::chat_message() : body_length_(0)
{
}

chat_message::~chat_message()
{
}

const char *chat_message::data() const
{
    return data_;
}
std::size_t chat_message::length() const
{
    return HEADER_LENGTH + body_length_;
}
const char *chat_message::body() const
{
    return data_ + HEADER_LENGTH;
}
char *chat_message::body()
{
    return data_ + HEADER_LENGTH;
}
std::size_t chat_message::body_length() const
{
    return body_length_;
}
void chat_message::body_length(std::size_t new_length)
{
    body_length_ = new_length;
    if (body_length_ > MAX_BODY_LENGTH)
    {
        body_length_ = MAX_BODY_LENGTH;
    }
}
bool chat_message::decode_header()
{
    char header[HEADER_LENGTH + 1] = "";
    std::strncat(header, data_, HEADER_LENGTH);
    body_length_ = std::atoi(header);
    if (body_length_ > MAX_BODY_LENGTH)
    {
        body_length_ = 0;
        return false;
    }
    return true;
}
void chat_message::encode_header()
{
    char header[HEADER_LENGTH + 1] = "";
    std::sprintf(header, "%4d", static_cast<int>(body_length_));
    std::memcpy(data_, header, HEADER_LENGTH);
}