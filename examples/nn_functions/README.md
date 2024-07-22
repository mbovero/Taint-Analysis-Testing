The following steps assume that a terminal has been opened with its working directory set as the same directory this README resides within.

## Execute Taint Analysis on Example Code
`CodeChecker log --build "make" --output ./compile_commands.json`
`CodeChecker analyze ./compile_commands.json --output ./reports --enable sensitive --checker-config clangsa:alpha.security.taint.TaintPropagation:Config=taint-config.yaml`

## Visualize Results as html
`CodeChecker parse --export html --output ./reports_html ./reports`
Navigate to the newly created reports_html folder and open the desired .html file.

## Visualize Results in Browser
In a separate terminal, execute:
`source ~/codechecker/venv/bin/activate`
`CodeChecker server --workspace .ws --port 8555`
In your original terminal window, run:
`CodeChecker store ./reports --name <report_name> --url http://localhost:8555/Default`
Then visit http://localhost:8555/Default in your browser.

## Generating/Visualizing New Reports
Run `make clean` before executing analysis with changed code or configuration.
Storing reports on your server under names/directories that already exist will not work. Navigate to the targeted report within your browser and delete it before attemping a reupload. 


## Sources
https://codechecker.readthedocs.io/en/latest/usage/
https://clang.llvm.org/docs/analyzer/user-docs/TaintAnalysisConfiguration.html#clangsa-taint-configuration-example
