const core = require("@actions/core");
const exec = require("@actions/exec");

async function run() {
  try {
    const project = core.getInput("project", { required: true });
    const version = core.getInput("version", { required: true });

    core.startGroup(`Fetch function insights ${project}(${version})`);
    // let insights = "";
    // const options = {};
    // options.listeners = {
    //   stdout: (data) => {
    //     insights += data.toString();
    //   },
    // };
    // await exec.exec("loci_api", ["func-insights", project, version], options);
    const insights = {
        project: 'Example',
        binaries: ['bin1', 'bin2'],
        mode: 'upload'
    };      
    core.info("Insights fetched successfully");
    const jInsights = JSON.parse(insights);
    core.startGroup('Fetched Function Insights');
    core.info(JSON.stringify(jInsights, null, 2));
    core.endGroup();

    core.endGroup();
  } catch (err) {
    core.setFailed(`Insights fetch failed: ${err.message}`);
  }
}

run();
