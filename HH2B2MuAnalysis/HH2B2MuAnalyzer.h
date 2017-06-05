#ifndef RootAnalysis_HZZAnalyzer_H
#define RootAnalysis_HZZAnalyzer_H

#include <string>
#include <vector>
#include <map>

#include "ObjectMessenger.h"
#include "EventProxyBase.h"
#include "EventProxyHTT.h"

#include "strbitset.h"
#include "TDirectory.h"

//ROOT includes
#include "TTree.h"
#include "TList.h"

#include "Analyzer.h"

class HZZHistograms;

class TH1F;
class TH2F;
class TH3F;
class TLorentzVector;


  typedef struct {
  ///Variables saved into a TTree
  float mass4Mu;
  float massZ1, massZ2;
  float muon1ID, muon2ID, muon3ID, muon4ID;
  float muon1Isolation, muon2Isolation, muon3Isolation, muon4Isolation;
  float muon1Pt, muon2Pt, muon3Pt, muon4Pt;
  float muon1SIP, muon2SIP, muon3SIP, muon4SIP;

  } ENTRY;


class HZZAnalyzer: public Analyzer{

 public:

  HZZAnalyzer(const std::string & aName, const std::string & aDecayMode = "None");

  virtual ~HZZAnalyzer();

  ///Initialize the analyzer
  virtual void initialize(TDirectory* aDir,
			  pat::strbitset *aSelections);

  virtual bool analyze(const EventProxyBase& iEvent);

  virtual bool analyze(const EventProxyBase& iEvent, ObjectMessenger *aMessenger){return analyze(iEvent); }

  virtual void finalize();

  virtual void clear(){;};

  virtual void addBranch(TTree *);

  Analyzer* clone() const;

  bool filter() const{ return filterEvent_;};


 protected:

  pat::strbitset *mySelections_;

  ///Types of the selection flow
  std::vector<std::string> selectionFlavours_;

 private:


  void setHistos(HZZHistograms *histos) { myHistos_ = histos;};

  ///Histograms storage.
  HZZHistograms *myHistos_;

  //should this HZZAnalyzer be able to filter events
  bool filterEvent_;

  ///Reconstructed objects selected for given event.
  HTTEvent aEvent;

  ENTRY aEntry;


};

#endif
