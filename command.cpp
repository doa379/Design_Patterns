#include <vector>

class X
{
  public:
  void execute(void) { };
};

class Y
{
  public:
  void y0(void) { };
  void y1(void) { };
};

class A : public X
{
  Y y;

  public:
  A(Y y) { this->y = y; };
  void execute(void) { y.y0(); };
};

class B : public X
{
  Y y;

  public:
  B(Y y) { this->y = y; };
  void execute(void) { y.y1(); };
};

class Z
{
  std::vector<X> V;

  public:
  void add(X x) { V.push_back(x); };
  void execute(void) { for (X x : V) x.execute(); V.clear(); };
};

int main(void)
{
  Y y;
  A a(y);
  B b(y);
  Z z;
  z.add(a);
  z.add(b);
  z.execute();
  return 0;
}
