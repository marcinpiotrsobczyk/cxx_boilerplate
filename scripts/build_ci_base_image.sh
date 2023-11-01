#! /bin/bash

set -xeuo pipefail


COMMIT=${1:-"Missing commit sha"}

docker build --progress=plain --target=cxx_boilerplate_image \
  -t "boilerplate_image:$COMMIT" -f Dockerfile .

docker tag "boilerplate_image:$COMMIT" cxx_boilerplate_image
