from ROOT import TFile,TTree


input  = 'RootAnalysis_SynchMuTau.root'
output = 'WAW_SYNCFILE_Nano_VBFHToTauTau_M125_powheg_mt_171214.root'
#input  = 'RootAnalysis_SynchTT.root'
#output = 'WAW_SYNCFILE_Nano_VBFHToTauTau_M125_powheg_tt_171214.root'

fin = TFile(input)
t = fin.Get("Summary/tree")
#t = fin.Get("tree")

fout = TFile(output,"recreate")
fout.mkdir("Synch")
fout.cd("Synch")
t.CloneTree().Write()

fout.Close()
fin.Close()
