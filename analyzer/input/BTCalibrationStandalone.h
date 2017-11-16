#ifndef BTEntry_H
#define BTEntry_H

/**
 *
 * BTagEntry
 *
 * Represents one pt- or discriminator-dependent calibration function.
 *
 * measurement_type:    e.g. comb, ttbar, di-mu, boosted, ...
 * sys_type:            e.g. central, plus, minus, plus_JEC, plus_JER, ...
 *
 * Everything is converted into a function, as it is easiest to store it in a
 * txt or json file.
 *
 ************************************************************/

#include <string>
#include <TF1.h>
#include <TH1.h>


class BTEntry
{
public:
  enum OperatingPoint {
    OP_LOOSE=0,
    OP_MEDIUM=1,
    OP_TIGHT=2,
    OP_RESHAPING=3,
  };
  enum JetFlavor {
    FLAV_B=0,
    FLAV_C=1,
    FLAV_UDSG=2,
  };
  struct Parameters {
    OperatingPoint operatingPoint;
    std::string measurementType;
    std::string sysType;
    JetFlavor jetFlavor;
    float etaMin;
    float etaMax;
    float ptMin;
    float ptMax;
    float discrMin;
    float discrMax;

    // default constructor
    Parameters(
      OperatingPoint op=OP_TIGHT,
      std::string measurement_type="comb",
      std::string sys_type="central",
      JetFlavor jf=FLAV_B,
      float eta_min=-99999.,
      float eta_max=99999.,
      float pt_min=0.,
      float pt_max=99999.,
      float discr_min=0.,
      float discr_max=99999.
    );

  };

  BTEntry() {}
  BTEntry(const std::string &csvLine);
  BTEntry(const std::string &func, Parameters p);
  BTEntry(const TF1* func, Parameters p);
  BTEntry(const TH1* histo, Parameters p);
  ~BTEntry() {}
  static std::string makeCSVHeader();
  std::string makeCSVLine() const;
  static std::string trimStr(std::string str);

  // public, no getters needed
  std::string formula;
  Parameters params;

};

#endif  // BTEntry_H


#ifndef BTCalibration_H
#define BTCalibration_H

/**
 * BTCalibration
 *
 * The 'hierarchy' of stored information is this:
 * - by tagger (BTCalibration)
 *   - by operating point or reshape bin
 *     - by jet parton flavor
 *       - by type of measurement
 *         - by systematic
 *           - by eta bin
 *             - as 1D-function dependent of pt or discriminant
 *
 ************************************************************/

#include <map>
#include <vector>
#include <string>
#include <istream>
#include <ostream>


class BTCalibration
{
public:
  BTCalibration() {}
  BTCalibration(const std::string &tagger);
  BTCalibration(const std::string &tagger, const std::string &filename);
  ~BTCalibration() {}

  std::string tagger() const {return tagger_;}

  void addEntry(const BTEntry &entry);
  const std::vector<BTEntry>& getEntries(const BTEntry::Parameters &par) const;

  void readCSV(std::istream &s);
  void readCSV(const std::string &s);
  void makeCSV(std::ostream &s) const;
  std::string makeCSV() const;

protected:
  static std::string token(const BTEntry::Parameters &par);

  std::string tagger_;
  std::map<std::string, std::vector<BTEntry> > data_;

};

#endif  // BTCalibration_H


#ifndef BTCalibrationReader_H
#define BTCalibrationReader_H

/**
 * BTCalibrationReader
 *
 * Helper class to pull out a specific set of BTEntry's out of a
 * BTCalibration. TF1 functions are set up at initialization time.
 *
 ************************************************************/

#include <memory>
#include <string>



class BTCalibrationReader
{
public:
  class BTCalibrationReaderImpl;

  BTCalibrationReader() {}
  BTCalibrationReader(BTEntry::OperatingPoint op,
                        const std::string & sysType="central",
                        const std::vector<std::string> & otherSysTypes={});

  void load(const BTCalibration & c,
            BTEntry::JetFlavor jf,
            const std::string & measurementType="comb");

  double eval(BTEntry::JetFlavor jf,
              float eta,
              float pt,
              float discr=0.) const;

  double eval_auto_bounds(const std::string & sys,
                          BTEntry::JetFlavor jf,
                          float eta,
                          float pt,
                          float discr=0.) const;

  std::pair<float, float> min_max_pt(BTEntry::JetFlavor jf,
                                     float eta,
                                     float discr=0.) const;

protected:
  std::shared_ptr<BTCalibrationReaderImpl> pimpl;
};


#endif // BTCalibrationReader_H
