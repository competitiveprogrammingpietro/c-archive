#include <cstdint>
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
extern const std::uint8_t _binary_archive_tar_start[];
extern const std::uint8_t _binary_archive_tar_end[];

extern const std::uint8_t _binary_script_sh_start[];
extern const std::uint8_t _binary_script_sh_end[];

int main()
{
{
  ofstream archive;
  archive.open ("out.live.tar");
  for (auto d = _binary_archive_tar_start; d != _binary_archive_tar_end; ++d)
      archive << (char)*d;
  archive.close();
}

{
  ofstream script;
  script.open ("script.live.sh");
   
  for (auto d = _binary_script_sh_start; d != _binary_script_sh_end; ++d)
      script << (char)*d;

  script.close();
}

 system("chmod +x ./script.live.sh");
 system("./script.live.sh out.live.tar");
 exit(0);
 
}
