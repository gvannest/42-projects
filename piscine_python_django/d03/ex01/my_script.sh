#!/usr/bin/env bash

pip3 --version
pip3 install -t local_lib --upgrade --force-reinstall --log file.log path.py
# pip install -t local_lib --upgrade --force-reinstall --log file.log git+https://github.com/jaraco/path.py.git
if [ -d local_lib ] && [ -e 'local_lib/path.py' ]
then
    python3 my_program.py
fi