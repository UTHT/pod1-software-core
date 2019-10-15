# University of Toronto Hyperloop Team Software Core #

## Directory Structure ##

## Overview ##

### The Three Teams ###
***Control Systems***
- Control systems is responsible for the high-level autonomy of the pod
  - Informed decision making from sensors and state estimators
  - Fined-grained control over active components such as the drive and braking systems

***Communications System***
- The communications system is responsible for the internal and external communications on the pod
  - Relaying control signals
  - Relaying data from sensors
- Communications also is responsible for health monitoring (sensor value ranges & data transmission rates) as well as establishing reliable connections to our control panel and to SpaceX

***Infrastructures***
- Infrastructures develops the real-time control panel as well as pod simulator
- The simulator allows us to run our pod through virtual scenarios and evaluate our pod by analyzing performance and identifying potential issues, for example
  - The simulator is also able to accept real-time manual input to allow testing from SpaceX or any other member who wishes to see the behavious of our pod given certain inputs say
- Infrastructures also plays a role in QA

## Git & Development Workflow ##

## Before you start... ##
- Files more than a few MB in size should not pushed to the repo unless there is a good reason
- **Always** check what files you're about to commit before doing so. `git status`
- No binaries or automatically generated files should ever be committed. (Unless there is a very very very good reason)

## GIT Workflow ##
USE THE CLI!!

The GIT workflow used here is not novel, it pulls a lot from ideas found here...
[Here](https://blog.logrocket.com/the-git-workflow-you-need-how-to-deal-with-multiple-teams-in-a-single-repository-faf5bb17a6e4/)
, [and here](https://nvie.com/posts/a-successful-git-branching-model/)

To start off, here is what the branching schema looks like. (This would represent, at a high level, a start/end to a sprint)
![Branching Schema](README-resources/branching_schema.png)

The basic idea...
- A dotted line represents temporary branches, solid lines are "permanent"
- Each team has a `dev`, `stable`, and multiple `feature` branches
- Branches...
  - Master
    - At any given moment, the most recent `tag` represents pod-ready software
  - Hotfix
    - Resolve issues unforeseen on the stable `master` branch
- During the start of every sprint, all teams pull from their latest stable tag
  - Any branch created within this sprint must pull from this stable tag
  - All work (features) during the sprint gets merged to the \*-dev branch
  - Upon completion of the sprint, all new features are tested and confirmed as stable and merged to \*-stable
  - Subsequently, each team's stables are merged to `master-dev` for further QA and final merging to `master`
- Reference the links from above for more details...

### Commit Message Formats ###
[Reference](https://chris.beams.io/posts/git-commit/)
The seven rules to follow...
1. Separate subject from body with a blank line
2. Limit the subject line to 50 characters
3. Capitalize the subject line
4. Do not end the subject line with a period
5. Use the imperative mood in the subject line
6. Wrap the body at 72 characters
7. Use the body to explain what and why vs. how

For details on each step, follow the link referenced above. I won't repeat.

### Commands to use when working ###


## Installation guide ##

The first thing is to init and update all submodules. Running `git submodule update --init --recursive` will accomplish this.

To ensure LCM is setup properly, I suggest reading our [lcm-practice repo](https://github.com/utht/lcm-practice) and the [official lcm build instructions](https://lcm-proj.github.io/build_instructions.html) for more information.

### Dependencies ###
- LCM (Lightweight Communications Marshalling)
  - To install LCM, follow the instructions here... [instructions to build LCM](https://lcm-proj.github.io/build_instructions.html)

## Notes on Using LCM ##
Firstly, this description is redundant information pulled from the [official documentation](https://lcm-proj.github.io/). But, frequent occurences to note.

To generate the language-specific bindings...
| Language | Command |
| --- | --- |
| C	| lcm-gen -c example_t.lcm |
| C++	| lcm-gen -x example_t.lcm |
| Python	| lcm-gen -p example_t.lcm |


