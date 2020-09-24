class X
{
  public:
};

class Y : public X
{

};

class A
{
  X x;
  public:
  A(X x) { this->x = x; };
  virtual void method(void) = 0;
};

class B : public A
{
  public:
  B(X x) : A(x) { };
  void method(void) { };
};

int main()
{
  /*
      A(X)
      / \
     B   Y
  */
  Y y;
  B b(y);
  return 0;
}
