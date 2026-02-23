#include "EDF.hh"

int main(void) {
  std::string file_name = "sample.edf";

  const std::string source = EDF::Utils::read_file(file_name);
  
  return !EDF::Utils::mainloop(source);
}
