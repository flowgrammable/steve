#include "utility.hpp"

#include <iostream>

int res(String const* n1, String const* n2)
{
  String name_cat = *n1 + '.' + *n2;
  String name_cat2 = *n1 + '.' + *n2;

  String const* n3 = get_identifier(name_cat);
  String const* n4 = get_identifier(name_cat2);

  std::cout << "N3: " << n3 << " : " << *n1 << '\n';
  std::cout << "N4: " << n4 << " : " << *n2 << '\n';  
}

int test1()
{
  String const* name = new String("stuff");
  String const* name2 = new String("stuff");
  String const* n1 = get_identifier(*name);
  String const* n2 = get_identifier(*name2);

  std::cout << "N1: " << n1 << " : " << *n1 << '\n';
  std::cout << "N2: " << n2 << " : " << *n2 << '\n';

  res(n1, n2);
}

int main()
{
  test1();
}