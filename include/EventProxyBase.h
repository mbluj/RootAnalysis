#ifndef EVENTPROXY_h
#define EVENTPROXY_h

#include <string>
#include <typeinfo>
#include <vector>
#include <omp.h>

#include "boost/shared_ptr.hpp"

#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TROOT.h"

   class EventProxyBase{

   public:

	  EventProxyBase();

      virtual ~EventProxyBase();

      EventProxyBase const& operator++();

      // Go to the very first Event.
      EventProxyBase const& toBegin();

      ///Go to event number n
      EventProxyBase const& toN(int n);
      
      virtual bool atEnd() const;

      ///Reload current event. Can be used if
      ///some tree branches are enebled/disabled
      ///en event by event basis.
      void reloadEvent();

      bool isValid() const;

      operator bool() const;
      void skip(int n);
      TFile* getTFile() const;

      TTree* getTTree() const;

      TChain* getTChain() const {return fChain.get();};

      virtual void init(std::vector<std::string> const& iFileNames);

      virtual EventProxyBase* clone() const {return 0;};
      //

      Long64_t size() const{ return accumulatedSize_; }

   protected:

      std::vector<std::string> fileNames_;
      boost::shared_ptr<TChain> fChain;
      std::string treeName_;

      Long64_t eventIndex_;
      Long64_t accumulatedSize_;

};
#endif

