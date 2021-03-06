#include "animal.hh"

#include <iostream>

int main(int argc, char* argv[]) {
  std::ostream& out = std::cout;
  Cat fluffy("fluffy"), simba("simba");
  Dog fido("fido"), rufus("rufus");
  Cow bossy("bossy"), bessie("bessie");
  //can't make instances of the base class, can only use pointers or references as below.
  //const Animal animals[] = { fido, fluffy };
  const Animal *animals[] = {
    &bessie,
    &bossy,
    &fido,
    &fluffy,
    &rufus,
    &simba,
  };
  //auto is classifying everything it is looping through as an animal (pointer)
  for (auto animalP : animals) {
    out << animalP->name << " says " << animalP->says() << std::endl;
    out << animalP->name << " eats " << animalP->eats() << std::endl;
  }
}
