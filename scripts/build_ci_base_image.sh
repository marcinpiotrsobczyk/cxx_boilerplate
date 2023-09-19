#! /bin/bash
set -xeuo pipefail


COMMIT=
if ! git --version
then
  COMMIT="$CI_COMMIT_SHA"
else
  COMMIT=$(git rev-parse HEAD)
fi


docker build --progress=plain --target=cxx_base_image \
  -t "cxx_base_image:$COMMIT" -f Dockerfile .

docker tag "cxx_base_image:$COMMIT" cxx_base_image
