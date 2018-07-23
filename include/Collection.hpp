#pragma once

class Collection {
public:
  template<class T> static T reduce(std::vector<T> arr, T (*fn)(T, T), T initial);
  template<class T, class C> static C reduce(std::vector<T> arr, C (*fn)(T, T), C initial);
  template<class T> static T reduce(std::vector<T> arr, T (*fn)(T, T));
  template<class T> static std::vector<T> filter(std::vector<T> arr, bool (*fn)(T));
};

template<class T, class C> C Collection::reduce(std::vector<T> arr, C (*fn)(T, T), C initial) {
  C acc = initial;
  for (T v : arr) acc = fn(acc, v);

  return acc;
}
template<class T> T Collection::reduce(std::vector<T> arr, T (*fn)(T, T), T initial) {
  return reduce<T, T>(arr, fn, initial);
}

template<class T> T Collection::reduce(std::vector<T> arr, T (*fn)(T, T)) {
  T acc = arr.back();
  arr.pop_back();
  return reduce(arr, fn, acc);
}
template<class T> std::vector<T> Collection::filter(std::vector<T> arr, bool (*fn)(T)) {
  std::vector<T> res;
  for (T v: arr) {
    if (fn(v))res.push_back(v);
  }
  return res;
}
