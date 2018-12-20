#ifndef BOX_H
#define BOX_H
class Box
{
  private:
    int x;
    int y;

  public:
    Box();
    Box(const Box &b);
    void getSize();
};
#endif