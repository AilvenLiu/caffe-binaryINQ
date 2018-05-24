#!/usr/bin/env sh
set -e

./build/tools/caffe train \
    --solver=examples/mnist/lenet_solver.prototxt  $@

#    --snapshot=examples/mnist/lenet_iter_10000.solverstate \
