const core = require("@actions/core");
const exec = require("@actions/exec");

async function run() {
  try {
    const project = core.getInput("project", { required: true });
    const version = core.getInput("version", { required: true });

    core.startGroup(`Fetch function insights for ${project}(${version})`)
    // let insights = "";
    // const options = {};
    // options.listeners = {
    //   stdout: (data) => {
    //     insights += data.toString();
    //   },
    // };
    // await exec.exec("loci_api", ["func-insights", project, version], options);
    const insights = `{
        "project": "DIFF Tests",
        "version": "case_03_v1",
        "functions": [
          {
            "name": "example::foo",
            "file": "src/foo.cpp",
            "lines_of_code": 42,
            "cyclomatic_complexity": 5
          },
          {
            "name": "example::bar",
            "file": "src/bar.cpp",
            "lines_of_code": 30,
            "cyclomatic_complexity": 3
          },
          {
            "name": "example::baz",
            "file": "src/baz.cpp",
            "lines_of_code": 75,
            "cyclomatic_complexity": 8
          }
        ],
        "summary": {
          "total_functions": 3,
          "total_lines_of_code": 147
        }
      }`; 
    core.info("Insights fetched successfully");
    core.endGroup();

    const jInsights = JSON.parse(insights);
    core.startGroup('Fetched Function Insights');
    core.info(JSON.stringify(jInsights, null, 2));
    core.endGroup();
  } catch (err) {
    core.setFailed(`Insights fetch failed: ${err.message}`);
  }
}

run();
