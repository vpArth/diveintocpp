#include <iostream>
#include <vector>

class Piece {
public:
  virtual ~Piece() = default;
  virtual void info() const = 0;
};

class Pawn : public Piece {
public:
  void info() const override {
    std::cout << "Pawn" << std::endl;
  }
};

class Knight : public Piece {
public:
  void info() const override {
    std::cout << "Knight" << std::endl;
  }
};

class PieceSet {
public:
  virtual ~PieceSet() {
    for (auto &v: list) {
      delete (v);
    }
  }
  std::vector<Piece *> list;
  void info() const {
    for (auto &v: list) {
      v->info();
    }
  }
};

class PieceSetBuilder {
protected:
  PieceSet *ps;
public:
  PieceSetBuilder() : ps(nullptr) {}
  PieceSet *build() { return ps; }
  PieceSetBuilder *create() {
    ps = new PieceSet;
    return this;
  }
  PieceSetBuilder *addPawn() {
    ps->list.push_back(new Pawn);
    return this;
  }
  PieceSetBuilder *addKnight() {
    ps->list.push_back(new Knight);
    return this;
  }
};

int main() {
  auto builder = new PieceSetBuilder;
  auto set = builder
      ->create()
      ->addPawn()
      ->addPawn()
      ->addKnight()
      ->build();
  set->info();

  delete (set);
  delete (builder);
}
