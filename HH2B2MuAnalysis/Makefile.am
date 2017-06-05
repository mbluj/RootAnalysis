#######################################
# The list of executables we are building seperated by spaces
# the 'bin_' indicates that these build products will be installed
# in the $(bindir) directory. For example /usr/bin
bin_PROGRAMS=hhAnalysis

# Because a.out is only a sample program we don't want it to be installed.
# The 'noinst_' prefix indicates that the following targets are not to be
# installed.
#noinst_PROGRAMS=hhAnalysis

#######################################
# Build information for each executable. The variable name is derived
# by use the name of the executable with each non alpha-numeric character is
# replaced by '_'. So a.out becomes a_out and the appropriate suffex added.
# '_SOURCES' for example.

# Sources for the a.out
hhAnalysis_SOURCES= HH2B2MuAnalysis.cc EventProxyHTT.cc \
	            HH2B2MuAnalyzer.cc HH2B2MuHistograms.cc \
							HTTEvent.cxx DictCint.cxx


# Linker options for a.out
hhAnalysis_LDFLAGS = $(top_srcdir)/src/libRootAnalysis.la -R @ROOTLIBDIR@ -L@ROOTLIBDIR@ $(BOOST_REGEX_LDFLAGS)
hhAnalysis_LDADD   = @ROOTLIBS@ -lProof -lRooFitCore -lRooFit @ROOTAUXLIBS@ -lgomp $(BOOST_REGEX_LIBS)

# Compiler options for a.out
hhAnalysis_CPPFLAGS = -I./ -I$(top_srcdir)/include -I@ROOTINCDIR@ $(BOOST_CPPFLAGS)

BUILT_SOURCES = DictCint.cxx

CLEANFILES = *Cint.cxx *~ core

%Cint.cxx 	:HTTEvent.h LinkDef.h
		@ROOTCINT@ -f $*Cint.cxx -c $(INCLUDES) $(AM_CPPFLAGS) $^
