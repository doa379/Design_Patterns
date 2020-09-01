// Products
class X
{
  public:
  virtual void method(void) = 0;
};

class AX : public X
{
  public:
  void method(void) { };
};

class BX : public X
{
  public:
  void method(void) { };
};

class Y
{
  public:
  virtual void method(void) = 0;
};

class AY : public Y
{
  public:
  void method(void) { };
};

class BY : public Y
{
  public:
  void method(void) { };
};

// Factory
class F
{
  public:
  virtual X *x() = 0;
  virtual Y *y() = 0;
};

class FP : public F
{
  AX ax;
  BY by;
  public:
  FP(AX ax, BY by) { this->ax = ax; this->by = by; };
  X *x() { return &ax; };
  Y *y() { return &by; };
};

class FQ : public F
{
  AY ay;
  BX bx;
  public:
  FQ(BX bx, AY ay) { this->ay = ay; this->bx = bx; };
  X *x() { return &bx; };
  Y *y() { return &ay; };
};

//

int main(void)
{
  AX ax;
  BY by;
  FP fp(ax, by);
  fp.x()->method();
  return 0;
}
