#!/usr/bin/env bash

javac $(find . -name Exercise*.java) -d bin
java -cp bin $@