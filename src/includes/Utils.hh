#pragma once

#include "main.hh"

namespace EDF::Utils {
  std::string read_file(const std::string& file_name);
  int mainloop(std::string_view source);

  template <typename T>
  void testing(const T val);
}
