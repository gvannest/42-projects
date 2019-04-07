#!/usr/bin/env bash

python3 -m venv django_env
source django_env/bin/activate
pip install --upgrade pip
pip install -r requirements.txt
