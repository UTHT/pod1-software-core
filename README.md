# University of Toronto Software Core #

## Overview ##

## Git & Development Workflow ##

## Before you start... ##
- Files more than a few MB in size should not pushed to the repo unless there is a good reason
- **Always** check what files you're about to commit before doing so. `git status`
- No binaries or automatically generated files should ever be committed. (Unless there is a very very very good reason)

## GIT Workflow ##
The GIT workflow used here is not novel, it pulls a lot from ideas found here...
[Here](https://blog.logrocket.com/the-git-workflow-you-need-how-to-deal-with-multiple-teams-in-a-single-repository-faf5bb17a6e4/)
[And here](https://nvie.com/posts/a-successful-git-branching-model/)

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

### Commands to use when working ###

## Installation guide ##

### Dependencies ###
- LCM (Lightweight Communications Marshalling)
  - To install LCM, follow the instructions here... [instructions to build LCM](https://lcm-proj.github.io/build_instructions.html)
