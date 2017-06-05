#ifndef HH2B2MuHistograms_h
#define HH2B2MuHistograms_h

// Original Author:  Artur Kalinowski
//         Created:  pon, 9 lis 2015, 08:55:38 CET
//
//
#include "AnalysisHistograms.h"

class THStack;


class HH2B2MuHistograms: public AnalysisHistograms {
   public:

  HH2B2MuHistograms(std::string fileName="Histos.root", int opt=0);

  HH2B2MuHistograms(TDirectory *myDir);

  HH2B2MuHistograms(TDirectory *myDir, const std::vector<std::string> & flavours);

  virtual ~HH2B2MuHistograms();

  void finalizeHistograms();

  virtual std::string getTemplateName(const std::string& name);

   private:

  virtual void defineHistograms();

  ///Types of the selection flow
  std::vector<std::string> selectionFlavours_;

  //Plot a single histogram.
  void plotAnyHistogram(const std::string & hName);

};

#endif
