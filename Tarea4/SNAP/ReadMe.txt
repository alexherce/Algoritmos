========================================================================
  SNAP : Stanford Network Analysis Platform
	http://snap.stanford.edu
========================================================================

Stanford Network Analysis Platform (SNAP) is a general purpose, high
performance system for analysis and manipulation of large networks.
SNAP is written in C++ and it scales to massive graphs with hundreds
of millions of nodes and billions of edges.


This version of SNAP imports a graph from the Stanford Large Network Dataset
Collection and exports it in GraphML, GEFX, GDF and GraphSON.
/////////////////////////////////////////////////////////////////////////////

Directory structure:
  http://snap.stanford.edu/snap/description.html

  code:
        program for exporting graphs in GraphML, GEFX, GDF, GraphSON
  snap-core:
        the core SNAP graph library
  snap-adv:
        advanced SNAP components, not in the core, but used by examples
  snap-exp:
        experimental SNAP components, still in development
  glib-core:
        STL-like library that implements basic data structures, like vectors
        (TVec), hash-tables (THash) and strings (TStr), provides
        serialization and so on
  doxygen:
        SNAP reference manuals

Code compiles under Windows (Microsoft Visual Studio, CygWin with gcc) and
Linux and Mac (gcc). Use the SnapExamples.vcproj or provided makefiles.

Some of applications expect that GnuPlot and GraphViz are installed and
accessible -- paths are in the system PATH variable or they reside in the
working directory.

/////////////////////////////////////////////////////////////////////////////

Example applications for advanced SNAP functionality are available
in the examples directory and described at:
  http://snap.stanford.edu/snap/description.html.

To compile from the command line, execute:
  make all   # compiles SNAP and all sample applications

To compile on Mac OSX, using Xcode:
  1. From the Toolbar, select Scheme (e.g. 'bigclam').
  2. Product -> Build.  (or Cmd + B).
  3. Run executable via the command line; or
     Choose the scheme's executable (Product -> Edit Scheme -> Run -> Info)
     and run: Product -> Run (or Cmd + R).
     Note: If using Gnuplot, add the PATH to the scheme's environment variables.
     or create symlink to /usr/bin:
     sudo ln -s <gnuplot_dir>/gnuplot /usr/bin/
  For code completion, the "docs" target has been created which includes all
  Snap-related files and example programs.
