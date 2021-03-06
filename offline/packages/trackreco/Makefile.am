##############################################
# please add new classes in alphabetical order

AUTOMAKE_OPTIONS = foreign

# List of shared libraries to produce
lib_LTLIBRARIES = \
  libtrack_reco_io.la \
  libtrack_reco.la

AM_CPPFLAGS = \
  -I$(includedir) \
  -I$(OFFLINE_MAIN)/include \
  -I${G4_MAIN}/include \
  -I$(ROOTSYS)/include \
  -I$(OFFLINE_MAIN)/include/eigen3

AM_CXXFLAGS = \
 -Werror -DRAVE -DRaveDllExport=

AM_LDFLAGS = \
  -L$(libdir) \
  -L$(OFFLINE_MAIN)/lib

pkginclude_HEADERS = \
  AssocInfoContainer.h \
  PHGenFitTrkFitter.h \
  PHGenFitTrkProp.h \
  PHHoughSeeding.h \
  PHInitVertexing.h \
  PHTrackPropagating.h \
  PHTrackSeeding.h \
  PHTruthTrackSeeding.h \
  PHTruthVertexing.h

ROOTDICTS = \
  AssocInfoContainer_Dict.cc
if MAKEROOT6
  pcmdir = $(libdir)
  nobase_dist_pcm_DATA = \
    AssocInfoContainer_Dict_rdict.pcm
else
  ROOT5_DICTS = \
    PHInitVertexing_Dict.cc \
    PHTrackSeeding_Dict.cc \
     PHTrackPropagating_Dict.cc \
    PHTrackFitting_Dict.cc \
    PH3DVertexing_Dict.cc \
    PHTruthVertexing_Dict.cc \
    PHTruthTrackSeeding_Dict.cc \
    PHHoughSeeding_Dict.cc \
    PHGenFitTrkProp_Dict.cc \
    PHGenFitTrkFitter_Dict.cc \
    PHRaveVertexing_Dict.cc
endif

libtrack_reco_io_la_SOURCES = \
  $(ROOTDICTS) \
  AssocInfoContainer.cc 

libtrack_reco_la_SOURCES = \
  $(ROOT5_DICTS) \
  PHInitVertexing.cc \
  PHTrackSeeding.cc \
  PHTrackPropagating.cc \
  PHTrackFitting.cc \
  PH3DVertexing.cc \
  PHTruthVertexing.cc \
  PHTruthTrackSeeding.cc \
  PHHoughSeeding.cc \
  PHGenFitTrkProp.cc \
  PHGenFitTrkFitter.cc \
  PHRaveVertexing.cc


libtrack_reco_io_la_LIBADD = \
  -lphool

libtrack_reco_la_LIBADD = \
  libtrack_reco_io.la \
  -lSubsysReco \
  -lg4testbench \
  -lg4detectors \
  -lgsl \
  -lgslcblas \
  -lHelixHough \
  -lFitNewton \
  -lSeamstress \
  -lgenfit2 \
  -lgenfit2exp \
  -lPHGenFit \
  -lg4bbc_io \
  -lg4tpc \
  -lg4intt \
  -lg4mvtx \
  -lmvtx_io \
  -lintt_io \
  -ltrackbase_historic_io \
  -lphparameter

# Rule for generating table CINT dictionaries.
%_Dict.cc: %.h %LinkDef.h
	rootcint -f $@ @CINTDEFS@ -c $(DEFAULT_INCLUDES) $(AM_CPPFLAGS) $^

#just to get the dependency
%_Dict_rdict.pcm: %_Dict.cc ;


################################################
# linking tests

BUILT_SOURCES = \
  testexternals.cc

noinst_PROGRAMS = \
  testexternals_track_reco \
  testexternals_track_reco_io


testexternals_track_reco_SOURCES = testexternals.cc
testexternals_track_reco_LDADD = libtrack_reco.la

testexternals_track_reco_io_SOURCES = testexternals.cc
testexternals_track_reco_io_LDADD = libtrack_reco_io.la

testexternals.cc:
	echo "//*** this is a generated file. Do not commit, do not edit" > $@
	echo "int main()" >> $@
	echo "{" >> $@
	echo "  return 0;" >> $@
	echo "}" >> $@

##############################################
# please add new classes in alphabetical order

clean-local:
	rm -f *Dict* $(BUILT_SOURCES) *.pcm
