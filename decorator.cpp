class Base
{
  public:
  virtual void method(void) = 0;
};

class Base_Decorator
{
  protected:
  Base *base;
  
  public:
  Base_Decorator(Base *base) { this->base = base; };
  void method(void) { };
};

class X : public Base_Decorator
{
  public:
  X(Base *base) : Base_Decorator(base) { };
  void method(void) { base->method(); };
};

class A : public Base
{
  public:
  A(void) { };
  void method(void) { };
};

class B : public Base
{
  public:
  B(void) { };
  void method(void) { };
};

int main()
{
  A a;
  X x(&a);
  return 0;
}
