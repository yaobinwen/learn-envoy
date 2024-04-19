# Learn Envoy

## Overview

This repository contains the versions of [Envoy](https://github.com/envoyproxy/envoy) source files that I'm interested in and the notes I made for learning purpose. Therefore, the code in this repository belongs to the original authors of Envoy and should be used under the same license. See their [license](https://github.com/envoyproxy/envoy/blob/main/LICENSE).

Each version is in its own sub-folder. My notes are all marked with `NOTE(ywen)`. The log messages I added are prefixed with `[ywen]`.

## How to build

The official document for building the code is [this](https://www.envoyproxy.io/docs/envoy/latest/start/building) which mentions two ways of building the code:

- To build in a Docker container, see [ci/README.md](https://github.com/envoyproxy/envoy/blob/main/ci/README.md).
  - Note that building in Docker requires the source code be a git repository (i.e., having the `.git` folder), otherwise it would report the error `fatal: not a git repository (or any parent up to mount point /)`. Unfortunately, the way that `learn-envoy` is set up cannot satisfy this requirement, so the build instructions here don't really apply to this repository. To build Envoy's code, check out the original source code [here](https://github.com/envoyproxy/envoy).
- To build without using Docker, see [bazel/README.md](https://github.com/envoyproxy/envoy/blob/main/bazel/README.md).

But here I will use Docker to build the code. As [ci/README.md] (see the section "On Linux") says, the general form of the building command is:

```bash
./ci/run_envoy_docker.sh './ci/do_ci.sh <TARGET>'
```

where `TARGET` is the long list in the same section. Usually, we can use the target `bazel.dev`:

```bash
./ci/run_envoy_docker.sh './ci/do_ci.sh bazel.dev'
```
