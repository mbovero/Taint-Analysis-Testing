## Preliminary Research
### Introductions to the concepts of static analysis and taint analysis:
- https://www.perforce.com/blog/sca/what-static-analysis
- https://www.sonarsource.com/blog/what-is-taint-analysis/

### Introductions to the tool(s)
- https://llvm.org/devmtg/2020-09/slides/Using_the_clang_static_ananalyzer_to_find_bugs.pdf
- https://llvm.org/devmtg/2012-11/Zaks-Rose-Checker24Hours.pdf
- https://codechecker.readthedocs.io/en/latest/analyzer/checker_and_analyzer_configuration/
- https://clang.llvm.org/docs/analyzer/user-docs/TaintAnalysisConfiguration.html


# Setup:
*CodeChecker is a tool for static code analysis that integrates with the LLVM/Clang ecosystem. It provides an easy-to-use interface for analyzing code, visualizing results, and tracking issues over time.* <br />

I used CodeChecker to interface with Clang’s GenericTaintChecker, which allowed me to easily run and visualize static taint analysis of C programs. I closely followed
[CodeChecker’s Quick Howto](https://codechecker.readthedocs.io/en/latest/usage/#codechecker-usage-guide) for initial setup, which began with a quick detour to the 
[Linux installation instructions](https://codechecker.readthedocs.io/en/latest/#linux). Pay special attention to the warning regarding newer Python versions - the tool 
might not work without running the provided code. After installation of CodeChecker, the Howto guide gives a comprehensive rundown of how to use the tool. <br />

**Note:**
I added `export PATH=~/codechecker/build/CodeChecker/bin:$PATH` to ~/.bashrc so that the CodeChecker command could be easily executed in any terminal window. <br />
<br />

## Further Exploration
The examples folder contains a few example programs and instructions on how to perform & visualize taint analysis on each one.

