#ifndef RootAnalysis_HTTWeightsMaker_H
#define RootAnalysis_HTTWeightsMaker_H

#include <string>

#include "ObjectMessenger.h"
#include "EventProxyBase.h"

#include "strbitset.h"
#include "TDirectory.h"

//ROOT includes
#include "TTree.h"
#include "TList.h"
#include "TH1F.h"

#include "Analyzer.h"

class EventProxyHTT;
class HTTWeightHistograms;

class HTTWeightsMaker: public Analyzer{

 public:
  
  HTTWeightsMaker(const std::string & aName);

  virtual ~HTTWeightsMaker();
  
  ///Initialize the analyzer
  virtual void initialize(TDirectory* aDir,
			  pat::strbitset *aSelections);

  virtual bool analyze(const EventProxyBase& iEvent);

  virtual bool analyze(const EventProxyBase& iEvent, ObjectMessenger *aMessenger){return analyze(iEvent); }

  virtual void finalize();

  virtual void clear(){;};

  virtual void addCutHistos(TList *aList){;};

  bool filter() const{ return filterEvent_;};

 protected:

  pat::strbitset *mySelections_;

  ///Types of the selection flow
  std::vector<std::string> selectionFlavours_;

 private:

  ///Event weight necessary to scale the MC PU distribution
  ///to one observed in data.
  float puWeight;

  ///ROOT file with PU histogram
  TFile *puFile;

  ///The PU reference histogram
  TH1F *hPU;

  ///Histograms storage.
  HTTWeightHistograms *myHistos_;
  
  //should this HTTWeightsMaker be able to filter events
  bool filterEvent_;
 
};

#endif
