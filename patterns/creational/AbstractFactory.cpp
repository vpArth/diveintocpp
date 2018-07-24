#include <iostream>
#include <vector>

class Piece {
public:
  virtual void info() = 0;
  virtual ~Piece() = default;
};

class Pawn : public Piece {
};

class Knight : public Piece {
};

class WhitePawn : public Pawn {
public:
  void info() override { std::cout << "White pawn" << std::endl; }
};

class BlackPawn : public Pawn {
public:
  void info() override { std::cout << "Black pawn" << std::endl; }
};

class WhiteKnight : public Knight {
public:
  void info() override { std::cout << "White knight" << std::endl; }
};

class BlackKnight : public Knight {
public:
  void info() override { std::cout << "Black knight" << std::endl; }
};

class PieceFactory {
public:
  virtual Knight *createKnight() const = 0;
  virtual Pawn *createPawn() const = 0;
  virtual ~PieceFactory() = default;
};

class WhitePieceFactory : public PieceFactory {
public:
  Knight *createKnight() const override { return new WhiteKnight; }
  Pawn *createPawn() const override { return new WhitePawn; }
};

class BlackPieceFactory : public PieceFactory {
public:
  Knight *createKnight() const override { return new BlackKnight; }
  Pawn *createPawn() const override { return new BlackPawn; }
};

class PieceSet {
public:
  void info() {
    for (auto &v: pieces) {
      v->info();
    }
  }
  std::vector<Piece *> pieces;
  virtual ~PieceSet() {
    for (auto &v: pieces)delete (v);
  };
};

class Game {
public:
  static PieceSet *create(const PieceFactory &factory) {
    auto ps = new PieceSet;
    ps->pieces.push_back(factory.createPawn());
    ps->pieces.push_back(factory.createPawn());
    ps->pieces.push_back(factory.createKnight());
    // ...
    return ps;
  }
};

int main() {
  WhitePieceFactory wFactory;
  BlackPieceFactory bFactory;

  auto white = Game::create(wFactory);
  auto black = Game::create(bFactory);

  white->info();
  black->info();

  delete white;
  delete black;
}
