#include <iostream>
#include <cmath>

#include "commonUtils.h"
#include "HH2B2MuHistograms.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TString.h"
#include "TLine.h"
#include "TF1.h"
#include "TGraph.h"
#include "TMarker.h"
#include "TMath.h"
#include "TLatex.h"
#include "TStyle.h"
#include "THStack.h"

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
HH2B2MuHistograms::HH2B2MuHistograms(std::string fileName, int opt){

  AnalysisHistograms::init(fileName);

}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
HH2B2MuHistograms::HH2B2MuHistograms(TDirectory *myDir){

  AnalysisHistograms::init(myDir);

}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
HH2B2MuHistograms::HH2B2MuHistograms(TDirectory *myDir, const std::vector<std::string> & flavours){
 selectionFlavours_ = flavours;

AnalysisHistograms::init(myDir);

}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
HH2B2MuHistograms::~HH2B2MuHistograms(){ }
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
std::string HH2B2MuHistograms::getTemplateName(const std::string& name){

  std::string templateName = "";

  if(name.find("h1DMass")!=std::string::npos) templateName = "h1DMassTemplate";
  if(name.find("h1DPt")!=std::string::npos) templateName = "h1DPtTemplate";

  return templateName;

}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void HH2B2MuHistograms::defineHistograms(){

 using namespace std;

 if(!histosInitialized_){
   //Make template histos
   add1DHistogram("h1DMassTemplate","",100,0,200,file_);
   add1DHistogram("h1DPtTemplate","",50,0,100,file_);
   histosInitialized_ = true;
 }
}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void HH2B2MuHistograms::finalizeHistograms(){

  AnalysisHistograms::finalizeHistograms();

  plotAnyHistogram("h1DMass4Mu");
  plotAnyHistogram("h1DMassZ1");
  plotAnyHistogram("h1DMassZ2");

}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void HH2B2MuHistograms::plotAnyHistogram(const std::string & hName){

   TCanvas* c = new TCanvas("AnyHistogram","AnyHistogram",
			   460,500);

  TLegend l(0.15,0.78,0.35,0.87,NULL,"brNDC");
  l.SetTextSize(0.05);
  l.SetFillStyle(4000);
  l.SetBorderSize(0);
  l.SetFillColor(10);

  TH1F* h1D = this->get1DHistogram(hName.c_str());

  if(h1D){
    h1D->SetLineWidth(3);
    h1D->SetYTitle("Events");
    h1D->SetXTitle("m [GeV/c^{2}]");
    h1D->GetYaxis()->SetTitleOffset(1.4);
    h1D->SetStats(kFALSE);
    h1D->SetLineColor(1);
    h1D->SetFillColor(1);
    h1D->SetMarkerStyle(20);
    h1D->Draw("p");
    c->Print(TString::Format("fig_png/%s.png",hName.c_str()).Data());
  }
}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
