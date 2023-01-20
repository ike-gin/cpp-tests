namespace junk {
struct someObj {
  int a;
  double b;
};
someObj someFunc() { return {55, 123.456}; }
static someObj someStaticFunc() { return {76, 777.888}; }
} // namespace junk
