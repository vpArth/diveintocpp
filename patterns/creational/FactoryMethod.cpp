#include <iostream>
#include <vector>

class Base {
public:
  virtual void info() = 0; // some common interface
  virtual ~Base() = default;
};

class A : public Base {
public:
  void info() override { std::cout << 'A' << std::endl; }
};

class B : public Base {
  void info() override { std::cout << 'B' << std::endl; }
};

class Factory {
public:
  virtual Base *create() = 0; // can have default implementation
  virtual ~Factory() = default;
};

class AFactory : public Factory {
public:
  Base *create() override { return new A; }
};

class BFactory : public Factory {
public:
  Base *create() override { return new B; }
};

int main() {
  auto *a_factory = new AFactory;
  auto *b_factory = new BFactory;

  std::vector<Base *> v;
  v.push_back(a_factory->create());
  v.push_back(b_factory->create());
  v.push_back(a_factory->create());

  for (auto &i : v)
    i->info();
}