/*
 * (C) Copyright 2017-2018 UCAR
 * 
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0. 
 */

#ifndef UFO_MARINE_MARINEVERTINTERP_OBSMARINEVERTINTERP_H_
#define UFO_MARINE_MARINEVERTINTERP_OBSMARINEVERTINTERP_H_

#include <ostream>
#include <string>

#include "oops/base/Variables.h"
#include "oops/util/ObjectCounter.h"

#include "ufo/marine/marinevertinterp/ObsMarineVertInterp.interface.h"
#include "ufo/ObsOperatorBase.h"

/// Forward declarations
namespace eckit {
  class Configuration;
}

namespace ioda {
  class ObsSpace;
  class ObsVector;
}

namespace ufo {
  class GeoVaLs;
  class ObsBias;
  class ObsDiagnostics;

// -----------------------------------------------------------------------------
/// Marinevertinterp observation operator class
class ObsMarineVertInterp : public ObsOperatorBase,
                   private util::ObjectCounter<ObsMarineVertInterp> {
 public:
  static const std::string classname() {return "ufo::ObsMarineVertInterp";}

  ObsMarineVertInterp(const ioda::ObsSpace &, const eckit::Configuration &);
  virtual ~ObsMarineVertInterp();

// Obs Operator
  void simulateObs(const GeoVaLs &, ioda::ObsVector &, ObsDiagnostics &) const override;

// Other
  const oops::Variables & requiredVars() const override {return varin_;}

  int & toFortran() {return keyOper_;}
  const int & toFortran() const {return keyOper_;}

 private:
  void print(std::ostream &) const override;
  F90hop keyOper_;
  const ioda::ObsSpace& odb_;
  oops::Variables varin_;
};

// -----------------------------------------------------------------------------

}  // namespace ufo
#endif  // UFO_MARINE_MARINEVERTINTERP_OBSMARINEVERTINTERP_H_
