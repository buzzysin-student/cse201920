#!/usr/bin/env bash

for type in basic noise adv; do
  for n in 1 2 3 4 5; do
    if [ $type == "basic" ] && [[ $n -gt 3 ]]; then
      break
    fi
    echo "Training =====> ${type}_${n}.csv"

    python lsr.py datafiles/train_data/${type}_${n}.csv
  done
done
