#!/bin/bash
docker build -t advent .
docker run --rm -it -v $(pwd):/code advent /bin/bash

