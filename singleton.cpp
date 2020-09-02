class Singleton
{
  static Singleton *s;
  Singleton(void) { };

  public:
  static Singleton *inst(void)
  {
    if (s == nullptr)
      s = new Singleton();

    return s;
  };
  ~Singleton(void) { delete s; };
};

Singleton *Singleton::s;

int main(void)
{
  Singleton *s;
  s->inst();
  return 0;
}
