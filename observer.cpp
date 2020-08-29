#include <vector>
#include <algorithm>

class Observable;

class Observer
{
  protected:
  Observable *observable;

  public:
  Observer(Observable *) { this->observable = observable; };
  virtual void update() = 0;
};

class Observable
{
  std::vector<Observer *> Registers;
  void *data;

  public:
  void register_observer(Observer *o) { Registers.push_back(o); };
  void notify(void) { std::for_each(Registers.begin(), Registers.end(), [](Observer *o) { o->update(); }); };
  void *get(void) { return data; };
};

class A : public Observer
{
  public:
  A(Observable *o) : Observer(o) { };
  void update() { };
  void get(void *result) { result = observable->get(); };
};


int main()
{
  Observable o;
  A a(&o);
  return 0;
}
