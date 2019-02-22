#ifndef SYSTEM_POTENTIAL_H
#define SYSTEM_POTENTIAL_H

#include <cuda_runtime.h>

#include <vector>

#include "main/defines.h"

// Forward declarations
class System;

struct BondPotential {
  int idx[2];
  int siteBlock[2];
  real kb;
  real b0;
};

struct AnglePotential {
  int idx[3];
  int siteBlock[2];
  real kangle;
  real angle0;
  real kureyb;
  real ureyb0;
};

struct DihePotential {
  int idx[4];
  int siteBlock[2];
  real kdih;
  int ndih;
  real dih0;
};

struct ImprPotential {
  int idx[4];
  int siteBlock[2];
  real kimp;
  real imp0;
};

struct CmapPotential {
  int idx[8];
  int siteBlock[3];
  int ngrid;
  int kcmapIndex;
};

class Potential {
  public:
  int bondCount;
  std::vector<struct BondPotential> bonds_tmp;
  struct BondPotential *bonds;
  struct BondPotential *bonds_d;
  int angleCount;
  std::vector<struct AnglePotential> angles_tmp;
  struct AnglePotential *angles;
  struct AnglePotential *angles_d;
  int diheCount;
  std::vector<struct DihePotential> dihes_tmp;
  struct DihePotential *dihes;
  struct DihePotential *dihes_d;
  int imprCount;
  std::vector<struct ImprPotential> imprs_tmp;
  struct ImprPotential *imprs;
  struct ImprPotential *imprs_d;
  int cmapCount;
  std::vector<struct CmapPotential> cmaps_tmp;
  struct CmapPotential *cmaps;
  struct CmapPotential *cmaps_d;

  // cudaStream_t bondedStream[5];
  cudaStream_t bondedStream;
  cudaStream_t nbdirectStream;
  cudaStream_t nbrecipStream;
  // NYI - might need some more

  cudaEvent_t bondedComplete[5];
  cudaEvent_t forceComplete;
  
  Potential();
  ~Potential();

  void initialize(System *system);

  void calc_force(int step,System *system);
};

#endif
