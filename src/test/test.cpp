#include <iostream>

void printt()
{
return;
}

template <class T, class... Args>
void printt(T head, Args... args)
{
std::cout<<head<<std::endl;
printt(args...);
return;
}

int main1()
{
printt(1,2,3,"45");
return 0;
}

