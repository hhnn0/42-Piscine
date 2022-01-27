#!/bin/bash

git log --pretty=format:"%H
" -5|grep -v '^$'
