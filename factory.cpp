class X
{
  public:
  virtual void method(void) = 0;
};

class A : public X
{
  public:
  void method(void) { };
};

class B : public X
{
  public:
  void method(void) { };
};

class Factory
{
  public:
  virtual X *create() = 0;
  void method(void) { this->create(); };
};

class P : public Factory
{
  A a;

  public:
  X *create() { return &a; };
};

class Q : public Factory
{
  B b;

  public:
  X *create() { return &b; };
};

int main()
{
  P p;
  p.create()->method();
  Q q;
  q.create()->method();
  return 0;
}
